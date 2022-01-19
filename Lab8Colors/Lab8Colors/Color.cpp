#include "Color.h"

Color::Color(string Name, int Value) {
	name = Name;
	value = Value;
	hex = "0x000000";
	r = 0, g = 0, b = 0;
	SetValue(value);
}

// ASCII A = 65
void Color::SetValue(int Value) {
	value = Value;
	r = (value >> 16) & 255;
	g = (value >> 8) & 255;
	b = (value >> 0) & 255;

	string toHex = "0123456789ABCDEF";

	hex[2] = toHex[r / 16];
	hex[3] = toHex[r % 16];
	hex[4] = toHex[g / 16];
	hex[5] = toHex[g % 16];
	hex[6] = toHex[b / 16];
	hex[7] = toHex[b % 16];
}

void Color::SetName(const char* Name) {
	name = Name;
}

unsigned char Color::GetR() const {
	return r;
}

unsigned char Color::GetG() const {
	return g;
}

unsigned char Color::GetB() const {
	return b;
}

string Color::GetHexValue() const {
	return hex;
}

string Color::GetName() const {
	return name;
}