#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer
{
private:
    string _name;
    string _address;
    string _phoneNumber;
public:
    Customer() 
        : _name(""), _address(""), _phoneNumber("")
    {
    }

    Customer(string name, string address, string phoneNumber) 
        : _name(name), _address(address), _phoneNumber(phoneNumber)
    {
    }

    string get_name() const
    {
        return _name;
    }

    string get_addres() const
    {
        return _address;
    }

    string get_phoneNumber() const
    {
        return _phoneNumber;
    }

    friend ostream& operator<<(ostream& os, const Customer& customer)
    {
        os << "Name: " << customer._name << endl;
        os << "Address: " << customer._address << endl;
        os << "Phone number: " << customer._phoneNumber << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Customer& customer)
    {
        cout << "Enter name: ";
        getline(is, customer._name);

        cout << "Enter address: ";
        getline(is, customer._address);

        cout << "Enter phone number: ";
        getline(is, customer._phoneNumber);

        return is;
    }
};

class BankAccount
{
private:
    Customer _customer;
    int _accountNumber;
    double _balance;

public:
  
    BankAccount() 
        : _customer(Customer()), _accountNumber(0), _balance(0)
    {
    }

    BankAccount(Customer customer, int accountNumber, double balance) 
        : _customer(customer), _accountNumber(accountNumber), _balance(balance)
    {
    }
     
    Customer get_customer() const
    {
        return _customer;
    }

    int get_accountNumber() const
    {
        return _accountNumber;
    }

    double get_balance() const
    {
        return _balance;
    }

    void deposit(double amount) 
    {
        _balance += amount;
    }

    void withdraw(double amount)
    {
        if (_balance < amount) 
        {
            cout << "Insufficient balance." << endl;
            return;
        }

        _balance -= amount;
    }

    friend istream& operator>>(istream& is, BankAccount& bankAccount) {
        cout << "Enter client information: " << endl;
        is >> bankAccount._customer;
        cout << "Enter account number: ";
        is >> bankAccount._accountNumber;
        cout << "Enter initial balance: ";
        is >> bankAccount._balance;
        return is;
    }

    friend ostream& operator<<(ostream& os, const BankAccount& account)
    {
        os << "Account Number: " << account._accountNumber << endl
            << "Balance: " << account._balance << endl
            << "Client Information: " << endl
            << account._customer;
        return os;
    }
};

int main()
{
    vector<BankAccount> accounts(10);
    BankAccount account;

    for (int i = 0; i < accounts.size(); i++)
    {
        cout << "Enter information for account " << i + 1 << ":" << endl;
        cin >> accounts[i];

        string temp;
        getline(cin, temp);
    }

    string nameToSearch;
    cout << "Enter customer name to search: ";
    getline(cin, nameToSearch);

    bool foundByName = false;
    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i].get_customer().get_name() == nameToSearch)
        {
            cout << "Account found by name:" << endl << accounts[i] << endl;
            foundByName = true;
        }
    }

    if (!foundByName)
    {
        cout << "Account did not find by name." << endl;
    }

    string addressToSearch;
    cout << "Enter customer address to search: ";
    getline(cin , addressToSearch);

    bool foundByAddress = false;
    for (int i = 0; i < accounts.size(); i++)
    {
        if (accounts[i].get_customer().get_addres() == addressToSearch)
        {
            cout << "Account found by address:" << endl << accounts[i] << endl;
            foundByAddress = true;
        }
    }

    if (!foundByAddress)
    {
        cout << "Account did not find by address." << endl;
    }

    return 0;
}

