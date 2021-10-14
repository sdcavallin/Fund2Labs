#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{

    // Lab 1 Data Visualization

    string title, c1, c2;
    cout << "Enter a title for the data:" << endl;
    getline(cin, title);
    cout << "You entered: " << title << endl;

    cout << "Enter the column 1 header:" << endl;
    getline(cin, c1);
    cout << "You entered: " << c1 << endl;
    cout << "Enter the column 2 header:" << endl;
    getline(cin, c2);
    cout << "You entered: " << c2 << endl;

    string data;
    vector<string> strs;
    vector<int> nums;
    while (true) {
        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, data);
        try {
            if (stoi(data) == -1) break;
        }
        catch (invalid_argument& e) {}

        int commas = 0;
        int ind = 0;
        for (long unsigned int i = 0; i < data.length(); i++) {
            if (data[i] == ',') {
                commas++;
                ind = i;
            }
        }

        if (commas < 1) {
            cout << "Error: No comma in string.\n";
            continue;
        }

        if (commas > 1) {
            cout << "Error: Too many commas in input.\n";
            continue;
        }

        string x = "";
        int y = 999;

        try {
            x = data.substr(0, ind);
            y = stoi(data.substr(ind + 1));
        }
        catch (invalid_argument& e) {
            cout << "Error: Comma not followed by an integer.\n";
            continue;
        }

        cout << "Data string: " << x << endl;
        cout << "Data integer: " << y << endl;

        strs.push_back(x);
        nums.push_back(y);
    }

    // Table
    cout << endl;
    cout << setw(33) << right << title << endl;
    cout << setw(20) << left << c1 << "|";
    cout << setw(23) << right << c2 << endl;
    cout << "--------------------------------------------" << endl;;

    for (long unsigned int i = 0; i < strs.size(); i++) {
        cout << setw(20) << left << strs[i] << "|";
        cout << setw(23) << right << nums[i] <<  endl;
    }

    cout << endl;

    // Chart
    for (long unsigned int i = 0; i < strs.size(); i++) {
        cout << setfill(' ') << setw(20) << right << strs[i] << " ";
        cout << setfill('*') << setw(nums[i]) << "" << endl;
    }

    return 0;
}
