#include <iostream>
#include <cstring>

char **allocateMatrixMemmory(int dictionarySize)
{
    char **matrix = new char *[dictionarySize];

    for (int i = 0; i < dictionarySize; i++)
        matrix[i] = new char[101];

    return matrix;
}

void deleteMatrixMemmory(char **matrix, int dictionarySize)
{
    for (int i = 0; i < dictionarySize; i++)
        delete[] matrix[i];

    delete[] matrix;
}

int inputTextSizeTask0(int textSize)
{
    do
    {
        std::cout << "> Text size: ";
        std::cin >> textSize;
    } while (textSize < 0 || textSize > 1024);

    return textSize;
}

void inputTextTask0(char *text, int textSize)
{
    std::cin.get();
    std::cout << "> Text:" << std::endl;
    for (int i = 0; i < textSize; i++)
        std::cin.get(text[i]);
    text[textSize] = '\0';
}

int inputDictionarySizeTask0(int dictionarySize)
{
    do
    {
        std::cout << "\n> Dictionary size: ";
        std::cin >> dictionarySize;
    } while (dictionarySize < 0 || dictionarySize > 128);

    return dictionarySize;
}

void inputDictionaryTask0(char **dictionary, int dictionarySize)
{
    std::cin.get();
    if (dictionarySize != 0)
    {
        std::cout << "> Dictionary:" << std::endl;
        for (int i = 0; i < dictionarySize; i++)
            std::cin.getline(dictionary[i], 100);
    }
}

int shouldAddSpace(char *text, char symbol)
{
    switch (symbol)
    {
    case '.':
        return 0;
        break;
    case ',':
        return 0;
        break;
    case '?':
        return 0;
        break;
    case '!':
        return 0;
        break;
    case ';':
        return 0;
        break;
    case ':':
        return 0;
        break;
    case '"':
        return 0;
        break;
    case ')':
        return 0;
        break;
    case ']':
        return 0;
        break;
    case '}':
        return 0;
        break;
    case '>':
        return 0;
        break;
    case '(':
        return 1;
        break;
    case '[':
        return 1;
        break;
    case '{':
        return 1;
        break;
    case '<':
        return 1;
        break;
    case '-':
        return 2;
        break;
    case '+':
        return 2;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '=':
        return 2;
        break;
    case '^':
        return 2;
        break;
    default:
        return 3;
        break;
    }
}

void removeElementAt(char *text, int &size, int index)
{
    size--;
    for (int i = index; i <= size; i++)
        text[i] = text[i + 1];
}

void addSpaceAt(char *arr, int &textSize, int index, char symbol = ' ')
{
    textSize++;
    for (int i = textSize; i > index; i--)
        arr[i] = arr[i - 1];
    arr[index] = symbol;
}

char *getWrongWord(char *wrongWord, char *word)
{
    int i = 0;
    wrongWord = new char[strlen(word) + 1];

    while (word[i] != '-')
    {
        wrongWord[i] = word[i];
        i++;
    }
    wrongWord[i] = '\0';
    return wrongWord;
}

void dictionaryCorrections(char *word, char *text, char **dictionary, int &textSize, int dictionarySize)
{
    for (int i = 0; i < dictionarySize; i++)
    {
        char *wrongWord = getWrongWord(wrongWord, dictionary[i]);
        int wrongWordSize = strlen(wrongWord);

        char *correctWord = strchr(dictionary[i], '-') + 1;
        int correctWordSize = strlen(correctWord);

        if (!strcmp(word, wrongWord))
        {
            // if (wrongWordSize < correctWordSize)
            //     for (int j = 0; j < correctWordSize - wrongWordSize; j++)
            //         addSpaceAt(text, textSize, i);

            // if (wrongWordSize > correctWordSize)
            //     for (int j = 0; j < wrongWordSize - correctWordSize; j++)
            //         removeElementAt(text, textSize, i);

            if (wrongWordSize == correctWordSize)
                strncpy(text - strlen(word), correctWord, correctWordSize);
            // textSize += correctWordSize - wrongWordSize;
        }

        delete[] wrongWord;
    }
}

void autoCorrect(char *text, char **dictionary, int textSize, int dictionarySize)
{
    for (int i = 0; i < textSize; i++) // punctuation
    {
        switch (shouldAddSpace(text, text[i]))
        {
        case 0:
            if (text[i + 1] != ' ')
                addSpaceAt(text, textSize, i + 1);
            break;
        case 1:
            if (text[i - 1] != ' ')
                addSpaceAt(text, textSize, i);
            break;
        case 2:
            if (text[i + 1] != ' ')
                addSpaceAt(text, textSize, i + 1);
            if (text[i - 1] != ' ')
                addSpaceAt(text, textSize, i);
            break;
        }
    }

    int t = 0;
    int index = 0;
    char word[100];

    while (*text) // get every word of text
    {
        bool a = *text >= 'a' && *text <= 'z';
        bool b = *text >= 'A' && *text <= 'Z';
        bool c = *text >= '0' && *text <= '9';
        if (a || b || c)
        {
            word[t] = *text;
            t++;
        }
        else
        {
            word[t] = '\0';

            
            if (*word != '\0')
                dictionaryCorrections(word, text, dictionary, textSize, dictionarySize);

            word[0] = '\0';
            t = 0;
        }
        text++;
        index++;
    }
    dictionaryCorrections(word, text, dictionary, textSize, dictionarySize);
    std::cout << word << std::endl;

    std::cout << "\nRedacted text:\n"
              << text << std::endl;
}

int main()
{
    const unsigned MAX_LEN = 1024;
    char buffer[MAX_LEN];

    int textSize = inputTextSizeTask0(textSize);
    inputTextTask0(buffer, textSize);

    char *text = new char[textSize + 1];
    strcpy(text, buffer);

    int dictionarySize = inputDictionarySizeTask0(dictionarySize);
    char **dictionary = allocateMatrixMemmory(dictionarySize);
    inputDictionaryTask0(dictionary, dictionarySize);

    autoCorrect(text, dictionary, textSize, dictionarySize);

    delete[] text;
    deleteMatrixMemmory(dictionary, dictionarySize);

    return 0;
}
/*
    изпуснат знак за край на изречението:
        софтуерът определя дали е достигнат краят на изречението тогава и само тогава, когато следващата дума започва на нов ред или няма
        следваща дума;
        приемаме, че всяко такова изречение би завършило с точка;
        ако изречението завършва със затварящи кавички, точката се слага преди тях.

    "Въведен" стринг(151):
Math 101:1+1=2,2-3=-1,5*5=25,9/3=3,2^3=8,2(3+4)=14
Dont you ever jyst .,;:!?.
A wise man once said:\"djundjalunga\"
And an een wiser man said \"bruh.\"

    Речник(7):
Dont-Don't
jyst-just
djundjalunga-Oops
een-even
bruh-No
said -said:
wizer-wiser

    Output:
    Math 101: 1 + 1 = 2, 2 - 3 =  - 1, 5 * 5 = 25, 9 / 3 = 3, 2 ^ 3 = 8, 2 (3 + 4) = 14.
    Don't you ever just . , ; : ! ? .
    A wise man once said:  "Oops."
    And an even wiser man said: "No."
    .
*/