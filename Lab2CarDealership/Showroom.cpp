#include "Showroom.h"

Showroom::Showroom(string n, unsigned int c) {
	name = n;
	cap = c;
	num = 0;
}

vector<Vehicle> Showroom::GetVehicleList() {
	return list;
}

void Showroom::AddVehicle(Vehicle v) {
	if (num == cap) {
		cout << "Showroom is full! Cannot add " << v.GetYearMakeModel() << endl;
	}
	else {
		list.push_back(v);
		num++;
	}
}

void Showroom::ShowInventory() {
	if (num == 0) {
		cout << name << " is empty!\n";
	}
	else {
		cout << "Vehicles in " << name << "\n";
	}
	for (unsigned int i = 0; i < num; i++) {
		list[i].Display();
	}
}

float Showroom::GetInventoryValue() {
	float val = 0.0f;
	for (unsigned int i = 0; i < num; i++) {
		val += list[i].GetPrice();
	}
	return val;
}