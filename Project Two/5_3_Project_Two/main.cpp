#include "Investment.h"

int main() {
	Investment myInvestment; // create investment class instance

	myInvestment.getInput(); // get input from user

	myInvestment.displayData(); // display entered data

	// display year end reports
	myInvestment.displayBothReports();


	return 0;
}