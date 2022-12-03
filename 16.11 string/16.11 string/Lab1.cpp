

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text = "";
    cout << "Enter text: " << endl;
    char inputCharacter ='\0';

    bool isParenthesisOpened = false;
    while (inputCharacter != '.') 
    {
        cin >> inputCharacter;

        if (inputCharacter == '(')
        {
            isParenthesisOpened = true;
        }
        else if (inputCharacter == ')')
        {
            isParenthesisOpened = false;
        }
        else if (!isParenthesisOpened)
        {
            text += inputCharacter;
        }
    }

    cout << text;
    return 0;
}

