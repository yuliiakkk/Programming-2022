#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <vector>



using namespace std;

class Abonent
{
private:
	string fullName;
	string adress;
	set<string> phoneNumbers;

public:
	Abonent(string name, string address) :
		fullName(name), 
		adress(address) 
	{
	}

	Abonent() :
		fullName(" "),
		adress(" ")
	{	
	}

	void addPhoneNumber(string phoneNumber)
	{
		phoneNumbers.insert(phoneNumber);
	}

	const string& getFullName() const
	{
		return fullName;
	}

	const string& getAdress() const
	{
		return adress;
	}

	set<string>& getPhoneNumbers()
	{
		return phoneNumbers;
	}

	bool hasPhoneNumber(string number) const
	{
		return phoneNumbers.contains(number);
	}

	bool operator<(const Abonent& other) const
	{
		return fullName < other.fullName;
	}
};

bool abonenEntryComparator(const pair<string, Abonent>& left, const pair<string, Abonent>& right)
{
	return left.first < right.first;
}


int main()
{
	ifstream inFile("phonebook.txt");
	if (!inFile)
	{
		cerr << "Error: could not open input file" << endl;
		return 1;
	}

	map<string, Abonent> phoneBook;

	string fullName;
	string adress;
	string phoneNumbers;
	string phoneNumber;
	Abonent abonent;

	

	while (!inFile.eof())
	{
		getline(inFile, fullName);
		getline(inFile, adress);
		getline(inFile, phoneNumbers);

		abonent = Abonent(fullName, adress);
		for (int i = 0; i < phoneNumbers.size(); i++)
		{
			
			if (phoneNumbers[i] != ' ')
			{
				phoneNumber += phoneNumbers[i];
			}
			else
			{
				abonent.addPhoneNumber(phoneNumber);
				phoneNumber = "";
			}
		}
		abonent.addPhoneNumber(phoneNumber);
		phoneBook.insert(make_pair(fullName, abonent));
	}


	for (auto& [name, abonent] : phoneBook)
	{
		vector<string> numbersToReplace;
		auto& phoneNumbersSet = abonent.getPhoneNumbers();
		for (auto phoneNumber : phoneNumbersSet)
		{
			if (phoneNumber[0] == '8')
				numbersToReplace.emplace_back(phoneNumber);
		}

		for (int i = 0; i < numbersToReplace.size(); ++i)
		{
			phoneNumbersSet.erase(numbersToReplace[i]);
			phoneNumbersSet.insert(numbersToReplace[i].substr(1));
		}
	}

	// Sort the phonebook by name
	vector<pair<string, Abonent>> sortedPhonebook(phoneBook.begin(), phoneBook.end());
	sort(sortedPhonebook.begin(), sortedPhonebook.end(), abonenEntryComparator);

	ofstream outFile1("file1.txt");
	if (!outFile1)
	{
		cerr << "Error: could not open output file1" << endl;
		return 1;
	}

	for (auto& [fullName, abonent] : sortedPhonebook)
	{
		outFile1 << abonent.getFullName() << " " << abonent.getAdress() << " ";

		auto& phoneNumbers = abonent.getPhoneNumbers();
		string phoneNumbersString;
		for (auto phoneNumber : phoneNumbers)
		{
			phoneNumbersString += phoneNumber + " ";
		}

		outFile1 << phoneNumbersString << endl;
	}

	outFile1.close();

	ofstream outFile2("file2.txt");
	if (!outFile2)
	{
		cerr << "Error: could not open output file2" << endl;
		return 1;
	}

	string searchPhoneNumber;
	std::cout << "Enter phone number to search: ";
	std::cin >> searchPhoneNumber;

	bool foundAbonent = false;
	for (auto& [fullName, abonent] : sortedPhonebook)
	{
		if (abonent.hasPhoneNumber(searchPhoneNumber))
		{
			foundAbonent = true;

			outFile2 << abonent.getFullName() << " " << abonent.getAdress() << " ";

			auto& phoneNumbers = abonent.getPhoneNumbers();
			string phoneNumbersString;
			for (auto phoneNumber : phoneNumbers)
			{
				phoneNumbersString += phoneNumber + " ";
			}

			outFile2 << phoneNumbersString << endl;
		}
	}

	if (!foundAbonent)
	{
		outFile2 << "No abonent found with phone number " << searchPhoneNumber << endl;
	}

	outFile2.close();
}

