#include <iostream>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

mt19937 random_mt;

int Random(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);
	return dist(random_mt);
}

void RollDice(int numberOfRolls, int numberOfSides);

class State {
public:
	int perCapita, pop, median, numHouse;
	string name;
	State(string na, int pe, int po, int m, int n);
	void print();
};

int main()
{
	cout << "1. Random Numbers\n";
	cout << "2. State Info\n";

	int option;
	cin >> option;

	if (option == 1)
	{
		int randomSeed;
		cout << "Random seed value: ";
		cin >> randomSeed;
		random_mt.seed(randomSeed);

		int rolls, sides;
		cout << "Number of times to roll the die: ";
		cin >> rolls;

		cout << "Number of sides on this die: ";
		cin >> sides;

		RollDice(rolls, sides);
	}
	else if (option == 2)
	{
		// Load the states

		map<string, State> states;

		ifstream file("states.csv");
		if (file.is_open()) {
			string in;
			getline(file, in);

			while (getline(file, in, ',')) {
				string name;
				int perCapita, pop, median, numHouse;

				name = in;

				getline(file, in, ',');
				perCapita = stoi(in);

				getline(file, in, ',');
				pop = stoi(in);

				getline(file, in, ',');
				median = stoi(in);

				getline(file, in);
				numHouse = stoi(in);

				states.emplace(name, State(name, perCapita, pop, median, numHouse));
			}
		}

		// Get input for option 1 (show all states) or 2 (do a search for a particular state)
		cout << "1. Print all states\n";
		cout << "2. Search for a state\n";
		cin >> option;

		if (option == 1) {
			map<string, State>::iterator iter;

			for (iter = states.begin(); iter != states.end(); iter++) {
				iter->second.print();
			}
		}

		if (option == 2) {
			string str;
			cin.ignore();
			getline(std::cin, str);
			auto iter = states.find(str);

			if (iter == states.end()) {
				cout << "No match found for " << str << endl;
			}
			else {
				iter->second.print();
			}

		}

	}

	return 0;
}

void RollDice(int numberOfRolls, int numberOfSides) {
	map<int, int> die;

	for (int i = 1; i <= numberOfSides; i++) {
		die.emplace(i, 0);
	}

	while (numberOfRolls-- > 0) {
		die[Random(1, numberOfSides)]++;
	}

	for (int i = 1; i <= numberOfSides; i++) {
		cout << i << ": " << die[i] << endl;
	}

}

State::State(string na, int pe, int po, int m, int n) {
	name = na;
	perCapita = pe;
	pop = po;
	median = m;
	numHouse = n;
}

void State::print() {
	cout << name << endl
		<< "Population: " << pop << endl
		<< "Per Capita Income: " << perCapita << endl
		<< "Median Household Income: " << median << endl
		<< "Number of Households: " << numHouse << endl;
}