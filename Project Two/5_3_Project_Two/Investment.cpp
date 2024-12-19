#include "Investment.h"
#include <iomanip> // for formatting output
#include <cmath> // for pow() function

// constructor 
Investment::Investment() : initialInvestment(0.0), monthlyDeposit(0.0), annualInterest(0.0), numYears(0) {}


//get user input method
void Investment::getInput() {
	cout << "**********************************" << endl;
	cout << "********** Data Input ************" << endl;

	cout << "Initial Investment Amount: ";
	cin >> initialInvestment;

	cout << "Monthly Deposit: ";
	cin >> monthlyDeposit;

	cout << "Annual Interest: ";
	cin >> annualInterest;

	cout << "Number of years: ";
	cin >> numYears;
}


// display data method
void Investment::displayData() const {
	system("CLS"); // clear screen

	cout << "**********************************" << endl;
	cout << "********** Data Input ************" << endl;

	cout << fixed << setprecision(2); // format to 2 decimal places
	cout << "Initial Investment Amount: $" << initialInvestment << endl;
	cout << "Monthly Deposit: $" << monthlyDeposit << endl;
	cout << "Annual Interest: " << annualInterest << "%" << endl;
	cout << "Number of years: " << numYears << endl;

	cout << "Press any key to continue..." << endl;

	// wait for user input to continue
	cin.ignore();
	cin.get();
}

// calculate final balance without monthly deposits
void Investment::displayBothReports() const {
	system("CLS"); // clear the screen

	cout << "Balance and Interest Without Additional Monthly Deposits\n";
	cout << "=============================================================\n";
	cout << "Year\t     Year End Balance\t Year End Earned Interest\n";
	cout << "-------------------------------------------------------------\n";
	
	double balanceNoDeposit = initialInvestment;
	double annualInterestRate = annualInterest / 100.0;

	for (int year = 1; year <= numYears; year++) {
		double yearStartBalance = balanceNoDeposit;
		balanceNoDeposit *= (1 + annualInterestRate); // apply annual interest
		double interestEarned = balanceNoDeposit - yearStartBalance;

		cout << setw(4) << year << setw(20) << fixed << setprecision(2) << "   $" << balanceNoDeposit << setw(25) << "      $" << interestEarned << endl;
		cout << endl;
	}

	cout << endl;

// calculate final balance with monthly deposits
	cout << "Balance and Interest With Additional Monthly Deposits\n";
	cout << "=============================================================\n";
	cout << "Year\t     Year End Balance\t Year End Earned Interest\n";
	cout << "-------------------------------------------------------------\n";

	double balanceWithDeposit = initialInvestment;
	double monthlyInterestRate = annualInterestRate / 12.0;

	for (int year = 1; year <= numYears; year++) {
		double yearStartBalance = balanceWithDeposit;

		for (int month = 0; month < 12; month++) {
			balanceWithDeposit += monthlyDeposit; // add monthly deposit
			balanceWithDeposit *= (1 + monthlyInterestRate); // add monthly interest
		}
		double interestEarned = balanceWithDeposit - yearStartBalance - (monthlyDeposit * 12);

		cout << setw(4) << year << setw(20) << fixed << setprecision(2) << "   $" << balanceWithDeposit << setw(25) << "      $" << interestEarned << endl;
		cout << endl;
	}

}