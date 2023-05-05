#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

template<typename T>
void double_odd_positions(vector<T>& arr)
{
    if constexpr (!is_same<T, int>::value && !is_same<T, string>::value)
        throw invalid_argument("Vector type must be either int or string.");

    if (arr.empty())
    {
        throw invalid_argument("Input vector is empty.");
    }

    vector<T> resultArr;
    for (int i = 0; i < arr.size(); ++i)
    {
        resultArr.emplace_back(arr[i]);
        if (i % 2 == 0)
            resultArr.emplace_back(arr[i]);
    }

    arr.swap(resultArr);
}

int main() {
    vector<int> intArray{ 1, 5, 2, 5, 9, 4, 3, 7 };
    try {
        double_odd_positions(intArray);
        for (int i = 0; i < intArray.size(); i++)
        {
            cout << intArray[i] << " ";
        }
        cout << endl;
    }
    catch (exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    vector<string> stringArray{ "apple", "orange", "banana", "coconut", "pineapple" };
    try 
    {
        double_odd_positions(stringArray);
        for (int i = 0; i < stringArray.size(); i++)
        {
            cout << stringArray[i] << " ";
        }
        cout << endl;
    }
    catch (exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    //(for exeption)
    vector<double> emptyArray;
    try 
    {
        double_odd_positions(emptyArray);
        for (int i = 0; i < emptyArray.size(); i++)
        {
            cout << emptyArray[i] << " ";
        }
        cout << endl;
    }
    catch (exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
