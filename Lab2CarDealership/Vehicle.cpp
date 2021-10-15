#include "Vehicle.h"

Vehicle::Vehicle() {
	make = "COP3503";
	model = "Rust Bucket";
	year = 1900;
	price = 0.0f;
	miles = 0;
}

Vehicle::Vehicle(string ma, string mo, unsigned int y, float p, unsigned int m) {
	make = ma;
	model = mo;
	year = y;
	price = p;
	miles = m;
}

void Vehicle::Display() {
	cout << to_string(year) << " " << make << " " << model << " $" << price << " " << to_string(miles) << endl;
}

string Vehicle::GetYearMakeModel() {
	return to_string(year) + " " + make + " " + model;
}

float Vehicle::GetPrice() {
	return price;
}