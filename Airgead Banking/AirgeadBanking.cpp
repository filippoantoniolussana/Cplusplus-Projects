//============================================================================
// Name        : AirgeadBanking.cpp
// Author      : Filippo Antonio Lussana
// Date        : Feb 3, 2021
// Description : Program that calculates the compound interest and displays
//				 the end year's balance and interest based on user input.
//============================================================================

#include <iostream>
#include <iomanip>

#include "InvestmentPlan.h"

using namespace std;


int main() {
	InvestmentPlan newPlan;  // Initialize an InvestmentPlan object
	double initialAmount;    // User's initial investment amount
	double monthlyDeposit;   // User's monthly deposit
	int annualInterest;      // User's annual interest
	int numYears;            // User's length of the investment

	try{
	// Get user's inputs
		cout << setfill('*') << setw(40) << "" << endl;
		cout << "*****" << setfill(' ') << setw(25) << right << "New Investment Plan" << setw(10) << "*****" << endl;
		cout << setfill('*') << setw(40) << "" << endl;

		cout << "Initial Investment Amount: " << endl;
		cout << ">>";
		cin >> initialAmount;

		if (initialAmount <= 0) {
			throw runtime_error("Invalid Initial Amount.");
		}
		// Set user's initial amount in object newPlan
		newPlan.SetInitialAmount(initialAmount);   // Set user's initial amount in object newPlan

		cout << "Monthly Deposit: " << endl;
		cout << ">>";
		cin >> monthlyDeposit;

		if (monthlyDeposit <= 0) {
			throw runtime_error("Invalid Monthly Deposit.");
		}
		newPlan.SetMonthlyDeposit(monthlyDeposit); // Set user's monthly deposit in object newPlan

		cout << "Annual Interest: " << endl;
		cout << ">>";
		cin >> annualInterest;

		if (annualInterest <= 0) {
			throw runtime_error("Invalid Annual Interest.");
		}
		newPlan.SetAnnualInterest(annualInterest); // Set user's annual interest in object newPlan

		cout << "Number of years: " << endl;
		cout << ">>";
		cin >> numYears;

		if (numYears <= 0) {
			throw runtime_error("Invalid Number Of Years.");
		}
		newPlan.SetNumYears(numYears);     // Set user's investment length in object newPlan


		cout << endl;
		cout << "Press any key to continue . . ." << endl;

		// Wait until user press any key
		cin.ignore();
		cin.get();

		// Call displayReport() function on object newPlan
		newPlan.displayReport();

	}
	catch (runtime_error& excpt) {
		cout << excpt.what() << " ";
		cout << "Please try again..." << endl;
	}

	return 0;
}
