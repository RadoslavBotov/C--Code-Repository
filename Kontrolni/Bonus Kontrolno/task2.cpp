#include <iostream>
#include <cstring>
using namespace std;

bool sameLetters(char *smalls, char *capitals)
{
    int sizeSmalls = strlen(smalls);
    int sizeCapitals = strlen(capitals);

    if (sizeSmalls != sizeCapitals)
        return false;

    for (int i = 0; i < sizeSmalls; i++)
        if ((capitals[i] - 'A' + 'a') != smalls[i])
            return false;

    return true;
}

void readStr(char *str, int size) // е низът „abABcC“, но не и низът „aBACbc“.
{
    char smalls[255];
    char capitals[255];
    int j = 0, t = 0;

    for (int i = 0; i < size; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            smalls[j] = str[i];
            j++;
        }

        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            capitals[t] = str[i];
            t++;
        }
    }

    cout << "Smalls  : " << smalls << endl;
    cout << "Capitals: " << capitals << endl;

    if (sameLetters(smalls, capitals))
        cout << "Same letters!";
    else
        cout << "Different letters.";
}

int main()
{
    char *textString = new char[255];

    cout << "> String: ";
    cin.getline(textString, 255);

    readStr(textString, strlen(textString));

    delete[] textString;

    return 0;
}