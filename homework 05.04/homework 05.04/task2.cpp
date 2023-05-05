#include <iostream>
#include <fstream>
#include <string>

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

    cout << "Enter the name of the birthday person: ";
    getline(cin, name);

    cout << "Enter the language for the greeting (ukr, eng, pln): ";
    cin >> language;

    if (language == "ukr") {
        translator = &translateToUkrainian;
    }
    else if (language == "eng") {
        translator = &translateToEnglish;
    }
    else if (language == "pln") {
        translator = &translateToPolish;
    }
    else {
        cout << "An incorrect language was selected. Exiting program." << endl;
        return 0;
    }

    string message = greeting(translator, name);
    ofstream outfile("greeting.txt");
    outfile << message;
    outfile.close();

    cout << "Greeting has been written to file greeting.txt." << endl;

    return 0;
}
