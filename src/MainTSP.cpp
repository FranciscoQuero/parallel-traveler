#include <string>
#include <fstream>
#include <iostream>
#include "Route.h"
#include "Problem.h"
#include "MontecarloHeuristic.h"
#include "City.h"
#include "MainTSP.h"
#include <time.h>
#include <stdlib.h>

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
    struct timespec startTime, endTime;
    double duration;
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
    clock_gettime(CLOCK_REALTIME, &startTime);
    Route route = MontecarloHeuristic::solveMontecarlo(problem, iterations);
    clock_gettime(CLOCK_REALTIME, &endTime);
    duration = (double)(endTime.tv_sec-startTime.tv_sec) + (double)((endTime.tv_nsec-startTime.tv_nsec)/(1.e+9));

    cout << "Time spent: " << duration << " s." << endl;
    cout << "Best cost: " << route.getCost() << endl;
    cout << "Best route found: " << route.toString() << "\n\n";

    return 0;
}
