#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

class Animal{
	public:
		// Accessors
		int GetTrackNum();
		string GetName();
		string GetType();
		string GetSubType();
		virtual int GetNumEggs();
		virtual int GetNurse();

		// Other functions
		virtual  void Print() {};


	protected:
		// Animal data members
		string name;
		int trackNum;
		string type;
		string subType;

};

#endif
