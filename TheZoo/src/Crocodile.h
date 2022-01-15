#ifndef CROCODILE_H
#define CROCODILE_H

#include "Oviparous.h"

using namespace std;

class Crocodile : public Oviparous{
	public:
		// Constructor
		Crocodile(string name, int trackNum, string type, string subType, int numberOfEggs);

};

#endif
