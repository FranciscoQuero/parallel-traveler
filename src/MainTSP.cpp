#include <string>
#include <fstream>
#include <iostream>
#include "Route.h"
#include "Problem.h"
#include "MontecarloHeuristic.h"
#include "City.h"
#include "MainTSP.h"
#include <stdlib.h>
#include <omp.h>
#include "mpi.h"

using namespace std;

Problem readCitiesFromFile(string filename) {
    int citiesTotal = 0;
    string name, dimensionInput, auxDimensionInput;
    string DIMENSION = "DIMENSION:";
    double x, y;
    vector<City> cities;
    ifstream citiesFile;

    citiesFile.open(filename.c_str());

    if ( citiesFile.is_open() ) {
        citiesFile >> dimensionInput;
        if (DIMENSION.compare(dimensionInput) == 0)
            citiesFile >> citiesTotal;

        for (int i = 0; i < citiesTotal; i++) {
            citiesFile >> name;
            citiesFile >> x;
            citiesFile >> y;
            cities.push_back(City(x, y, name));
        }

        citiesFile.close();
    }
    Problem problem(cities);
    return problem;
}

int main (int argc, char **argv) {
    double startTime, endTime, duration;
    int iterations = 10000, iproc, nproc;
    string filename = "file.txt";


    if (argc < 3) {
        cout << "You should provide the number of iterations and the filename. Using 10,000 iterations and file.txt\n";
    } else {
        iterations = atoi(argv[2]);
        filename = argv[1];
    }

    Problem problem = readCitiesFromFile(filename);

    startTime = omp_get_wtime();
    double cost = MontecarloHeuristic::solveMontecarlo(problem, iterations, argc, argv);
    endTime = omp_get_wtime();
    MPI_Comm_rank(MPI_COMM_WORLD, &iproc);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);
    if (iproc == 0) {
    duration = endTime - startTime;
    cout << "Time spent: " << duration << " s." << endl;
    cout << "Best cost: " << cost << endl;
    }
    MPI_Finalize();

    return 0;
}
