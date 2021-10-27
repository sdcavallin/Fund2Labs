#include <iostream>
#include <fstream>
#include "extrafile.h"
using namespace std;

int main()
{
	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;

	/* Load files here */
	Set ships(option);

	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;

	cin >> option;

	/* Work your magic here */
	switch (option) {
	case 1 : 
		ships.printAllShips();
		break;
	case 2 :
		ships.biggestGun();
		break;
	case 3 :
		ships.mostPowerfulShip();
		break;
	case 4 :
		ships.weakestShip();
		break;
	case 5 :
		ships.printUnarmed();
		break;
	}

	return 0;
}