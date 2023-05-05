
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person 
{
    string name;
    string address;
};

template <typename T>//sorting with bubble sort algorithm
void sortArray(T arr[], int size, bool (*compare)(T, T))
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = i + 1; j < size; j++) 
        {
            if (compare(arr[j], arr[i]))
            {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

bool intComperator(int numb1, int numb2) 
{
    return numb1 < numb2;
}

bool stringComperator(string str1, string str2) 
{
    return str1 < str2;
}

bool personComperator(Person pers1, Person pers2) 
{
    return pers1.name < pers2.name;
}

int main() {
    int intArr[] = { 5, 1, 0, 9, 2, 7 };
    sortArray(intArr, 4, intComperator);
    for (int i = 0; i < 6; i++) {
        cout << intArr[i] << " ";
    }
    cout << endl;

    string strArr[] = { "zebra", "giraff", "hippo", "lion" };
    sortArray(strArr, 4, stringComperator);
    for (int i = 0; i < 4; i++) {
        cout << strArr[i] << " ";
    }
    cout << endl;

    Person personArr[] = {
        {"John", "123 Main St"},
        {"Mary", "456 Oak Ave"},
        {"Alex", "789 Pine Rd"},
    };
    sortArray(personArr, 3, personComperator);
    for (int i = 0; i < 3; i++) {
        cout << personArr[i].name << " " << personArr[i].address << endl;
    }
    return 0;
}

