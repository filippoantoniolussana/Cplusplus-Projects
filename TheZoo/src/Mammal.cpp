#include "Mammal.h"

/*
  Void function that prints the information for animals of type Mammal
*/
void Mammal::Print() {
	cout << "|" << setfill('0') << setw(6) << right << trackNum << setfill(' ') << setw(11) << "|" << setw(15) << left << name;
	cout << "|" << setw(15) << left << type << "|" << setw(15) << left << subType;
	cout << "|" << setw(15) << left << GetNumEggs() << "|" << setw(15) << left << nurse << "|" << endl;
	cout << setfill('-') << setw(17) << left << "+" << setw(16) << "+" << setw(16) << "+" << setw(16) << "+" << setw(16) << "+" << setw(16) << "+" << "+" << endl;
}

/*
  Accessor for nurse
  @return: - nurse (type int): animal's nursing status
*/
int Mammal::GetNurse(){
	return nurse;
}
