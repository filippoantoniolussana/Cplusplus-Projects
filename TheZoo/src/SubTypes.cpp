#include "Crocodile.h"
#include "Goose.h"
#include "Pelican.h"
#include "Whale.h"
#include "Bat.h"
#include "SeaLion.h"


/*
  Crocodile constructor
  @parameters: - name (type string): animal's name
               - trackNum (type int): animal's track number
               - type (type string): animal's type
               - subType (type string): animal's sub-type
               - numberOfeggs (type int): animal's number of eggs
*/
Crocodile::Crocodile(string name, int trackNum, string type, string subType, int numberOfEggs) {
			this->name = name;
			this->trackNum = trackNum;
			this->type = type;
			this->subType = subType;
			this->numberOfEggs = numberOfEggs;
		}

/*
  Goose constructor
  @parameters: - name (type string): animal's name
               - trackNum (type int): animal's track number
               - type (type string): animal's type
               - subType (type string): animal's sub-type
               - numberOfeggs (type int): animal's number of eggs
*/
Goose::Goose(string name, int trackNum, string type, string subType, int numberOfEggs) {
	this->name = name;
	this->trackNum = trackNum;
	this->type = type;
	this->subType = subType;
	this->numberOfEggs = numberOfEggs;
}


/*
  Pelican constructor
  @parameters: - name (type string): animal's name
               - trackNum (type int): animal's track number
               - type (type string): animal's type
               - subType (type string): animal's sub-type
               - numberOfeggs (type int): animal's number of eggs
*/
Pelican::Pelican(string name, int trackNum, string type, string subType, int numberOfEggs) {
	this->name = name;
	this->trackNum = trackNum;
	this->type = type;
	this->subType = subType;
	this->numberOfEggs = numberOfEggs;
}


/*
  Whale constructor
  @parameters: - name (type string): animal's name
               - trackNum (type int): animal's track number
               - type (type string): animal's type
               - subType (type string): animal's sub-type
               - nurse (type int): animal's nursing status
*/
Whale::Whale(string name, int trackNum, string type, string subType, int nurse) {
		this->name = name;
		this->trackNum = trackNum;
		this->type = type;
		this->subType = subType;
		this->nurse = nurse;
	}

/*
  Bat constructor
  @parameters: - name (type string): animal's name
               - trackNum (type int): animal's track number
               - type (type string): animal's type
               - subType (type string): animal's sub-type
               - nurse (type int): animal's nursing status
*/
Bat::Bat(string name, int trackNum, string type, string subType, int nurse) {
	this->name = name;
	this->trackNum = trackNum;
	this->type = type;
	this->subType = subType;
	this->nurse = nurse;
}

/*
  Sea Lion constructor
  @parameters: - name (type string): animal's name
               - trackNum (type int): animal's track number
               - type (type string): animal's type
               - subType (type string): animal's sub-type
               - nurse (type int): animal's nursing status
*/
SeaLion::SeaLion(string name, int trackNum, string type, string subType, int nurse) {
	this->name = name;
	this->trackNum = trackNum;
	this->type = type;
	this->subType = subType;
	this->nurse = nurse;
}
