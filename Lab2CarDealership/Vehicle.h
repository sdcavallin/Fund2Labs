#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Vehicle {
	string make, model;
	unsigned int year, miles;
	float price;

public:
	Vehicle();
	Vehicle(string ma, string mo, unsigned int y, float p, unsigned int m);

	void Display();
	string GetYearMakeModel();
	float GetPrice();
};