#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

class City
{
	public:
		City(double x, double y, string name);
		double getX();
		double getY();
		string getName();
		double calculateEuclideanDistance(City city);
	private:
		double x, y;
		string name;
};

City:City(double _x, double _y, string _name) {
	x = _x;
	y = _y;
	name = _name;
}

double City::getX() {
	return x;
}

double City::getY() {
	return y;
}

string City::getName() {
	return name;
}

double City::calculateEuclideanDistance(City city) {
	_x = city.getX();
	_y = city.getY();

	return sqrt(pow(x - _x, 2) + pow(y - _y, 2));
}