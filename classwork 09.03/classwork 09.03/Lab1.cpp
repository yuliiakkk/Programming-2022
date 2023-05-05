#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class electricalAppliance
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

    string getName() const
    {
        return name_;
    }

    string getBrand() const
    {
        return brand_;
    }

    virtual void input(istream& in)
    {
        in >> name_ >> brand_ >> price_ ;
    }

    virtual void output(ostream& on)
    {
        on << "Name: " << name_ << "Brand: " << brand_ << "Price" << price_;;
    }

    friend ostream& operator<<(ostream& os, electricalAppliance& file1)
    {
        file1.output(os);

        return os;
    }

    friend istream& operator>>(istream& in, electricalAppliance& file1)
    {
        file1.input(in);
        return in;
    }

};

class vacuumCleaner : public electricalAppliance
{
private:
    string color;
    int capacity;
public:
    void input(istream& in)
    {
        electricalAppliance::input(in);
        in >> color >> capacity;
    }

    void output(ostream& os)
    {
        electricalAppliance::output(os);
        os << "Color: " << color << "Capacity: " << capacity;

    }

};

class washingMashine : public electricalAppliance
{
private:
    int prog_numb;
    int volume;
public:

    void input(istream& in)
    {
        electricalAppliance::input(in);
        in >> prog_numb >> volume;
    }

    void output(ostream& os)
    {
        electricalAppliance::output(os);
        os << "Number of programs: " << prog_numb << "Volume: " << volume;

    }
};

bool compareByName(electricalAppliance* p1, electricalAppliance* p2)
{
    return p1->getName() < p2->getName();
}

double getTotalPriceByBrand(vector<electricalAppliance*> appliances, string brand)
{
    double total = 0;
    for (electricalAppliance* appliance : appliances)
    {
        if (appliance->getBrand() == brand)
        {
            total += appliance->getPrice();
        }
    }
    return total;
}

int main()
{
    vector<electricalAppliance*> electricalAppliances;
    ifstream file1("file1.txt");

   

    if (file1.is_open())
    {
        while (!file1.eof())
        {
            string type;
            file1 >> type;

            if (type == "VC")
            {
                vacuumCleaner* vc = new vacuumCleaner();
                file1 >> *vc;
                electricalAppliances.push_back(vc);
            }
            else if (type == "WM")
            {
                washingMashine* wm = new washingMashine();
                file1 >> *wm;
                electricalAppliances.push_back(wm);
            }
        }
        file1.close();
    }

    sort(electricalAppliances.begin(), electricalAppliances.end(), compareByName);
    
    ofstream file2("file2.txt");
    for (auto appliance : electricalAppliances) 
    {
        file2 << *appliance << endl;
    }
    file2.close();

    string brand;
    cin >> brand;

    ofstream file3("file3.txt");
    for (auto appliance : electricalAppliances)
    {
        file3 << appliance->getName() << endl;
    }
    double totalPrice = getTotalPriceByBrand(electricalAppliances, brand);
    file3 << "Total price for " << brand << ": " << totalPrice << endl;
    file3.close();
    

    return 0;
}


