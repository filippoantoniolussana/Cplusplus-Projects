//============================================================================
// Name        : P1Clock.cpp
// Date        : Jan 21, 2020
// Author      : Filippo Antonio Lussana
// Description : Program that display a 12-hours and a 24-hours clock
//				 where the user can add one hour, minute, or second.
//============================================================================

#include <iostream>  // Include library to get user input
#include <iomanip>   // Include library to use setfill and setw
#include <ctime>     // Include library to get time
using namespace std;


/*
  Void Function that display a 12-hour, and a 24-hour clock according to the local time.
  @Parameters: - hour (type int): Current clock's hours.
               - min (type int): Current clock's minutes.
               - sec (type int): Current clock's seconds.

*/
void displayClock(int hour, int min, int sec) {
	string amPm = "AM";  // Variable to set "AM" or "PM" in the 12-hours clock
	int twelveHour;      // Variable to convert hours from 24-hours to 12-hours.

	// If/else statement to convert 24-hours to 12-hours, and set AM/PM accordingly.
    if (hour <= 12) {
    	twelveHour = hour;
    	amPm = "AM";
    }
    else {
    	twelveHour = hour - 12;
    	amPm = "PM";
    }

    // Print the 12-hours and 24-hours clock
	cout << setfill('*') << setw(26) << "" << setfill(' ') << setw(4) << "" << setfill('*') << setw(26) << "" << endl;
	cout << "*     12-Hour Clock      *" << setfill(' ') << setw(4) << ""  << "*     24-Hour Clock      *" << endl;
	printf("*     %2d:%2d:%2d %s        *    *       %2d:%2d:%2d         *\n", twelveHour, min, sec, amPm.c_str(), hour, min, sec);
	cout << setfill('*') << setw(26) << "" << setfill(' ') << setw(4) << "" << setfill('*') << setw(26) << "" << endl;
	cout << endl;
	cout << endl;

}


/*
  Void Function that add one hour to the 12-hours and 24-hours clock.
  @Parameters: - hour (type int - passed by reference): Current clock's hours.
               - min (type int ): Current clock's minutes.
               - sec (type int): Current clock's seconds.

*/
void addOneHour(int& hour, int min, int sec) {
	// If/else statement to restart the hours or add one hour to the clock
	if (hour == 23) {
		hour = 0;
	}
	else {
		hour++;
	}

	// Print the clocks
	displayClock(hour, min, sec);
}


/*
  Void Function that add one minute to the 12-hours and 24-hours clock.
  @Parameters: - hour (type int - passed by reference): Current clock's hours.
               - min (type int - passed by reference): Current clock's minutes.
               - sec (type int): Current clock's seconds.

*/
void addOneMinute(int& hour, int& min, int sec) {
	// If/else statement to restart the minutes or add one minute to the clock
	if (min == 59) {
		hour = hour + 1;
		min = 0;
	}
	else {
		min++;
	}

	// Print the clocks
	displayClock(hour, min, sec);
}


/*
  Void Function that add one hour to the 12-hours and 24-hours clock.
  @Parameters: - hour (type int): Current clock's hours.
               - min (type int - passed by reference): Current clock's minutes.
               - sec (type int - passed by reference): Current clock's seconds.

*/
void addOneSecond(int hour, int& min, int& sec) {
	// If/else statement to restart the seconds or add one second to the clock
	if (sec == 59) {
		min = min + 1;
		sec = 0;
	}
	else {
		sec++;
	}

	// Print the clocks
	displayClock(hour, min, sec);
}


int main() {
	time_t ttime = time(0);       // Create a time_t object with current time
	tm *lt = localtime(&ttime);   // Initialize pointer for ctime tm structure to get hours, minutes, and seconds
	char menuOption = 'y';        // Variable to start the loop and get user's menu option


	// Display the 12-hours and 24-hours clock
	displayClock(lt->tm_hour, lt->tm_min, lt->tm_sec);

	// While loop that iterate until '4' is entered
	while (menuOption != '4') {
		// If/else statement to call each function based on the user's input
		if (menuOption == '1') {
			addOneHour(lt->tm_hour, lt->tm_min, lt->tm_sec);
		}
		else if (menuOption == '2') {
			addOneMinute(lt->tm_hour, lt->tm_min, lt->tm_sec);
		}
		else if (menuOption == '3') {
			addOneSecond(lt->tm_hour, lt->tm_min, lt->tm_sec);
		}
		else if (menuOption == '4') {
			break; // If '4' is entered, exit the program
		}

		// Display the option menu
		cout << "What option would you like?" << endl;
		cout << setfill('*') << setw(20) << "" << endl;
		cout << "*" << setfill(' ') << setw(18) << left << " 1-Add One Hour" << "*" << endl;
		cout << "*" << setfill(' ') << setw(18) << left << " 2-Add One Minute" << "*" << endl;
		cout << "*" << setfill(' ') << setw(18) << left << " 3-Add One Second" << "*" << endl;
		cout << "*" << setfill(' ') << setw(18) << left << " 4-Exit Program" << "*" << endl;
		cout << setfill('*') << setw(20) << "" << endl;

		// Display ">>" and get user's menu option
		cout << ">>";
		cin >> menuOption;

	}

	// Display a message when the user exit the program
	cout << "Have a great day!";

	return 0;
}
