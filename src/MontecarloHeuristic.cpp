#include "MontecarloHeuristic.h"
#include <City.h>
#include <Route.h>
#include <Problem.h>
#include <algorithm>

using namespace std;

Route MontecarloHeuristic::solveMontecarlo(Problem problem) {
    const int ITERATIONS = 10000;
    vector<int> routeInt;
    int totalCities = problem.getNumberOfCities();
    bool isFirstIteration = true;
    double totalCost = 0, currentCost;
    Route route = 0, lessCostRoute = 0;

    for (int i = 0; i < totalCities; i++)
        routeInt.push_back(i);

    for (int i = 0; i < ITERATIONS; i++){
        random_shuffle (routeInt.begin(), routeInt.end());
        route = Route(totalCities);

        for (int j = 0; j < totalCities; j++)
            route.addCity(routeInt.at(j));

        currentCost = problem.cost(route);

        if (isFirstIteration) {
            totalCost = currentCost;
            isFirstIteration = false;
            lessCostRoute = route;
        } else if (currentCost < totalCost) {
            totalCost = currentCost;
            lessCostRoute = route;
        }
    }

    return lessCostRoute;
}
