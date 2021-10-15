#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "extrafile.h"

Set::Set(int opt) {	
	count = 0;
	if (opt == 4) {
		load(1);
		load(2);
		load(3);
	}
	else {
		load(opt);
	}
}

void Set::load(int opt) {
	ifstream file;
	string fname = "lego" + to_string(opt) + ".csv";

	file.open(fname);

	if (file.is_open()) {
		string in;
		getline(file, in);

		while (getline(file, in, ',')) {
			number.push_back(stoi(in));

			getline(file, in, ',');
			theme.push_back(in);

			getline(file, in, ',');
			name.push_back(in);

			getline(file, in, ',');
			minifigs.push_back(stoi(in));

			getline(file, in, ',');
			pieces.push_back(stoi(in));

			getline(file, in);
			price.push_back(stod(in));

			count++;
		}

	}
	else {
		throw logic_error("File not found");
	}
}

void Set::print(int set) {
	cout << "Name: " << name[set] << endl;
	cout << "Number: " << number[set] << endl;
	cout << "Theme: " << theme[set] << endl;
	cout << "Price: $" << price[set] << endl; // formatting problems?
	cout << "Minifigures: " << minifigs[set] << endl;
	cout << "Piece count: " << pieces[set] << endl;
}

void Set::printLess(int set) {
	cout << number[set] << " " << name[set] << " $" << price[set] << endl;
}

void Set::mostExpensive() {
	double max = 0.0;
	int ind = 0;
	for (int i = 0; i < count; i++) {
		if (price[i] > max) {
			max = price[i];
			ind = i;
		}
	}
	cout << "The most expensive set is:" << endl;
	print(ind);
}

void Set::mostPieces() {
	int max = 0;
	int ind = 0;
	for (int i = 0; i < count; i++) {
		if (pieces[i] > max) {
			max = pieces[i];
			ind = i;
		}
	}
	cout << "The set with the highest parts count:" << endl;
	print(ind);
}

void Set::searchNames(string input) {
	vector<int> results;
	for (int i = 0; i < count; i++) {
		if (name[i].find(input) != string::npos) {
			results.push_back(i);
		}
	}
	if (results.size() == 0) {
		cout << "No sets found matching that search term" << endl;
	}
	else {
		cout << "Sets matching \"" << input << "\":" << endl;
		for (int i : results) {
			printLess(i);
		}
	}
}

void Set::searchThemes(string input) {
	vector<int> results;
	for (int i = 0; i < count; i++) {
		if (theme[i].find(input) != string::npos) {
			results.push_back(i);
		}
	}
	if (results.size() == 0) {
		cout << "No sets found matching that search term" << endl;
	}
	else {
		cout << "Sets matching \"" << input << "\":" << endl;
		for (int i : results) {
			printLess(i);
		}
	}
}

void Set::partsInfo() { 
	int total = 0, average = 0;

	for (int i : pieces) {
		total += i;
	}

	average = total / count;

	cout << "Average part count for " << count << " sets: " << average << endl;
}

void Set::priceInfo() {
	double total = 0;
	double average = 0;

	for (double i : price) {
		total += i;
	}

	average = total / count;

	cout << "Average price for " << count << " sets: $" << average << endl;

	double max = 0.0;
	int maxInd = 0;
	for (int i = 0; i < count; i++) {
		if (price[i] > max) {
			max = price[i];
			maxInd = i;
		}
	}

	double min = max;
	int minInd = 0;
	for (int i = 0; i < count; i++) {
		if (price[i] < min) {
			min = price[i];
			minInd = i;
		}
	}

	cout << "Least expensive set:" << endl;
	print(minInd);

	cout << "Most expensive set:" << endl;
	print(maxInd);

}

void Set::minifigsInfo() {
	int total = 0, average = 0;

	for (int i : minifigs) {
		total += i;
	}

	average = total / count;

	cout << "Average number of minifigures: " << average << endl;
	cout << "Set with the most minifigures:" << endl;
	
	int max = 0;
	int ind = 0;
	for (int i = 0; i < count; i++) {
		if (minifigs[i] > max) {
			max = minifigs[i];
			ind = i;
		}
	}

	print(ind);

}


void Set::oneOfEverything() {
	double totalCost = 0;
	int totalPieces = 0, totalMini = 0;

	for (int i = 0; i < count; i++) {
		totalCost += price[i];
		totalPieces += pieces[i];
		totalMini += minifigs[i];
	}

	cout << "If you bought one of everything..." << endl;
	cout << "It would cost: $" << totalCost << endl;
	cout << "You would have " << totalPieces << " pieces in your collection" << endl;
	cout << "You would have an army of " << totalMini << " minifigures!" << endl;
}