//============================================================================
// Name        : TheZoo.cpp
// Author      : Filippo Antonio Lussana
// Date        : Feb 1, 2021
// Description : Program interface to maintain animal data for Wildlife Zoo.
//				 It allows to load, edit and save data each animal's data into a file.
//====

#include <iostream>
#include <jni.h>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

#include "Animal.h"
#include "Crocodile.h"
#include "Goose.h"
#include "Pelican.h"
#include "Whale.h"
#include "Bat.h"
#include "SeaLion.h"


using namespace std;

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}


/*
  Void function to add a new animal to the vector
  @Parameter: - &animals (vector of type Animal objects pointers): vector to store each animal information
*/
void AddAnimal(vector<Animal*>&animals)
{
	string name;         // Animal's name
	string type;         // Animal's type
	string subType;      // Animal's sub-type
	int trackNum;        // Animal's track number
	int numberOfEggs;    // Animal's number of eggs
	int nurse;           // Animal's nursing status
	char saveAnimal;     // Confirm animal addition

	try{

		// Get animal's tracking number
		cout << "Track number: " << endl;
		cout << ">>" << endl;
		cin >> trackNum;

		// If track number less than 1 or more than 999999 throw an error
		if (trackNum < 1 || trackNum > 999999) {
			throw runtime_error("Invalid track number.");
		}

		// For loop that checks if track number on the system.
		for (unsigned int i = 0; i < animals.size(); ++i) {
			if (animals.at(i)->GetTrackNum() == trackNum) {
				cout << "Track number already registered." << endl;
				return;
			}
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n' );

		// Get animal's name
		cout << "Enter Animal Name: " << endl;
		cout << ">>";
		getline(cin, name);


		// Get animal's type
		cout << "Enter Animal Type: " << endl;
		cout << ">>";
		cin >> type;


		// Get animal's sub-type
		cout << "Enter Animal Sub-type " << endl;
		cout << ">>";
		cin >> subType;

		// Get animal's number of eggs
		cout << "Enter Number of Eggs:" << endl;
		cout << ">>";
		cin >> numberOfEggs;

		// Throw an error if number of eggs is less than 0 or a char
		if (numberOfEggs < 0) {
			throw runtime_error("Invalid number of eggs.");
		}

		// Get animal's nursing status
		cout << "Enter 1 if Nursing, 0 if not: " << endl;
		cout << ">>";
		cin >> nurse;

		// Throw an error if nurse is not 0 or 1, or if char is entered
		if (nurse < 0 || nurse > 1) {
			throw runtime_error("Only 0 or 1 allowed for nursing.");
		}

		// Get user confirmation to add new animal
		cout << "Enter any key to save or 'n' to cancel addition" << endl;
		cout << ">>";
		cin >> saveAnimal;

		if (saveAnimal == 'n') {
			cout << "The addition has been canceled" << endl << endl;
			return;
		}

		// Create and add an animal object to the vector based on the subtype
		if (subType.find("Crocodile") != string::npos) {
			animals.push_back(new Crocodile (name, trackNum, type, subType ,numberOfEggs));
		}
		else if (subType == "Goose") {
			animals.push_back(new Goose (name, trackNum, type, subType ,numberOfEggs));
		}
		else if (subType == "Pelican") {
			animals.push_back(new Pelican (name, trackNum, type, subType ,numberOfEggs));
		}
		else if (subType == "Whale") {
			animals.push_back(new Whale (name, trackNum, type, subType ,nurse));
		}
		else if (subType == "Bat") {
			animals.push_back(new Bat (name, trackNum, type, subType ,nurse));
		}
		else if (subType == "Sea lion") {
			animals.push_back(new SeaLion (name, trackNum, type, subType ,nurse));
		}
		else {
			// Throw an error if an invalid sub-type is entered
			throw runtime_error("Invalid sub-type.");
		}

			// Display a message if the animal has been successfully added to the vector
			cout << "New animal successfully added" << endl << endl;

	}
	catch(runtime_error& excpt){
		// Clear input
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// Display the error message passed by throw statement
		cout << excpt.what() << " ";
		cout << "Please try again..." << endl << endl;
		return;

	}






     /*
            TODO: Write proper code to add an animal to your vector (or array)
     */
}


/*
  Void function to remove an animal object from the vector
  @Parameter: - &animals (vector of type Animal objects pointers): vector to store each animal information
*/
void RemoveAnimal(vector<Animal*>&animals)
{
	int trackNum;        // Animal's track number
	char confirmDelete;  // Confirm animal deletion

	try {
		// Get animal's track number
		cout << "Enter Track Number: " << endl;
		cout << ">>";
		cin >> trackNum;


		// If track number less than 1 or more than 999999 throw error
		if (trackNum < 1 || trackNum > 999999 ) {
			throw runtime_error("Invalid track number.");

		}

		// For loop that iterates through the vector
		for (unsigned int i = 0; i < animals.size(); ++i) {

			// If animal found in the vector ask for deletion confirmation
			if (animals.at(i)->GetTrackNum() == trackNum) {
				cout << "Delete animal? Enter y for yes or n for no" << endl;
				cout << ">>";
				cin >> confirmDelete;

				// If 'y' entered delete animal from vector
				if (confirmDelete == 'y') {
					animals.erase(animals.begin() + i);
					cout << "Animal successfully deleted" << endl;
					break;
				}
			}

		}

		// Display a message if animal not found in vector
		cout << "Animal not found" << endl;
	}
	catch(runtime_error& excpt){
		// Clear input
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// Display the error message passed by throw statement
		cout << excpt.what() << " ";
		cout << "Please try again..." << endl << endl;
		return;

	}



}


/*
  Void function that loads data from the file to the vector
  @Parameter: - &animals (vector of type Animal objects pointers): vector to store each animal information
*/
void LoadDataFromFile(vector<Animal*>&animals)
{
	ifstream inFS;     // Input file stream
	string line;       // Store each line from the file
	string name;       // Animal's name
	string type;       // Animal's type
	string subType;    // Animal's sub-type
	int trackNum;      // Animal's track number
	int numberOfEggs;  // Animal's number of eggs
	int nurse;         // Animal's nursing status

	// Empty the vector
	animals.clear();

	// Open file
	inFS.open("zoodata.txt");

	// Check whether the file successfully opened
	if (!inFS.is_open()) {
	      cout << "Could not open file " << endl;
	   }

	// While loop that iterates until end of lines
	while (!inFS.eof()) {

		  // Get line from file
		  getline(inFS, line);

		  // Extract data from line and stores in variables
		  trackNum = stoi(line.substr(0, 7),nullptr,10);    // stoi() used to convert string to integer
		  name = line.substr(8,15);
		  type = line.substr(25,15);
		  subType = line.substr(42,15);
		  numberOfEggs = stoi(line.substr(59,1),nullptr,10);
		  nurse = stoi(line.substr(61,1),nullptr,10);

		  // If/else statement that creates an animal object based on the sub-type and adds it to the vector
		  if (subType.find("Crocodile") != string::npos) {
			  animals.push_back(new Crocodile (name, trackNum, type, subType ,numberOfEggs));
		  }
		  else if (subType.find("Goose") != string::npos) {
			  animals.push_back(new Goose (name, trackNum, type, subType ,numberOfEggs));
		  }
		  else if (subType.find("Pelican") != string::npos) {
			  animals.push_back(new Pelican (name, trackNum, type, subType ,numberOfEggs));
		  }
		  else if (subType.find("Bat") != string::npos) {
			  animals.push_back(new Bat (name, trackNum, type, subType ,nurse));
		  }
		  else if (subType.find("Whale") != string::npos) {
			  animals.push_back(new Whale (name, trackNum, type, subType ,nurse));
		  }
		  else if (subType.find("SeaLion") != string::npos) {
			  animals.push_back(new SeaLion (name, trackNum, type, subType ,nurse));
		  }
		  else {
			  cout << "Animal: " << trackNum << " not loaded. " << "Sub-type not allowed: " << subType << endl;
		  }


	}

	// Close file
	inFS.close();

	// Display a message once load completed
	cout << "Load complete." << endl << endl;


}


/*
  Void function that stores vector data in the file
  @Parameter: - &animals (vector of type Animal objects pointers): vector to store each animal information
*/
void SaveDataToFile(vector<Animal*>&animals)
{
	ofstream outFS; // Output file stream

	// Open file
	outFS.open("zoodata.txt");

	// Check whether the file successfully opened
	if (!outFS.is_open()) {
	      cout << "Could not open file " << endl;
	   }

	// For loop that iterate through all animal objects
	for (unsigned int i = 0; i < animals.size(); ++i) {

		if (i == 0) {
			// Print first element without new line
			outFS << setfill('0') << setw(7) << right << animals.at(i)->GetTrackNum() << " " << setfill(' ') << setw(17) << left << animals.at(i)->GetName();
			outFS << setw(16) << left << animals.at(i)->GetType() << " ";
			outFS << setw(16) << left << animals.at(i)->GetSubType() << " ";
			outFS << animals.at(i)->GetNumEggs() << " " << animals.at(i)->GetNurse();

		}
		else {
			// From second elements print adding new line
			outFS << endl;
			outFS << setfill('0') << setw(7) << right << animals.at(i)->GetTrackNum() << " " << setfill(' ') << setw(17) << left << animals.at(i)->GetName();
			outFS << setw(16) << left << animals.at(i)->GetType() << " ";
			outFS << setw(16) << left << animals.at(i)->GetSubType() << " ";
			outFS << animals.at(i)->GetNumEggs() << " " << animals.at(i)->GetNurse();

		}

	}

	// Close file
	outFS.close();

}


/*
  Void function that displays a menu for the user to select different operations
  @Parameter: - &animals (vector of type Animal objects pointers): vector to store each animal information
*/
void DisplayMenu(vector<Animal*>&animals)
{
	char menuOption = 'y';  // Loop condition

	// While loop that iterates a menu to allow the user to change data until 'q' is entered
	while (menuOption != 'q') {



		// Display menu option
		cout << setfill('*') << setw(30) << "" << endl;
		cout << "*****" << setfill(' ') << setw(12) << right << "Menu" << setw(13) << "*****" << endl;
		cout << setfill('*') << setw(30) << "" << endl;
		cout << "*  a - Load animal data      *" << endl;
		cout << "*  b - Generate data         *" << endl;
		cout << "*  c - Display animal data   *" << endl;
		cout << "*  d - Add record            *" << endl;
		cout << "*  e - Delete record         *" << endl;
		cout << "*  f - Save animal data      *" << endl;
		cout << "*  q - quit                  *" << endl;
		cout << setfill('*') << setw(30) << "" << endl << endl;
		cout << ">>";
		cin >> menuOption;


		// If/else statements that call each function based on the selected menu option
		if (menuOption == 'a') {
			LoadDataFromFile(animals);
		}
		else if (menuOption == 'b') {
			GenerateData();
		}
		else if (menuOption == 'c') {

			// Display table header
			cout << "+" << setfill('-') << setw(17) << "+" << setw(16) << "+" << setw(16) << "+" << setw(16) << "+" << setw(16) << "+" << setw(16) << "+" << endl;
			cout << "|Track#          |Name           |Type           |Sub-type       |Eggs           |Nurse          |" << endl;
			cout << "+" << setfill('-') << setw(17) << "+" << setw(16) << "+" << setw(16) << "+" << setw(16) << "+" << setw(16) << "+" << setw(16) << "+" << endl;

			// For loop that prints each animals information
			for (unsigned int i = 0; i < animals.size(); ++i) {
				animals.at(i)->Print();
			}

			cout << endl << endl;

		}
		else if (menuOption  == 'd') {
			AddAnimal(animals);
		}
		else if (menuOption == 'e') {
			RemoveAnimal(animals);
		}
		else if (menuOption == 'f') {
			SaveDataToFile(animals);
		}
		else if (menuOption == 'q') {
			cout << "Have a nice day!" << endl;
			return;
		}
		else {
			//Display a message if selected menu option not available
			cout << "Menu option not available." << endl;
		}

	}
}





int main()
{
	vector<Animal*>animals; // Initialize a vector of Animals objects pointers


	// Display user's interface
	DisplayMenu(animals);


	return 1;
}
