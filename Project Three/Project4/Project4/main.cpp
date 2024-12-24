#include "ItemTracker.h"
#include <iostream>
#include <string>

using namespace std;


void displayMenu();

// displays the program menu with options for the user
void displayMenu() {
	cout << "=== Item tracking Program ===\n" << endl;
	cout << "1. Search for an item's frequency" << endl;
	cout << "2. Print frequency of all items" << endl;
	cout << "3. Print histogram of item frequencies" << endl;
	cout << "4. Exit the program\n" << endl;
	cout << "Choose an option: ";
}

int main() {
	const string inputFile = "CS210_Project_Three_Input_File.txt";    // input file containing item data
	const string backupFile = "frequency.dat";  //  backup file for item data

	// create an ItemTracker object to manage the data
	ItemTracker tracker(inputFile, backupFile);
	int choice;


	do {
		displayMenu();   // show the main menu
		cin >> choice;

		// validate user input for menu selection
		if (cin.fail() || choice < 1 || choice > 4) {
			cin.clear();  // clear invalid input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');   // ignore remaining input
			cout << "\nInvalid  menu option... Please select a valid option.\n" << endl;
			continue;    // restart the loop for valid input
		}

		switch (choice) {
			case 1: {
				cin.ignore();							// clear newline character from the buffer
				string item;
				cout << "Enter the item to search for: ";
				getline(cin, item);					 // get the item name from the user
				tracker.searchItemFrequency(item);  //  search for the specific item
				break;
			}
			case 2: {
				tracker.printAllFrequencies();  //  search and print the frequency of items in the input file
				break;
			}
			case 3: {
				tracker.printHistogram();  // search and print the histogram for the items in the input file
				break;
			}
			case 4: {
				cout << "Exiting the program..." << endl;  // exit the program if 4 is entered
			}
		}
	} while (choice != 4);   // loop until the user exits

	return 0;
}