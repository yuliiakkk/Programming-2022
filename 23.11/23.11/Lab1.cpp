#include <iostream>
#include <string>
#include <map>
#include <vector>


using namespace std;

/*#define pis pair<int, string>
#define psi pair<string, int>
#define mp(a, b) make_pair(a, b)*/

enum color
{
    BLACK,
    RED,
    VIOLET,
    ORANGE,
    GREEN,
    YELLOW,
    WHIE,
    BLUE
};

/*const map<int, string> COLOR_NAMES = map<int, string>{
    mp(0, "black"),
    mp(1, "red"),
    mp(2, "violet"),
    mp(3, "orange"),
    mp(4, "green"),
    mp(5, "yellow"),
    mp(6, "white"),
    mp(7, "blue")
};

const map<string, int> COLOR_NUMBERS = map<string, int>{
    mp("black", 0),
    mp("red", 1),
    mp("violet", 2),
    mp("orange", 3),
    mp("green", 4),
    mp("yellow", 5),
    mp("white", 6),
    mp("blue", 7)
};

void rand_colors(color* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = color(rand() % 8);
    }
}

void print_colors(color* A, int n)
{
    for (int i = 0; i < n; i++) 
    {
        cout << "Color is " << COLOR_NAMES.find(A[i])->second << endl;
    }
}

void print_colors(vector<color> A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout << "Color is " << COLOR_NAMES.find(A[i])->second << endl;
    }
}*/

/*int main()
{
    int n;
    int m;
    cout << "Enter n: " << endl;
    cin >> n;
    color* A = new color[n];
    rand_colors(A, n);
    print_colors(A, n);

    
    cin >> m;
    cout << "Enter m colors: " << endl;

    vector<color> B;
    string colInput;
    for (int i = 0; i < m; ++i) {
        cin >> colInput;
        while (!COLOR_NUMBERS.contains(colInput)) {
            cout << "Invalid input, try again:" << endl;
            cin >> colInput;
        }

        color col = color(COLOR_NUMBERS.find(colInput)->second);
        bool colorExistsInA = false;
        for (int j = 0; j < n; ++j) {
            if (A[j] == col) {
                colorExistsInA = true;
                break;
            }
        }

        if (!colorExistsInA) {
            B.push_back(col);
        }
    }
    
    print_colors(B);
    return 0;
}*/

struct Colorball
{
    double r;
    color ballcolor;

    Colorball(color c, double r) : r(r), ballcolor(c) {}

};


int main()
{
    int  n;
    double r;
    color ballcolor;
    vector<Colorball> C;
    cout << "Ener information about 5 balls:" << endl;
    for (int i = 0; i <5; i++) {
        cin >> r >> n;

        C.push_back(Colorball(color(n), r));

    }
    Colorball maxcolor=C[0];
    for (int i = 1; i < 5; i++)
    {
        if (maxcolor(C[i].r, maxcolor.r == C[i].r)
        {
            maxcolor=C[i];
        }
    }
    cout<<"Max color is "<<maxcolor;
 }



