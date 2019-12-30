#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <City.h>
#include <Route.h>

#define MAXIMUM_LENGTH 101

using namespace std;

class Problem
{
    public:
        Problem(vector<City> _cities);
        static Problem readCitiesFromFile(ifstream citiesFile);
        int getNumberOfCities();
        City getCity(int position);
        double getDistance(int position1, int position2);
        double cost(Route route);

    private:
        vector<City> cities;
        //double distanceMatrix[52][52];
        vector<vector<double > > distanceMatrix;
};

Problem::Problem(vector<City> _cities) {
    double currentDistance;
    vector<City> cities(_cities);
    const int length = cities.size();
    cout << "LENGTH PROBLEMA " << length;
    City currentCity(0, 0, "dummy"), auxCity(0, 0, "dummy");

    this->cities = _cities;

    for (int i = 0; i < length; i++){
        currentCity = cities.at(i);
        vector<double> row;//creates empty row
        for (int j = 0; j < length; j++) {
            auxCity = cities.at(j);
            //cout << "\n-- I: " << i << " - J: " << j << " \n";
            //distanceMatrix[i][j] = currentCity.calculateEuclideanDistance(auxCity); //rompe aqui cuando i=6, j=22
            //a[i][j] = currentCity.calculateEuclideanDistance(auxCity);
            currentDistance = currentCity.calculateEuclideanDistance(auxCity);
            row.push_back(currentDistance);
        }
        distanceMatrix.push_back(row);
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
    City currentCity(0,0,"dummy"), auxCity(0, 0, "dummy");

    for (int i = 0; i < total-1; i++) {
        currentCity = cities.at(route.getCities(i));
        auxCity = cities.at(route.getCities(i+1));
        distance += currentCity.calculateEuclideanDistance(auxCity);
    }

    return distance;
}
