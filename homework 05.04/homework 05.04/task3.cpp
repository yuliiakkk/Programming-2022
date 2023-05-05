#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

string translateToUkrainian(string name) {
    return "З днем народження, " + name + "!";
}

string translateToEnglish(string name) {
    return "Happy Birthday, " + name + "!";
}

string translateToPolish(string name) {
    return "Wszystkiego najlepszego z okazji urodzin, " + name + "!";
}

string greeting(string (*translator)(string), string name) {
    return (*translator)(name);
}

int main() {
    string name;
    string language;
    string (*translator)(string);

    try {
        cout << "Enter the name of the birthday person: ";
        getline(cin, name);

        cout << "Enter the language for the greeting (ukr, eng, pln): ";
        cin >> language;

        if (language == "ukr") 
        {
            translator = &translateToUkrainian;
        }
        else if (language == "eng") 
        {
            translator = &translateToEnglish;
        }
        else if (language == "pln") 
        {
            translator = &translateToPolish;
        }
        else 
        {
            throw invalid_argument("An incorrect language was selected. Exiting program.");
        }

        string message = greeting(translator, name);

        ofstream outfile("greeting.txt");
        if (!outfile) 
        {
            throw runtime_error("Could not open file.");
        }
        outfile << message;
        outfile.close();
        if (outfile.fail()) 
        {
            throw runtime_error("Could not write to file.");
        }

        cout << "Greeting has been written to file greeting.txt." << endl;

    }
    catch (const exception& e) 
    {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
