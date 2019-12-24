#include <iostream>
#include <string.h>

using namespace std;

class Route 
{
	public:
		Route(int length);
		void setCities(int position, int city);
		int getCities(int position);
		void addCity(int position);
		int[] getCities();
		int getNumberOfCities();
		void insertCity(int position, int value);
		string toString();

	private:
		int cities[];
		int numberOfCities;
};

Route::Route(int length) {
	cities = new int[length];
	numberOfCities = 0;
}

void Route::setCities(int position, int city) {
	cities[position] = city;
}

int Route::getCities(int position) {
	return cities[position % numberOfCities];
}

int Route::getNumberOfCities() {
	return numberOfCities;
}

void Route::addCity(int position) {
	cities[numberOfCities] = position;
	numberOfCities++;
}

int[] Route::getCities(){
	return cities;
}

void Route::insertCity(int position, int value) {
	int auxCity, rotationAuxCity;
	numberOfCities++;

	auxCity = cities[position];
	cities[position] = value;

	for (int i = position+1; i < numberOfCities; i++) {
		rotationAuxCity = cities[i];
		cities[i] = auxCity;
		auxCity = rotationAuxCity;
	}
}

string Route::toString() {
	string textRoute = '{';

	for (int i = 0; i < numberOfCities; i++) {
		if (i != numberOfCities-1)
			textRoute += cities[i] + ',';
		else
			textRoute += cities[i];
	}

	textRoute += '}';

	return textRoute;
}