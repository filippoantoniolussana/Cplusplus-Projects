#include <iostream>
#include <iomanip>
#include "InvestmentPlan.h"

using namespace std;


/*
  Mutator to set InvestmentPlan initial amount
  @Parameter: - initialAmount (type double): user's initial amount
*/
void InvestmentPlan::SetInitialAmount(double initialAmount) {
	this->initialAmount = initialAmount;
}

/*
  Mutator to set InvestmentPlan monthlyDeposit
  @Parameter: - monthlyDeposit (type double): user's monthly deposit
*/
void InvestmentPlan::SetMonthlyDeposit(double monthlyDeposit) {
	this->monthlyDeposit = monthlyDeposit;
}

/*
  Mutator to set InvestmentPlan annual interest
  @Parameter: - annualInterest (type int): user's annual interest
*/
void InvestmentPlan::SetAnnualInterest(int annualInterest) {
	this->annualInterest = annualInterest;
}

/*
  Mutator to set InvestmentPlan number of years
  @Parameter: - numYears (type int): user's number of years
*/
void InvestmentPlan::SetNumYears(int numYears) {
	this->numYears = numYears;
}




/*
  Function that displays the user's entered information, call compound interest function
  and display a menu to allow the user to change the initially entered information
*/
void InvestmentPlan::displayReport() {
	char menuOption = 'y';  // Variable to check loop condition and select menu option

	// Display user's entered value
	cout << setfill('*') << setw(40) << "" << endl;
	cout << "*****" << setfill(' ') << setw(25) << right << "Your Investment Plan" << setw(10) << "*****" << endl;
	cout << setfill('*') << setw(40) << "" << endl;

	cout << "Initial Investment Amount:  $" << initialAmount << endl;
	cout << endl;
	cout << "Monthly Deposit:  $" << monthlyDeposit << endl;
	cout << endl;
	cout << "Annual Interest:  %" << annualInterest << endl;
	cout << endl;
	cout << "Number of years:  " << numYears << endl;

	cout << endl;
	cout << "Press any key to continue . . ." << endl;

	// Wait until user press any key
	cin.get();

	// Call compoundInterest() function to calculate and display the compound interest based on user's data
	compoundInterest();

	try{

	// While loop that iterates a menu to allow the user to change data until 'q' is entered
		while(menuOption != 'q') {


			// Display menu option
			cout << setfill('*') << setw(32) << "" << endl;
			cout << "*****" << setfill(' ') << setw(13) << right << "Menu" << setw(14) << "*****" << endl;
			cout << setfill('*') << setw(32) << "" << endl;
			cout << "*  a - Update monthly deposit  *" << endl;
			cout << "*  b - Update annual interest  *" << endl;
			cout << "*  c - Update number of years  *" << endl;
			cout << "*  q - quit                    *" << endl;
			cout << setfill('*') << setw(32) << "" << endl << endl;
			cout << ">>";
			cin >> menuOption;

			// If/else statement to get new user's data based on the selected menu option
			if (menuOption == 'a') {
				cout << "Enter new monthly deposit: " << endl;
				cout << ">>";
				cin >> monthlyDeposit;

				// Throw an error if monthlyDeposit is less than 1 or char is entered
				if (monthlyDeposit < 1) {
					throw runtime_error("Invalid Monthly Deposit.");
				}

				// Call compoundInterest() function with new monthly deposit
				compoundInterest();

			}
			else if (menuOption == 'b') {
				cout << "Enter new annual interest: " << endl;
				cout << ">>";
				cin >> annualInterest;

				// Throw an error if annualInterest is less than 1 or char is entered
				if (annualInterest <= 0) {
					throw runtime_error("Invalid Annual Interest.");
				}

				// Call compoundInterest() function with new annual interest
				compoundInterest();

			}
			else if (menuOption == 'c') {
				// Call compoundInterest() function with new number of years
				cout << "Enter new number of years: " << endl;
				cout << ">>";
				cin >> numYears;

				// Throw an error if numYears is less than 1 or char is entered
				if (numYears <= 0) {
					throw runtime_error("Invalid Number Of Years.");
				}

				compoundInterest();

			}
			else if (menuOption == 'q') {

				// Exit loop if 'q' is entered
				cout << "Have a great day!" << endl;
				break;
			}
			else {

				// Display a message if the entered menu option is not available
				cout << "Menu option not available. Please select an option from the menu!" << endl;
				cout << ">>";
				cin >> menuOption;
			}

		}

	}
	catch(runtime_error& excpt){
		// Display the error message passed by throw statement
		cout << excpt.what() << " ";
		cout << "Please try again..." << endl << endl;
	}

}




