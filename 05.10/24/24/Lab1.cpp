// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <numbers>

using namespace std;

int sum_digits(int x) {
    return (x / 100) + ((x / 10) % 10) + (x % 10);
}

bool assert_input(int x) {
    if (x < 100 || x > 999) {
        cout << "Entered number is not a three-digit number!\n";

        return false;
    }

    return true;
}

int main()
{
    int x;
    cout << "Enter a three-digit number: ";
    cin >> x;

    if (!assert_input(x))
        return 0;

    cout << endl << "Sum of digits: " << sum_digits(x);

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
