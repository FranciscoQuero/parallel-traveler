#include <vector>

#ifndef PROBLEM_H
#define PROBLEM_H
#define MAXIMUM_LENGTH 10000

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

#endif // PROBLEM_H
