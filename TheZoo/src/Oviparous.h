#ifndef OVIPAROUS_H
#define OVIPAROUS_H

#include "Animal.h"
#include <iomanip>

using namespace std;

class Oviparous : public Animal{
	public:
		// Accessors
		int GetNumEggs();

		// Other functions
		void Print();


	protected:
		// Oviparous data member
		int numberOfEggs;


};

#endif
