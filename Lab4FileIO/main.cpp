#include <iomanip>
#include <iostream>
#include "extrafile.h"
using namespace std;

int main()
{

	cout << std::fixed << setprecision(2);
	cout << "Which file(s) to open?\n";
	cout << "1. lego1.csv" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	cin >> option;

	/*======= Load data from file(s) =======*/
	Set legos(option);

	cout << "1. Most Expensive set" << endl;
	cout << "2. Largest piece count" << endl;
	cout << "3. Search for set name containing..." << endl;
	cout << "4. Search themes..." << endl;
	cout << "5. Part count information" << endl;
	cout << "6. Price information" << endl;
	cout << "7. Minifigure information" << endl;
	cout << "8. If you bought one of everything..." << endl;
	cout << "0. Exit" << endl;

	int choice;
	cin >> choice;
	cin.get();  // Clear newline character for any later input

	/*======= Print out how many sets were loaded =======*/
	cout << "Total number of sets: " << legos.count << endl;

	/*======= Based on the choice, execute the appropriate task and show the results =======*/
	string input;
	switch (choice) {
	case 1 :
		legos.mostExpensive();
		break;
	case 2:
		legos.mostPieces();
		break;
	case 3:
		getline(cin, input);
		legos.searchNames(input);
		break;
	case 4:
		getline(cin, input);
		legos.searchThemes(input);
		break;
	case 5:
		legos.partsInfo();
		break;
	case 6:
		legos.priceInfo();
		break;
	case 7 :
		legos.minifigsInfo();
		break;
	case 8 :
		legos.oneOfEverything();
		break;
	}

	return 0;
}

