#include <string>

#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED

class City
{
	public:
	    City();
		City(double x, double y, std::string name);
		double getX();
		double getY();
		std::string getName();
		double calculateEuclideanDistance(City city);
	private:
		double x, y;
		std::string name;
};

#endif // CITY_H_INCLUDED
