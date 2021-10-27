#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Weapon {
public:
	string name;
	int firepower;
	float power;

	Weapon(string n, int f, float p);
	void print();
};

class Set {
public:
	vector<string> name, shipClass;
	vector<short> length;
	vector<int> shield, numWeapons, totalFirepower;
	vector<float> warp;
	vector<vector<Weapon>> weapons;
	int count;

	Set(int opt);

	void load(int opt);

	void print(int set);

	void printAllShips();
	void biggestGun();
	void mostPowerfulShip();
	void weakestShip();
	void printUnarmed();
};
