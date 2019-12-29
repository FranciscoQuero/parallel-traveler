#include "MainTSP.h"
#include <string>
#include "City.h"
#include <Route.h>
#include <Problem.h>
#include <fstream>
#include <MontecarloHeuristic.h>

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
        if (DIMENSION.compare(dimensionInput) == 0) {
            citiesFile >> citiesTotal;
        } else {
            //citiesTotal = dimensionInput;
        }

        for (int i = 0; i < citiesTotal; i++) {
            citiesFile >> name;
            citiesFile >> x;
            citiesFile >> y;
            cities.push_back(City(x, y, name));
        }

        citiesFile.close();
    }
    Problem problemica(cities);
    cout << "lee files - " << problemica.getNumberOfCities();
    return Problem(cities);
}

int main () {
    //Route route = 0;
    int start = 0;
    long timeStart, timeEnd;

    Problem problem = readCitiesFromFile();
    cout << "Entrando en el montecarlo\n - " << problem.getNumberOfCities();
    // TODO: time
    Route route = MontecarloHeuristic::solveMontecarlo(problem);

    cout << "Total Cities: " << route.getNumberOfCities();

    return 0;
}
