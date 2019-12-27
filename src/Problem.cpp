#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <City.h>
#include <Route.h>

#define MAXIMUM_LENGTH 10000

using namespace std;

class Problem
{
    public:
        Problem();
        Problem(vector<City> _cities);
        Problem readCitiesFromFile(ifstream citiesFile);
        int getNumberOfCities();
        City getCity(int position);
        double getDistance(int position1, int position2);
        double cost(Route route);

    private:
        vector<City> cities;
        double distanceMatrix[][MAXIMUM_LENGTH];
};

Problem::Problem() {};

Problem::Problem(vector<City> _cities) {
    vector<City> cities = _cities;
    int length = cities.size();
    City currentCity(0, 0, "dummy"), auxCity(0, 0, "dummy");

    //distanceMatrix = new double [length][length];

    for (int i = 0; i < length; i++){
        currentCity = cities.at(i);
        for (int j = 0; j < length; j++) {
            auxCity = cities.at(j);
            distanceMatrix[i][j] = currentCity.calculateEuclideanDistance(auxCity);
        }
    }
};

Problem Problem::readCitiesFromFile(ifstream citiesFile) {
    int citiesTotal = 0;
    string name, dimensionInput, auxDimensionInput;
    string DIMENSION = "DIMENSION:";
    double x, y;
    vector<City> cities;

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

    return Problem(cities);
}

int Problem::getNumberOfCities(){
    return cities.size();
}

City Problem::getCity(int position) {
    return cities.at(position);
}

double Problem::getDistance(int position1, int position2) {
    return distanceMatrix[position1][position2];
}

double Problem::cost(Route route){
    double distance = 0;
    int total = route.getNumberOfCities();
    City auxCity = City(0, 0, "dummy");

    for (int i = 0; i < total-1; i++) {
        auxCity = cities.at(i+1);
        distance += cities.at(i).calculateEuclideanDistance(auxCity);
    }

    return distance;
}
