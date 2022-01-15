#ifndef GOOSE_H
#define GOOSE_H


#include "Oviparous.h"

using namespace std;

class Goose : public Oviparous{
	public:
		// Constructor
		Goose(string name, int trackNum, string type, string subType, int numberOfEggs);


};

#endif
