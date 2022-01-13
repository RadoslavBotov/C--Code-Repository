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
    case '(':
        return 1;
        break;
    case '[':
        return 1;
        break;
    case '{':
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
        break;
    case '>':
        return 2;
        break;
    case '<':
        return 2;
        break;
    case '\n':
        return 3;
        break;
    default:
        return 4;
    }
}

void addElementAt(char *arr, int &textSize, int index, char symbol = ' ')
{
    textSize++;
    for (int i = textSize; i > index; i--)
        arr[i] = arr[i - 1];
    arr[index] = symbol;
}

void addSpaceAtPointer(char *text, char *str, int &textSize, int &strSize)
{
    textSize++;
    char *index = text + textSize;

    while (index != str)
    {
        *index = *(index - 1);
        index--;
    }
}

void removeElementAt(char *text, char *str, int &textSize, int &strSize)
{
    char *index = text + textSize;

    while (str != index)
    {
        *str = *(str + 1);
        str++;
    }

    textSize--;
}

void autoCorrect(char *text, char **dictionary, int textSize, int dictionarySize)
{
    bool openingQuotes = true;
    for (int i = 0; i < textSize; i++) // punctuation
    {
        switch (shouldAddSpace(text, text[i]))
        {
        case 0: //   . , ; : ! ? ) ] }
            if (text[i] == '"')
                openingQuotes = !openingQuotes;
            if (text[i + 1] != ' ' && openingQuotes)
                addElementAt(text, textSize, i + 1);
            break;
        case 1: //   ( [ {
            if (text[i - 1] != ' ')
                addElementAt(text, textSize, i);
            break;
        case 2: //   + - * / = ^ > <
            if (text[i + 1] != ' ')
                addElementAt(text, textSize, i + 1);
            if (text[i - 1] != ' ')
                addElementAt(text, textSize, i);
            break;
        case 3: // \n
            if (text[i - 1] != '.')
                addElementAt(text, textSize, i, '.');
            break;
        }
    }

    if (dictionarySize != 0)
    {
        char **wrongWords = allocateMatrixMemmory(dictionarySize);
        char **correctWords = allocateMatrixMemmory(dictionarySize);

        char temp[101];
        for (int i = 0; i < dictionarySize; i++) // Separate dictionary into 2 arrays: "wrong" words and "correct" words
        {
            int t = 0;
            while (dictionary[i][t] != '-')
            {
                wrongWords[i][t] = dictionary[i][t];
                t++;
            }
            wrongWords[i][t] = '\0';
            strcpy(correctWords[i], strchr(dictionary[i], '-') + 1);
        }

        for (int i = 0; i < dictionarySize; i++) // for each entry in dictionary
        {
            int wrongWordSize = strlen(wrongWords[i]);
            int correctWordSize = strlen(correctWords[i]);

            char *wrongWord = strstr(text, wrongWords[i]);

            while (wrongWord != nullptr) // while there are "wrong" words in text
            {
                if (wrongWordSize < correctWordSize)
                    for (int i = 0; i < correctWordSize - wrongWordSize; i++)
                        addSpaceAtPointer(text, wrongWord, textSize, correctWordSize);
                else if (wrongWordSize > correctWordSize)
                    for (int i = 0; i < wrongWordSize - correctWordSize; i++)
                        removeElementAt(text, wrongWord, textSize, correctWordSize);

                strncpy(wrongWord, correctWords[i], correctWordSize);
                wrongWord = strstr(text, wrongWords[i]);
            }
        }

        deleteMatrixMemmory(wrongWords, dictionarySize);
        deleteMatrixMemmory(correctWords, dictionarySize);
    }

    if (textSize < 2048)
        std::cout << text << std::endl;
    else
        std::cout << "Text size bigger than 2048 after corrections!" << std::endl;
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