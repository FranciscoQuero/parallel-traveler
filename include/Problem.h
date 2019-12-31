#include <vector>
#include <City.h>
#include <Route.h>

using namespace std;

#ifndef PROBLEM_H
#define PROBLEM_H

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

#endif // PROBLEM_H
