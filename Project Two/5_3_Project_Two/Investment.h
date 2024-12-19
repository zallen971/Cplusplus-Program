#pragma once

#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <iostream>
using namespace std;

// define the investment class
class Investment {
private:
	// private member variables
	double initialInvestment;
	double monthlyDeposit;
	double annualInterest;
	int numYears;

public:
	Investment(); // constructor

	void getInput(); // get user input method

	void displayData() const; // display data method

	void displayBothReports() const; // calculate final balance without monthly deposits


};

#endif // INVESTMENT_H