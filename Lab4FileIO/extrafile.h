#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Set { // possible error: not loading last line of csv
	
public:
	vector<int> number, minifigs, pieces;
	vector<double> price;
	vector<string> theme, name;
	int count;

	Set(int opt);

	void load(int opt);

	void print(int set);
	void printLess(int set);

	void mostExpensive();
	void mostPieces();

	void searchNames(string input);
	void searchThemes(string input);

	void partsInfo();
	void priceInfo();
	void minifigsInfo();

	void oneOfEverything();
};