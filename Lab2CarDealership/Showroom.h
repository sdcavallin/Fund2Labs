#pragma once
#include "Vehicle.h"

class Showroom {
	string name;
	vector<Vehicle> list;
	unsigned int cap;
	
public:
	unsigned int num;
	Showroom(string n = "Unnamed Showroom", unsigned int capacity = 0);

	vector<Vehicle> GetVehicleList();

	void AddVehicle(Vehicle v);
	void ShowInventory();
	float GetInventoryValue();
};