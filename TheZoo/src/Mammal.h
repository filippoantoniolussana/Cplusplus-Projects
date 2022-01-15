#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"
#include <iomanip>

using namespace std;

class Mammal : public Animal{
	public:
		// Accessor
		int GetNurse();

		// Other functions
		void Print();


	protected:
		// Mammal data member
		int nurse;

};

#endif
