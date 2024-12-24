#include "ItemTracker.h"
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cctype>

using namespace std;


// helper function to trim leading and trailing whitespace from a string
string trim(const string& str) {
	size_t start = str.find_first_not_of(" \t\n\r");
	size_t end = str.find_last_not_of(" \t\n\r");

	if (start == string::npos || end == string::npos) {
		return "";  // string contains only whitespace
	}

	return str.substr(start, end - start + 1);
}


// helpter function to capitalize the first letter
string ItemTracker::capitalFirstLetter(const string& str) const {
	if (str.empty()) return str;

	string result = str;
	result[0] = toupper(result[0]);  // capitalize the first letter
	transform(result.begin() + 1, result.end(), result.begin() + 1, ::tolower); // make the rest lowercase
	return result;
}


// function to convert strings to lowercase
string ItemTracker::toLowerCase(const string& str) const {
	string lowerStr = str;
	transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
	return lowerStr;
}


// constructor: initializes the file names and loads data
ItemTracker::ItemTracker(const string& inputFile, const string& backupFile) : inputFileName(inputFile), backupFileName(backupFile) {
	loadFileData();          // load data from input file into memory
	writeBackupFile();      // save the loaded data to a backup file
}


// load item frequency data from the input file
void ItemTracker::loadFileData() {
	ifstream inputFile(inputFileName);
	if (!inputFile.is_open()) {
		// error handling: check if the input file can be opened
		cerr << "Error: Unable to open input file!" << endl;
		return;
	}

	string item;
	int count;

	// read items and their frequencies line by line and count frequencies
	while (getline(inputFile, item)) {
		item = trim(item);          // trim whitespace
		item = toLowerCase(item);  // convert to lowercase
		if (!item.empty()) {
			itemFrequency[item]++;
		}
	}

	inputFile.close();  // close the input file after reading
}


// write the item frequncy to data to do a backup file
void ItemTracker::writeBackupFile() {
	ofstream backupFile(backupFileName);
	if (!backupFile.is_open()) {
		// error handling: check if the backup file can be opened
		cerr << "Error: Unable to save backup file!" << endl;
		return;
	}

	// write each item and its frequency to the backup file
	for (const auto& entry : itemFrequency) {
		backupFile << entry.first << " " << entry.second << "\n";
	}

	backupFile.close();  // close the backup file after writing
}


// search and print the frequency of a specific item
void ItemTracker::searchItemFrequency(const string& item) const {
	string itemLower = toLowerCase(item);  // convert user input to lowercase
	auto it = itemFrequency.find(itemLower);
	if (it != itemFrequency.end()) {
		// item found: print frequency
		cout << "\n" << it->second << "\n" << endl;
	}
	else {
		// item not found
		cout << item << " was not found in the list." << endl;
	}
}



// print all items and their frequencies in tabular format
void ItemTracker::printAllFrequencies() const {
	cout << "\n*** Item Frequencies ***" << endl;

	// iterate through the map and print each item and its frequencies
	for (const auto& entry : itemFrequency) {
		cout << setw(12) << capitalFirstLetter(entry.first) << ": " << entry.second << endl;
	}

	cout << endl;  // new line after frequencies print
}


// print histogram of item frequencies
void ItemTracker::printHistogram() const {
	cout << "\n*** Item Histogram ***\n" << endl;

	// iterate through the map and print a histogram line for each item
	for (const auto& entry : itemFrequency) {
		cout << setw(12) << capitalFirstLetter(entry.first) << ": ";
		cout << string(entry.second, '*') << endl;  // create the histogram using '*'
	}
	cout << endl;  // newline after histogram prints
}