#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <ratio>

using namespace std;
using namespace chrono;

template<typename T>
class Product {
private:
    T item;
   /* int creation_date;*/
    system_clock::time_point creation_date;
    int expiration_date;
public:

    Product() :
        item(T()),
        expiration_date(0)
    {
    }

    Product(T item, system_clock::time_point creation_date, int expiration_date) :
        item(item),
        creation_date(creation_date),
        expiration_date(expiration_date)
    {
    }

   /* int getExpirationDate()
    {
        return expiration_date;
    }*/

   /* system_clock::time_point getExpirationDate() const
    {
        system_clock::time_point expiration_date = creation_date + hours(24 * expiration_date);
        return expiration_date;
    }*/
    system_clock::time_point::duration getExpirationDate() const // changed return type
    {
        system_clock::time_point expiration_date = creation_date + hours(24 * expiration_date);
        return system_clock::to_time_t(expiration_date); // return duration
    }


    friend ostream& operator<<(ostream& os, const Product& p)
    {
        os << p.item << " (" << p.getExpirationDate() << " days)";
        return os;
    }

    friend istream& operator>>(istream& is, Product& p)
    {
        is >> p.item >> p.expiration_date;
        p.creation_date = system_clock::now(); 
        return is;
    }
};

template<typename T>
struct Milk {
    string name;
    T fat;
    Milk() :
        fat(T()),
        name("")
    {
    }

    Milk(const string& name, const T& fat) :
        name(name),
        fat(fat)
    {
    }

    friend ostream& operator<<(ostream& os, const Milk& milk)
    {
        os << milk.name << " Milk (" << milk.fat << "% of fat)";
        return os;
    }

    friend istream& operator>>(istream& is, Milk& milk) 
    {
        is >> milk.name >> milk.fat;
        return is;
    }
};

int main()
{
    const int numberOfProducts = 3;

    Product<string> stringProducts[numberOfProducts] =
    {
        Product<string>("Banana", system_clock::now(), 7),
        Product<string>("Apple", system_clock::now(), 5),
        Product<string>("Orange", system_clock::now(), 10)
    };

    cout << "String products:" << endl;
    for (int i = 0; i < numberOfProducts; i++)
    {
        cout << stringProducts[i] << " Expires on " << system_clock::to_time_t(system_clock::time_point(stringProducts[i].getExpirationDate())) << endl;
    }
   /* const int numberOfProducts = 3;

    Product<string> stringProducts[numberOfProducts] =
    {
        Product<string>("Banana", system_clock::now(), 7),
        Product<string>("Apple", system_clock::now(), 5),
        Product<string>("Orange", system_clock::now(), 10)
    };

    cout << "String products:" << endl;
    for (int i = 0; i < numberOfProducts; i++)
    {
        cout << stringProducts[i] << " Expires on " << system_clock::to_time_t(stringProducts[i].getExpirationDate() + seconds(0)) << endl;
    }*/

    const int numberOfMilkProducts = 2;

    Product<Milk<int>> milkProducts[numberOfMilkProducts] =
    {
        Product<Milk<int>>(Milk<int>{"Whole", 3}, system_clock::now(), 7),
        Product<Milk<int>>(Milk<int>{"Skimmed", 0}, system_clock::now(), 5)
    };

   /* cout << "Milk products:" << endl;
    for (int i = 0; i < numberOfMilkProducts; i++)
    {
        auto expirationTime = milkProducts[i].getExpirationDate();
        auto expirationTimeT = system_clock::to_time_t(time_point_cast<system_clock::duration>(expirationTime));
        cout << milkProducts[i] << " Expires on " << ctime(&expirationTimeT) << endl;
    }*/

    cout << "Milk products:" << endl;
    for (int i = 0; i < numberOfMilkProducts; i++)
    {
        cout << milkProducts[i] << " Expires on " << milkProducts[i].getExpirationDate() << endl;
    }



}