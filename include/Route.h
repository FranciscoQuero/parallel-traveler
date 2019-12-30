#include <string>

#ifndef ROUTE_H_INCLUDED
#define ROUTE_H_INCLUDED

class Route
{
	public:
		Route(int length);
		void setCities(int position, int city);
		int getCities(int position);
		void addCity(int position);
		int getCities();
		int getNumberOfCities();
		void insertCity(int position, int value);
		std::string toString();
		void setCost(double newCost);
		double getCost();

	private:
		int *cities;
		int numberOfCities;
		double cost;
};

#endif // ROUTE_H_INCLUDED
