#include "clockfunction.h"


// function to display both 12-hour and 24-hour clocks
void displayClocks(int hour12, int minute, int second, int hour24) {
    cout << "**************************       **************************" << endl;
    cout << "*       12-Hour Clock    *       *      24-Hour Clock     *" << endl; // 12 and 24 hour clocks
    cout << "*      " << setw(2) << setfill('0') << hour12 << ":" << setw(2) << setfill('0') << minute
        << ":" << setw(2) << setfill('0') << second << (hour24 < 12 ? " AM" : " PM")
        << "       *       *       " << setw(2) << setfill('0') << hour24 << ":" << setw(2)
        << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << "         *" << endl; // displays time
    cout << "**************************       **************************" << endl;
}

// function to display the menu
void displayMenu() {
    cout << endl << endl;
    cout << "**************************" << endl;
    cout << "* 1 - Add One Hour       *" << endl;
    cout << "* 2 - Add One Minute     *" << endl;
    cout << "* 3 - Add One Second     *" << endl;
    cout << "* 4 - Exit Program       *" << endl;
    cout << "**************************" << endl;
    cout << endl << endl;
}

// function to add time to the clocks
void addTime(int& hour12, int& hour24, int& minute, int& second, int choice) {
    if (choice == 1) { // add 1 hour if user choice is 1
        hour12 = (hour12 % 12) + 1; 
        hour24 = (hour24 + 1) % 24;
    }
    else if (choice == 2) { // add one minute if user choice is 2
        minute = (minute + 1) % 60;
        if (minute == 0) { // if minute resets to 0 add an hour
            hour12 = (hour12 % 12) + 1;
            hour24 = (hour24 + 1) % 24;
        }
    }
    else if (choice == 3) { // add one second if user choice is 3
        second = (second + 1) % 60;
        if (second == 0) { // if second resets to 0 add a minute
            minute = (minute + 1) % 60;
            if (minute == 0) { // if minute also resets to 0 add an hour
                hour12 = (hour12 % 12) + 1;
                hour24 = (hour24 + 1) % 24;
            }
        }
    }
}

int main() {
    time_t now = time(0); // get current time
    tm localTimeStruct; // structure to hold local time
    tm* localTime = &localTimeStruct; // creates the pointer for the structure
    localtime_s(localTime, &now); // converts time

    // initialize time for 12-hour and 24-hour clocks
    int hour24 = localTime->tm_hour; // 24 hour clock
    int hour12 = (hour24 % 12 == 0) ? 12 : hour24 % 12; // 12 hour clock
    int minute = localTime->tm_min; // current minute
    int second = localTime->tm_sec; // current second

    int choice;

    // run the program until the user chooses Exit
    while (true) {
        displayClocks(hour12, minute, second, hour24);
        displayMenu();

        // get user choice
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) { // checks for invalid input
            cin.clear(); // clears the failed state input
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // removes the invalid input
            cout << "Invalid input. Please enter a valid options: 1, 2, 3, or 4." << endl;
            cout << endl;
            continue;
        }

        if (choice == 4) {
            cout << "Exiting the program..." << endl; // exit the program if user choice is 4
            break;
        }
        else if (choice >= 1 && choice <= 3) {
            addTime(hour12, hour24, minute, second, choice); // add time based on user choice
        }
        else {
            cout << "Invalid choice. Please try again..." << endl; // if input is invalid
        }
    }

    return 0;
}