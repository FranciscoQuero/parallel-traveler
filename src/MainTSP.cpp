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
    int iterations = 10000;
    string filename = "file.txt";

    if (argc < 3) {
        cout << "You should provide the number of iterations and the filename. Using 10,000 iterations and file.txt\n";
    } else {
        iterations = atoi(argv[2]);
        filename = argv[1];
    }

    Problem problem = readCitiesFromFile(filename);

    //cout.precision(8);
    startTime = omp_get_wtime();
    Route route = MontecarloHeuristic::solveMontecarlo(problem, iterations);
    endTime = omp_get_wtime();
    duration = endTime - startTime;

    cout << "Time spent: " << duration << " s." << endl;
    cout << "Best cost: " << route.getCost() << endl;
    if (route.getNumberOfCities() < 150)
        cout << "Best route found: " << route.toString() << "\n\n";

    return 0;
}
