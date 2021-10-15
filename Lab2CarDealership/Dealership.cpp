#include "Dealership.h"

Dealership::Dealership(string n, unsigned int c) {
	name = n;
	cap = c;
	num = 0;
}

void Dealership::AddShowroom(Showroom s) {
	if (num == cap) {
		cout << "Dealership is full, can't add another showroom!" << endl;
	}
	else {
		list.push_back(s);
		num++;
	}
}

float Dealership::GetAveragePrice() {
	float prices = 0;
	unsigned int cars = 0;

	for (unsigned int i = 0; i < num; i++) {
		prices += list[i].GetInventoryValue();
		cars += list[i].num;
	}

	if (cars == 0) return 0.0f;
	return (prices / cars);
}

void Dealership::ShowInventory() {
	if (num == 0) {
		cout << name << " is empty!\n";
	}
	else {
		for (unsigned int i = 0; i < num; i++) {
			list[i].ShowInventory();
			cout << endl;
		}
	}
	cout << "Average car price: $" << GetAveragePrice();
	//printf("Average car price: $%.2f", GetAveragePrice());
}
