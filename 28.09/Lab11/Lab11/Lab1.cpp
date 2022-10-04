// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <numbers>

using namespace std;

double circle_area(double r) {
    return numbers::pi * pow(r, 2);
}

double circle_length(double r) {
    return 2 * numbers::pi * r;
}

double sphere_volume(double r) {
    return (4 * numbers::pi * pow(r, 3)) / 3;
}


int main()
{
    double r;
    cout << "Enter a radius: ";
    cin >> r;

    cout << endl << "Circle area: " << circle_area(r) << endl;
    cout << "Circle length: " << circle_length(r) << endl;
    cout << "Sphere volume: " << sphere_volume(r);

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
