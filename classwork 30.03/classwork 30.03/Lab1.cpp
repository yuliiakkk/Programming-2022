#include<algorithm>
#include <string>
#include <iostream>
#include<sstream>
#include <iomanip>
#include<fstream>

using namespace std;

string Tab(double(*f)(double), double a, double b, int n)
{
    ostringstream os;
    os << '|' << setw(5) << 'x' << setw(5) << '|' << setw(5) << "sinx" << setw(5) << '|' << endl;
    int h = (b - a) / n;
    for (a; a < b; a + h)
    {
        os << '|' << setw(5) << a << setw(5) << '|' << setw(5) << f(a) << setw(5) << endl;
    }

    return os.str();    
}

double f1(double x)
{
    double result;
    result = pow(x, 3) + pow(x, 2) - 8 * x + 9;
    return result;
}

int main()
{
    double a;
    cin >> a;
    double b;
    cin >> b;

    int n;
    cin >> n;

    cout << "Enter line a,b and step n" << endl;
    string st, st1, st2;
    st = Tab(sin, a, b, n);
    ofstream file1("result.txt");
    file1 << "sin x" << endl << st;


    st1 = Tab(f1, a, b, n);
    file1 << " pow(x, 3) + pow(x, 2) - 8 * x + 9" << endl << st1;


    st2 = Tab([](double x))
        {
            return sin(x) + 8 * tan(x) - 24 * pow(x, 2);
        }
    file1<< "sinx+8tgx-24x^2" << endl << st2;
    
    return 0;
}

