#include <vector>
#include "City.h"
#include "Route.h"

using namespace std;

class Problem
{
    public:
        Problem(vector<City> _cities);
        int getNumberOfCities();
        City getCity(int position);
        double getDistance(int positionCity1, int positionCity2);
        double cost(Route route);

    private:
        vector<City> cities;
        vector<vector<double > > distanceMatrix;
};

Problem::Problem(vector<City> _cities) {
    double currentDistance;
    vector<City> cities(_cities);
    const int length = cities.size();
    City currentCity(0, 0, ""), auxCity(0, 0, "");

    this->cities = _cities;

    for (int i = 0; i < length; i++){
        currentCity = cities.at(i);
        vector<double> row; // creates empty row
        for (int j = 0; j < length; j++) {
            auxCity = cities.at(j);
            currentDistance = currentCity.calculateEuclideanDistance(auxCity);
            row.push_back(currentDistance);
        }
        distanceMatrix.push_back(row);
    }
};

int Problem::getNumberOfCities(){
    return cities.size();
}

City Problem::getCity(int position) {
    return cities.at(position);
}

double Problem::getDistance(int positionCity1, int positionCity2) {
    return distanceMatrix[positionCity1][positionCity2];
}

double Problem::cost(Route route){
    double distance = 0;
    int total = route.getNumberOfCities();

    // We do not parallelize this loop because the overhead is always worse than the parallelization time saving
    for (int i = 0; i < total-1; i++) {
        City currentCity = cities.at(route.getCities(i));
        City auxCity = cities.at(route.getCities(i+1));
        distance += currentCity.calculateEuclideanDistance(auxCity);
    }

    return distance;
}
