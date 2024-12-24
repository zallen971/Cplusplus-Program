#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// ItemTracker class
class ItemTracker {
private:
	map<string, int> itemFrequency;  // stores items and their frequencies
	string inputFileName;    // Name of input file
	string backupFileName;  // name of backup file

	string capitalFirstLetter(const string& str) const; // function to capitalize first letter

	string toLowerCase(const string& str) const;  // function to lowercase user inputs


	void loadFileData();      // reads item frequency data from the input file and populates the map
	void writeBackupFile();  // writes the current item frequency data to the backup file

public:
	ItemTracker(const string& inputFIle, const string& backupFile);  // constructs ItemTracker object with file names

	void searchItemFrequency(const string& item) const;  // searches for the frequency of the specific item
	void printAllFrequencies() const;  // prints the frequencies of all items
	void printHistogram() const;  // prints the histogram of item frequencies
};

#endif  // ITEMTRACKER_H