#include <string>
#include <fstream>
#include <iostream>
#include "Route.h"
#include "Problem.h"
#include "MontecarloHeuristic.h"
#include "City.h"
#include "MainTSP.h"
#include <time.h>

using namespace std;

Problem readCitiesFromFile() {
    int citiesTotal = 0;
    string name, dimensionInput, auxDimensionInput;
    string DIMENSION = "DIMENSION:";
    double x, y;
    vector<City> cities;
    ifstream citiesFile;

    citiesFile.open("file.txt");

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

int main () {
    struct timespec startTime, endTime;
    long double duration;
    int iterations = 1000;
    Problem problem = readCitiesFromFile();
    clockid_t clk_id;

    cout.precision(8);
    clock_gettime(clk_id, &startTime);
    Route route = MontecarloHeuristic::solveMontecarlo(problem, iterations);
    clock_gettime(clk_id, &endTime);
    duration = endTime.tv_sec - startTime.tv_sec;

    cout << "Time spent: " << duration << " s." << endl;
    cout << "Best cost: " << route.getCost() << endl;
    cout << "Best route found: " << route.toString() << "\n\n";

    return 0;
}
