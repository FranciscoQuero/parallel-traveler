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

	private:
		int *cities;
		int numberOfCities;
};

#endif // ROUTE_H_INCLUDED
