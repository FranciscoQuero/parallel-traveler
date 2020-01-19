#include "MontecarloHeuristic.h"
#include "City.h"
#include "Route.h"
#include "Problem.h"
#include <algorithm>
#include <ctime>
#include <time.h>
#include <iostream>
#include <random>
#include <chrono>
#include "mpi.h"

using namespace std;

double MontecarloHeuristic::solveMontecarlo(Problem problem, int iterations, int argc, char **argv) {
    vector<int> routeInt;
    int totalCities = problem.getNumberOfCities();
    double definitiveCost;
    vector<vector<int > > routeOrderMatrix;
    Route lessCostRoute = Route(0);
    //srand (time(NULL));

    int iproc, nproc;

    routeInt.resize(totalCities);
    routeOrderMatrix.resize(iterations);
    for (int i = 0; i < totalCities; i++)
        routeInt[i] = i;

    //MPI_Scatter(routeOrderMatrix.data(), 4, MPI_FLOAT, routeOrderMatrix.data(), 4, MPI_FLOAT, 0, MPI_COMM_WORLD);
    //for (int i = iproc; i < iterations; i+=nproc){
    if (MPI_Init(&argc, &argv) != MPI_SUCCESS) exit(1);
    MPI_Comm_rank(MPI_COMM_WORLD, &iproc);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
    srand(time(NULL) + iproc);
    double totalCost = 0;

    for (int i = iproc; i < iterations; i+=nproc) {
        for (int j = 0; j < totalCities; j++) {
            int randomInt = j + rand() % (totalCities - j);
            swap(routeInt[j], routeInt[randomInt]);
        }
        routeOrderMatrix[i] = routeInt;
    }
    //MPI_Bcast(&routeOrderMatrix, iterations*totalCities, MPI_INT, 0, MPI_COMM_WORLD);


    /*if (iproc == 0) {
        MPI_Bcast(&routeOrderMatrix, iterations, MPI_INT, iproc, MPI_COMM_WORLD);
    }

    MPI_Barrier(MPI_COMM_WORLD);*/

    for (int i = iproc; i < iterations; i+=nproc){
        vector <int> currentRouteOrder = routeOrderMatrix[i];

        Route route = Route(totalCities);

        for (int j = 0; j < totalCities; j++)
            route.addCity(currentRouteOrder[j]);

        double currentCost = problem.cost(route);
        //cout << currentCost << " rank: " << iproc << endl;

        if (i == iproc || totalCost > currentCost) {
            //cout << " -> Found a cost of " << currentCost << " iteration: " << i << " rank: " << iproc << endl;
            totalCost = currentCost;
            lessCostRoute = route;
        }
    }
    cout << "Best: " << totalCost << " rank: " << iproc << endl;

    MPI_Reduce(&totalCost, &definitiveCost, 1, MPI_DOUBLE, MPI_MIN, 0, MPI_COMM_WORLD);
    //MPI_Finalize();
    //cout << "Best: " << definitiveCost << endl;
    //lessCostRoute.setCost(totalCost);
    return definitiveCost;
}
