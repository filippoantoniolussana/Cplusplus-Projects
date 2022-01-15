#include "Animal.h"

/*
  Accessor for trackNum
  @return: - trackNum (type int): animal's tracking number
*/
int Animal::GetTrackNum() {
	return trackNum;
}

/*
  Accessor for name
  @return: - name (type string): animal's name
*/
string Animal::GetName(){
	return name;
}

/*
  Accessor for type
  @return: - type (type string): animal's type
*/
string Animal::GetType(){
	return type;
}

/*
  Accessor for subType
  @return: - subType (type string): animal's sub-type
*/
string Animal::GetSubType() {
	return subType;
}


/*
  Virtual accessor for number of eggs
  @return: - value 0 (type int): mammal's fixed number of eggs
*/
int Animal::GetNumEggs() {
	return 0;
}


/*
  Virtual accessor for nursing status
  @return: - value 0 (type int): oviparous fixed nursing status
*/
int Animal::GetNurse() {
	return 0;
}

