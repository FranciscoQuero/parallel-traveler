#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <City.h>
#include <Route.h>

using namespace std;

#ifndef PROBLEM_H
#define PROBLEM_H
#define MAXIMUM_LENGTH 10000

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
        double distanceMatrix[][MAXIMUM_LENGTH];
};

#endif // PROBLEM_H
