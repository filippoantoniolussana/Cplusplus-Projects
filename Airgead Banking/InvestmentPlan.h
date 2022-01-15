#ifndef INVESTMENT_PLAN_H
#define INVESTMENT_PLAN_H

#include <iostream>
using namespace std;

class InvestmentPlan{
	public:

		//Mutators
		void SetInitialAmount(double initialAmount);
		void SetMonthlyDeposit(double monthlyDeposit);
		void SetAnnualInterest(int annualInterest);
		void SetNumYears(int investmentTime);

		//Other methods
		void displayReport();
		void compoundInterest();

	private:
		// Initialized private members
		double initialAmount;
		double monthlyDeposit;
		int annualInterest;
		int numYears;

};

#endif
