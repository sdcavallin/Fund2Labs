#include <string>
#include <map>
#include <iostream>
#pragma once

using namespace std;

class Color {
public:
	string name, hex;
	int value;
	unsigned char r, g, b;
	void SetValue(int Value);
	void SetName(const char* Name);

	unsigned char GetR() const;
	unsigned char GetG() const;
	unsigned char GetB() const;

	string GetHexValue() const;
	string GetName() const;

	Color(string Name, int Value);
};

