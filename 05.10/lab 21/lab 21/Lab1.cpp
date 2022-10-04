// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <numbers>

using namespace std;

const int seconds_in_minute = 60;
const int minutes_in_hour = 60;
const int seconds_in_hour = seconds_in_minute * minutes_in_hour;

int get_full_hours(int seconds) {
    return seconds / seconds_in_hour;
}

int get_remaining_minutes(int seconds) {
    return (seconds / seconds_in_minute) - get_full_hours(seconds) * minutes_in_hour;
}

int main()
{
    int seconds;
    cout << "Enter the number of secondss:";
    cin >> seconds;

    cout << endl << "Number of hours: " << get_full_hours(seconds) << endl;
    cout << "Number of minutes: " << get_remaining_minutes(seconds) << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
