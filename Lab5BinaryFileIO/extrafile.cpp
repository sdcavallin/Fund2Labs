#include "extrafile.h"

Set::Set(int opt) {
	count = 0;

	if (opt == 3) {
		load(1);
		load(2);
	}
	else {
		load(opt);
	}
}

void Set::load(int opt) {
	string fname = "friendlyships.shp";
	if (opt == 2) fname = "enemyships.shp";

	ifstream file(fname, ios_base::binary);

	if (file.is_open()) {
		int FileCount;
		file.read((char*)&FileCount, 4);
		count += FileCount;

		for (int i = 0; i < FileCount; i++) {

			int len;

			// Read length of string
			file.read((char*)&len, 4);
			// Dynamically allocate char array
			char* buffer = new char[len];
			// Read into char array
			file.read(buffer, len);
			// Copy char array into string
			string Name = buffer;
			// Delete char array
			delete[] buffer;

			file.read((char*)&len, 4);
			buffer = new char[len];
			file.read(buffer, len);
			string ShipClass = buffer;
			delete[] buffer;

			short ShipLength;
			file.read((char*)&ShipLength, 2);

			int Shield;
			file.read((char*)&Shield, 4);

			float Warp;
			file.read((char*)&Warp, 4);

			int NumWeapons;
			file.read((char*)&NumWeapons, 4);

			name.push_back(Name);
			shipClass.push_back(ShipClass);
			length.push_back(ShipLength);
			shield.push_back(Shield);
			warp.push_back(Warp);
			numWeapons.push_back(NumWeapons);

			vector<Weapon> myWeapons;
			int TotalFirepower = 0;
			for (int j = 0; j < NumWeapons; j++) {
				file.read((char*)&len, 4);
				buffer = new char[len];
				file.read(buffer, len);
				string WeaponName = buffer;
				delete[] buffer;

				int Firepower;
				file.read((char*)&Firepower, 4);
				TotalFirepower += Firepower;

				float Power;
				file.read((char*)&Power, 4);

				myWeapons.push_back(Weapon(WeaponName, Firepower, Power));
			}

			totalFirepower.push_back(TotalFirepower);
			weapons.push_back(myWeapons);

		}

	}
	file.close();
}

void Set::print(int set) {
	cout << "Name: " << name[set] << endl;
	cout << "Class: " << shipClass[set] << endl;
	cout << "Length: " << length[set] << endl;
	cout << "Shield capacity: " << shield[set] << endl;
	cout << "Maximum Warp: " << warp[set] << endl;
	cout << "Armaments: " << endl;

	if (numWeapons[set] == 0) {
		cout << "Unarmed" << endl;
	}
	else {
		for (Weapon w : weapons[set]) {
			w.print();
		}
		cout << "Total firepower: " << totalFirepower[set] << endl;
	}

}

void Set::printAllShips() {
	for (int i = 0; i < count; i++) {
		print(i);
		cout << endl;
	}
}

void Set::biggestGun() {
	int max = 0, ind = 0;
	for (int i = 0; i < count; i++) {
		for (Weapon w : weapons[i]) {
			if (w.firepower > max) {
				max = w.firepower;
				ind = i;
			}
		}
	}
	print(ind);
}

void Set::mostPowerfulShip() {
	int max = 0, ind = 0;
	for (int i = 0; i < count; i++) {
		if (totalFirepower[i] > max) {
			max = totalFirepower[i];
			ind = i;
		}
	}
	print(ind);
}

void Set::weakestShip() {
	int min = INT_MAX, ind = 0;
	for (int i = 0; i < count; i++) {
		if (totalFirepower[i] < min && numWeapons[i] > 0) {
			min = totalFirepower[i];
			ind = i;
		}
	}
	print(ind);
}

void Set::printUnarmed() {
	for (int i = 0; i < count; i++) {
		if (numWeapons[i] == 0) {
			print(i);
			cout << endl;
		}
	}
}


Weapon::Weapon(string n, int f, float p) {
	name = n;
	firepower = f;
	power = p;
}

void Weapon::print() {
	cout << name << ", " << firepower << ", " << power << endl;
}