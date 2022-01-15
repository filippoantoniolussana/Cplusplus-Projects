#include "Oviparous.h"

/*
  Void function that prints the information for animals of type Oviparous
*/
void Oviparous::Print() {
	cout << "|" << setfill('0') << setw(6) << right << trackNum << setfill(' ') << setw(11) << "|" << setw(15) << left << name;
	cout << "|" << setw(15) << left << type << "|" << setw(15) << left << subType;
	cout << "|" << setw(15) << left << numberOfEggs << "|" << setw(15) << left << GetNurse() << "|" << endl;
	cout << setfill('-') << setw(17) << left << "+" << setw(16) << "+" << setw(16) << "+" << setw(16) << "+" << setw(16) << "+" << setw(16) << "+" << "+" << endl;
}


/*
  Accessor for numberOfEggs
  @return: - numberOfEggs (type int): animal's number of eggs
*/
int Oviparous::GetNumEggs() {
	return numberOfEggs;
}
