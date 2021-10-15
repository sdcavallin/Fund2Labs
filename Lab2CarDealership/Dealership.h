#pragma once
#include "Showroom.h"

class Dealership {
	string name;
	vector<Showroom> list;
	unsigned int cap;
	unsigned int num;

public:
	Dealership(string n = "Generic Dealership", unsigned int capacity = 0);

	void AddShowroom(Showroom s);
	float GetAveragePrice();
	void ShowInventory();
};