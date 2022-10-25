// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

const double epsilon = 10e-5;

double count_actual_sum(double x) {
    return pow(1 + x, -2.5);
}

double get_si(double x, int i) {
    double si = pow(-x, i);
    for (int k = i; k >= 1; k--) {
        si *= (5 + 2 * (k - 1)) / (2 + 2 * (k - 1));
    }


    return si;
}

double count_sum(double x) {
    double S = 0;
    double si = 1;
    int i = 0;
    while (abs(si) > epsilon) {
        S += si;
        i++;
        si = get_si(x, i);
    }

    return S;
}


    
   


   

int main()
{
    double a, h;
    cout << "Enter a and h: "<< endl;
    
    cin >> a >> h;
    

    double S, y, p;

    cout << setprecision(3) << fixed << "|   X   |   S   |   y   | Pohybka |" << endl;
    cout << "___________________________________" << endl;

    for (int i = 0; i < 10; i++) {
        double x = a + i * h;

        y = count_actual_sum(x);
        S = count_sum(x);
        p = abs((S - y) / y) * 100;

        cout << "| " << x << " | " << S << " | " << y << " | " << p << "% |" << endl;
        cout << "___________________________________" << endl;
    }




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
