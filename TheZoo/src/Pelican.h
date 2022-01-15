#ifndef PELICAN_H
#define PELICAN_H

#include "Oviparous.h"

using namespace std;

class Pelican : public Oviparous{
	public:
	// Constructor
		Pelican(string name, int trackNum, string type, string subType, int numberOfEggs);


};

#endif
