#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>
#include <string>


using namespace std;

struct GasBill {
    string surname;
    int num_people;
    double amount_paid;
};

struct WaterBill {
    string surname;
    int meter_reading;
    double volume_paid;
    double amount_paid;
};

bool gas_comperator(const GasBill& a, const GasBill& b) 
{
    return a.num_people > b.num_people;
}

bool water_comperator(const WaterBill& a, const WaterBill& b) 
{
    return a.surname < b.surname;
}

bool water_payment_comperator(const WaterBill& a, const WaterBill& b) 
{
    return a.amount_paid > b.amount_paid;
}

int main() {
    try {
        deque<GasBill> gas_bills;
        deque<WaterBill> water_bills;

        ifstream infile("bills.txt");
        if (!infile.is_open()) 
        {
            throw runtime_error("Could not open file.");
        }
      

        while (!infile.fail())
        {
            string type;
            infile >> type;
            if (type == "G")
            {
                GasBill bill;
                infile >> bill.surname >> bill.num_people >> bill.amount_paid;
                gas_bills.push_back(bill);
            }
            else if (type == "W")
            {
                WaterBill bill;
                infile >> bill.surname >> bill.meter_reading >> bill.volume_paid >> bill.amount_paid;
                water_bills.push_back(bill);
            }
            else
            {
                if (!infile.fail())
                {
                    throw runtime_error("Invalid bill type.");
                }
            }
        }
        infile.close();

        sort(gas_bills.begin(), gas_bills.end(), gas_comperator);
        sort(water_bills.begin(), water_bills.end(), water_comperator);

        ofstream gasfile("gas_bills.txt");
        if (!gasfile.is_open()) 
        {
            throw runtime_error("Could not open file.");
        }
        for (auto& bill : gas_bills)
        {
            gasfile << bill.surname << " " << bill.num_people << " " << bill.amount_paid << endl;
        }
        gasfile.close();

        ofstream waterfile("water_bills.txt");
        if (!waterfile.is_open()) {
            throw runtime_error("Could not open file.");
        }
        for (auto& bill : water_bills) 
        {
            waterfile << bill.surname << " " << bill.meter_reading << " " << bill.volume_paid << " " << bill.amount_paid << endl;
        }
        waterfile.close();

        sort(water_bills.begin(), water_bills.end(), water_payment_comperator);

        ofstream top5file("top5_water_bills.txt");
        if (!top5file.is_open()) 
        {
            throw runtime_error("Could not open file.");
        }
        for (int i = 0; i < min(5, (int)water_bills.size()); i++)
        {
            top5file << water_bills[i].surname << " " << water_bills[i].amount_paid << endl;
        }
        top5file.close();
    }

    catch (const exception& e) 
    {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}
