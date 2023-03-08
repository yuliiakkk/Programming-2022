#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Phone 
{
protected:
    string name_;
    string brand_;
    double price_;
public:
    double getPrice() const
    {
        return price_;
    }

    /*virtual void print() = 0;*/

    virtual void input(istream& in)
    {
        in >> name_ >> brand_ >> price_;
    }

    virtual void output(ostream& on)
    {
        on << "Name: " << name_ << "Brand: " << brand_ << "Price" << price_;;
    }

    friend ostream& operator<<(ostream& os, Phone& file2)
    {
        file2.output(os);

        return os;
    }

    friend istream& operator>>(istream& in, Phone& file2)
    {
        file2.input(in);
        return in;
    }
};

class MobilePhone : public Phone 
{
private:
    string color;
    int memory;
public:
    void input(istream& in)
    {
        Phone::input(in);
        in >> color >> memory;
    }

    void output(ostream& os)
    {
        Phone::output(os);
        os << "Color: " << color << "Memory: " << memory;

    }
};

class RadioPhone : public Phone {
private:
    int radius;
    bool hasAutoAnswer;
public:
    void input(istream& in)
    {
        Phone::input(in);
        in >> radius >> hasAutoAnswer;
    }

    void output(ostream& os)
    {
        Phone::output(os);
        os << "Radius: " << radius << "Has auto-answear or not: " << hasAutoAnswer;

    }

};

bool compareByPrice(Phone* p1, Phone* p2) {
    return p1->getPrice() < p2->getPrice();
}


    int main()
    {

        ifstream file1("file1.txt");
        vector<Phone*> phones;

        if (file1.is_open())
        {
            while (!file1.eof())
            {
                char type;
                file1 >> type;

                if (type == 'M') {
                    MobilePhone* mp = new MobilePhone();
                    file1 >> *mp;
                    phones.push_back(mp);
                }
                else if (type == 'R') {
                    RadioPhone* rp = new RadioPhone();
                    file1 >> *rp;
                    phones.push_back(rp);
                }
            }
            file1.close();
        }


        ifstream file2("file2.txt");

        if (file2.is_open())
        {
            while (!file2.eof())
            {
                char type;
                file2 >> type;

                if (type == 'M') {
                    MobilePhone* mp = new MobilePhone();
                    file2 >> *mp;
                    phones.push_back(mp);
                }
                else if (type == 'R') {
                    RadioPhone* rp = new RadioPhone();
                    file2 >> *rp;
                    phones.push_back(rp);
                }
            }
            file2.close();
        }

        sort(phones.begin(), phones.end(), compareByPrice);


        ofstream output("output.txt");

        if (output.is_open())
        {
            double total_price = 0.0;

            for (auto phone : phones)
            {
                output << *phone << endl;
                total_price += phone->getPrice();
            }

            output << "Total price: " << total_price << endl;
            output.close();
        }
        return 0;
    }

    