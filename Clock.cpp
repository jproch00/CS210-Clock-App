/*clock.cpp project one
Jordan Proch
CS-210
January 28 2024
*/

#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

void getClock24() { //function for 24 hour clock
			time_t now = time(0);
			tm* lt = localtime(&now);
			int hours = lt->tm_hour;
			int min = lt->tm_min;
			int sec = lt->tm_sec;
			cout << (hours < 10? "0" : "") << hours << ":" << (min < 10 ? "0" : "") << min << ":" << (sec < 10 ? "0" : "") << sec << " ";

			return;
}

void getClock12() { //function for 12 hour clock
	time_t now = time(0);
	tm* lt = localtime(&now);
	int hours = lt->tm_hour;
	int min = lt->tm_min;
	int sec = lt->tm_sec;
	if (hours >= 12) {
		cout << (hours < 10 ? "0" : "") << hours << ":" << (min < 10 ? "0" : "") << min << ":" << (sec < 10 ? "0" : "") << sec << "PM";
	}
	if (hours > 12) { //necessary for 12 hour format
		hours = hours - 12;
		cout << (hours < 10 ? "0" : "") << hours << ":" << (min < 10 ? "0" : "") << min << ":" << (sec < 10 ? "0" : "") << sec << "PM";
	}
	else {
		cout << (hours < 10 ? "0" : "") << hours << ":" << (min < 10 ? "0" : "") << min << ":" << (sec < 10 ? "0" : "") << sec << "AM";
	}
	return;
}

void menuFunc() { //displays UI
	cout << "---------------------" << endl;
	cout << "- 1: Add One Hour ---" << endl;
	cout << "- 2: Add One Minute -" << endl;
	cout << "- 3: Add One Second -" << endl;
	cout << "- 4: Exit Program ---" << endl;
	cout << "---------------------" << endl;
}

int main()
{
	time_t now = time(0);
	tm* lt = localtime(&now);
	int hours = lt->tm_hour;
	int min = lt->tm_min;
	int sec = lt->tm_sec;
	int userInput;

	//clock display below
	cout << "---------------------------------------" << endl;
	cout << "--24-hour clock--     --12-hour clock--" << endl;
	cout << "--   ";
	getClock24();
	cout << " --     --  ";
	getClock12();
	cout << " --" << endl;
	cout << "---------------------------------------" << endl;

	menuFunc();

	cin >> userInput;
	while (userInput != 4) { //continues to loop until user exits
		if (userInput == 1) { //checks user input
			hours = hours + 1;
			if (hours >= 24) {
				hours = 0;
			}
			cout << "---------------------------------------" << endl;
			cout << "--24-hour clock--     --12-hour clock--" << endl;
			cout << "--   ";
			cout << (hours < 10 ? "0" : "") << hours << ":" << (min < 10 ? "0" : "") << min << ":" << (sec < 10 ? "0" : "") << sec << " ";
			cout << " --     --  ";
			if (hours == 12) {
				cout << (hours < 10 ? "0" : "") << hours << ":" << (min < 10 ? "0" : "") << min << ":" << (sec < 10 ? "0" : "") << sec << "PM";
			}
			else if (hours > 12) { //necessary for 12 hour format
				hours = hours - 12;
				cout << (hours < 10 ? "0" : "") << hours << ":" << (min < 10 ? "0" : "") << min << ":" << (sec < 10 ? "0" : "") << sec << "PM";
			}
			else {
				cout << (hours < 10 ? "0" : "") << hours << ":" << (min < 10 ? "0" : "") << min << ":" << (sec < 10 ? "0" : "") << sec << "AM";
			}
			cout << " --" << endl;
			cout << "---------------------------------------" << endl;
			cout << endl;

		}

		else if (userInput == 2) { //checks user input
			min = min + 1;
			if (min >= 60) {
				min = 0;
			}
			cout << "---------------------------------------" << endl;
			cout << "--24-hour clock--     --12-hour clock--" << endl;
			cout << "--   ";
			cout << (hours < 10 ? "0" : "") << hours << ":" << (min < 10 ? "0" : "") << min << ":" << (sec < 10 ? "0" : "") << sec << " ";
			cout << " --     --  ";
			if (hours > 12) { //necessary for 12 hour format
				hours = hours - 12;
				cout << (hours < 10 ? "0" : "") << hours << ":" << (min < 10 ? "0" : "") << min << ":" << (sec < 10 ? "0" : "") << sec << "PM";
			}
			else {
				cout << (hours < 10 ? "0" : "") << hours << ":" << (min < 10 ? "0" : "") << min << ":" << (sec < 10 ? "0" : "") << sec << "AM";
			}
			cout << " --" << endl;
			cout << "---------------------------------------" << endl;
			cout << endl;
			}

		else if (userInput == 3) { //checks user input
			sec = sec + 1;
			if (sec >= 60) {
				sec = 0;
			}
			cout << "---------------------------------------" << endl;
			cout << "--24-hour clock--     --12-hour clock--" << endl;
			cout << "--   ";
			cout << (hours < 10 ? "0" : "") << hours << ":" << (min < 10 ? "0" : "") << min << ":" << (sec < 10 ? "0" : "") << sec << " ";
			cout << " --     --  ";
			if (hours > 12) { //necessary for 12 hour format
				hours = hours - 12;
				cout << (hours < 10 ? "0" : "") << hours << ":" << (min < 10 ? "0" : "") << min << ":" << (sec < 10 ? "0" : "") << sec << "PM";
			}
			else {
				cout << (hours < 10 ? "0" : "") << hours << ":" << (min < 10 ? "0" : "") << min << ":" << (sec < 10 ? "0" : "") << sec << "AM";
			}
			cout << " --" << endl;
			cout << "---------------------------------------" << endl;
			cout << endl;
			}
			menuFunc();
			cin >> userInput;
	}
	if (userInput == 4) { //exits program
		cout << "Exiting Program";
	}

	return 0;
}