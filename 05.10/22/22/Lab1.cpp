// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <numbers>

using namespace std;

const int seconds_in_minute = 60;
const int seconds_in_hour = 60 * seconds_in_minute;
const int hours_on_clock = 12;
const int full_circle_angle = 360;

double calculate_clock_angle(int hour, int minute, int second) {
    int totalSeconds = seconds_in_hour * hour + seconds_in_minute * minute;
    return full_circle_angle * double(totalSeconds) / (seconds_in_hour * hours_on_clock);
}

bool assert_inputs(int hour, int minute, int second) {
    bool h, m, s;

    h = hour < 0 or hour > 11;
    m = minute > 59 or minute < 0;
    s = second > 59 or second < 0;

    if (h || m || s) {
        if (h)
            cout << "Hour should be in range from 0 to 11" << endl;
        if (m)
            cout << "Minute should be in range from 0 to 59" << endl;
        if (s)
            cout << "Second should be in range from 0 to 59" << endl;

        return false;
    }

    return true;
}

int main()
{
    int hour, minute, second;
    cout << "Enter h/m/s/: " << endl;
    cin >> hour >> minute >> second;

    if (!assert_inputs(hour, minute, second))
        return 0;

    cout << endl << "Clock angle: " << calculate_clock_angle(hour, minute, second);

    return 0;
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
