// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*#include <iostream>
#include <numbers>

using namespace std;

int main()
{
    double a[100];
    int n;
    cout << " Enter numbers "<<endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a [i];
    }
    {
        double s = a[0];
        double b[100];
        for (int k = 0; k < n; k++)

        {
            b[k] = a[k] / (1 + s * s);
            s = s + a[k + 1];
            cout << "b " << b[k];
        }
        
    }


    return 0;
}*/

/*#include<iostream>
#include<numbers>

using namespace std;

int main()
{
    int k;
    for (int i = 0; i < k; i++)
    {
        (k % i == 0);
    }

}*/


/*#include<iostream>
#include<numbers>

using namespace std;

int main() {
    double a[100];
    cout << "Enter m: " << endl;
    int m;
    cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
       
            bool s = true;
            for (int i = 0; i < m - 1; i++)
            {
                if (a[i] < a[i + 1])
           { cout << " Ne spadna ";
             s = false;
             break;
            }
        
        if (s == true);
            cout << "Spadna ";
        }
        

        return 0;
}*/

 #include<iostream>
 #include<numbers>

using namespace std;

int main() {
    int size;
    cout << "input size: " << endl;
    cin >> size;
    int array[100];
    for (int i = 0; i > 0; i++)
    {
        cout << "Input x" <<i<<endl;
        cin >> array[i];
    }
    int min = array[0];
    int index = 0;
    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
                index = i;
        }
    }
    cout << "min number= " << min << "index= " << index;
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