/*
  Function that calculates the compound interest and displays the user's year-end
  balance with and without the additional monthly deposits
*/
void InvestmentPlan::compoundInterest() {
	const int MONTHS_PER_YEAR = 12;    // Month in a year
	double monthlyBalance;             // Variable to update the monthly balance
	double monthlyInterest;            // Variable to update the monthly interest
	double endYearInterest;            // Total end of the year interest
	double endYearBalance;             // Total end of the year balance
	double tmpAmount = initialAmount;  // Variable to restore initialAmount once compoundInterest() is called again
	int i, j;                 // Loop index



	cout << setfill('=') << setw(75) << "" << endl;
	cout << "         Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << setfill('=') << setw(75) << "" << endl;
	cout << endl;
	cout << "    Year          Year End Balance        Year End Earned Interest     " << endl;
	cout << endl;
	cout << setfill('=') << setw(75) << "" << endl;

	// For loop that iterates for the number of years
	for (j = 1; j <= numYears; ++j) {

		// Set endYearInterest to zero to re-calculate interest for the next year
		endYearInterest = 0;

		// For loop that iterate for each month
		for (i = 1; i <= MONTHS_PER_YEAR; ++i) {

			monthlyInterest = initialAmount * ((annualInterest / 100.0) / 12.0);
			monthlyBalance = monthlyInterest + initialAmount;

			// Each month's monthly balance is set to be the initial amount for the next month
			initialAmount = monthlyBalance;

			// Sum each month's interest to get endYearInterest
			endYearInterest = endYearInterest + monthlyInterest;

			// endYearBalance corresponds to the last monthly balance of the year
			if (i == 12) {
				endYearBalance = monthlyBalance;
			}

		}

		// Display endYearBalance and endYearInterest
		cout << setfill(' ') << setw(5) << right << j;
		cout << setw(25) << right << fixed << setprecision(2) << endYearBalance;
		cout << setw(25) << right << fixed << setprecision(2) << endYearInterest << endl;
		cout << setfill('-') << setw(75) << "" << endl;

	}


		cout << endl << endl << endl;

		cout << setfill('=') << setw(75) << "" << endl;
		cout << "         Balance and Interest With Additional Monthly Deposits" << endl;
		cout << setfill('=') << setw(75) << "" << endl;
		cout << endl;
		cout << "    Year          Year End Balance        Year End Earned Interest     " << endl;
		cout << endl;
		cout << setfill('=') << setw(75) << "" << endl;

		// For loop that iterates for the number of years
		for (j = 1; j <= numYears; ++j) {

			// Set endYearInterest to zero to re-calculate interest for the next year
			endYearInterest = 0;

			// For loop that iterate for each month
			for (i = 1; i <= MONTHS_PER_YEAR; ++i) {

				monthlyInterest = (initialAmount + monthlyDeposit) * ((annualInterest / 100.0) / 12.0);
				monthlyBalance = monthlyInterest + initialAmount + monthlyDeposit;

				// Each month's monthly balance is set to be the initial amount for the next month
				initialAmount = monthlyBalance;

				// Sum each month's interest to get endYearInterest
				endYearInterest = endYearInterest + monthlyInterest;

				// endYearBalance corresponds to the last monthly balance of the year
				if (i == 12) {
					endYearBalance = monthlyBalance;
				}

			}

			// Display endYearBalance and endYearInterest
			cout << setfill(' ') << setw(5) << right << j;
			cout << setw(25) << right << fixed << setprecision(2) << endYearBalance;
			cout << setw(25) << right << fixed << setprecision(2) << endYearInterest << endl;
			cout << setfill('-') << setw(75) << "" << endl;


		}

		cout << endl << endl;

		// Restore initialAmount value for next compoundInteres() call
		initialAmount = tmpAmount;

	}
