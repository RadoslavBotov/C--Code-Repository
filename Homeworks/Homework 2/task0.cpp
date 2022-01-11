#include <iostream>
using namespace std;

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
    cin.get();
    cout << "> Text:" << endl;
    for (int i = 0; i < textSize; i++)
        cin.get(text[i]);
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
    cin.get();
    if (dictionarySize != 0)
    {
        cout << "> Dictionary:" << endl;
        for (int i = 0; i < dictionarySize; i++)
            cin.getline(dictionary[i], 100);
    }
}

bool shouldAddSpaceAfter(char symbol)
{
    switch (symbol)
    {
    case '.':
        return true;
        break;
    case ',':
        return true;
        break;
    case '?':
        return true;
        break;
    case '!':
        return true;
        break;
    case ';':
        return true;
        break;
    case ':':
        return true;
        break;
    case '-':
        return true;
        break;
    case '"':
        return true;
        break;
    case ')': // ) ] } >
        return true;
        break;

    default:
        return false;
        break;
    }
}

void addSpaceRight(char *arr, int &textSize, int index, char symbol = ' ')
{
    textSize++;
    for (int i = textSize; i > index; i--)
        arr[i] = arr[i - 1];
    arr[index] = symbol;
}

void addSpaceLeft(char *arr, int &textSize, int index, char symbol = ' ')
{
    textSize++;
    for (int i = textSize; i > index + 1; i--)
        arr[i] = arr[i - 1];
    arr[index + 1] = symbol;
}

void removeDupWord(string str)
{
    string word = "";
    for (auto x : str)
    {
        if (x == ' ')
        {
            cout << word << endl;
            word = "";
        }
        else
        {
            word = word + x;
        }
    }
    cout << word << endl;
}

void punctuation(char *text)
{
}

void autoCorrect(char *text, char **dictionary, int textSize, int dictionarySize)
{
    for (int i = 0; i < textSize; i++)
    {
        cout << "< " << i << " " << text[i] << endl;
        if (shouldAddSpaceAfter(text[i]))
            if (text[i + 1] != ' ')
                addSpaceRight(text, textSize, i);
    }
}

int main()
{
    // const unsigned MAX_LEN = 1024;
    // //...

    // char buffer[MAX_LEN];
    // std::cin.getline(buffer, '\n');

    // char *str = new char[strlen(buffer) + 1];
    // //+1 заради '\0' накрая
    // strcpy(str, buffer);

    int textSize = inputTextSizeTask0(textSize);
    char *text = new char[textSize];
    inputTextTask0(text, textSize);

    int dictionarySize = inputDictionarySizeTask0(dictionarySize);
    char **dictionary = allocateMatrixMemmory(dictionarySize);
    inputDictionaryTask0(dictionary, dictionarySize);

    autoCorrect(text, dictionary, textSize + 1, dictionarySize);

    cout << "\nRedacted text:\n"
         << text;

    delete[] text;
    deleteMatrixMemmory(dictionary, dictionarySize);

    return 0;
}
/*
Аня има проблем с правописа и често допуска грешки, пишейки документация на софтуера, който разработва. Затова ѝ е хрумнала
добрата идея да напише софтуер, който да ги поправя вместо нея. Възможни автоматично поправими грешки са:

    пропуснат интервал около препинателен знак:
        интервал се слага след всеки препинателен знак с изключение на отваряща скоба и отварящи кавички;
        интервал се слага преди тире, аритметична операция, отваряща скоба и отварящи кавички;
    сгрешен правопис на дума или фраза;
        за корекция на сгрешени думи или фрази, софтуерът използва помощен речник;
        речникът представлява поредица от двойки от сгрешена дума или фраза и правилното ѝ изписване, разделени със знак за тире;
    изпуснат знак за край на изречението:
        софтуерът определя дали е достигнат краят на изречението тогава и само тогава, когато следващата дума започва на нов ред или няма
        следваща дума;
        приемаме, че всяко такова изречение би завършило с точка;
        ако изречението завършва със затварящи кавички, точката се слага преди тях.

Да се напише функция autoCorrect, която по зададен текст за редакция и речник, както е описан по-горе, извежда на екрана
редактирания текст. Функцията да приема параметри с подходящ тип. Да се реализира подходяща програма, която демонстрира
работата на функцията като въвежда текст за редакция и речник и ги подава като параметри.
Допуска се използването на помощни функции.

    Ограничения
    Записите в речника имат максимална дължина от 100 символа.
    Дължината на текста след извършените корекции не може да надвишава 2048 символа.

    "Въведен" стринг(149): "Math 101:1+1=2,2-3=-1,5*5=25,9/3=3,2^3=8,2(3+4)=14\nDont you ever jyst .,;:!?.\nA wise man once said:\"djundjalunga\"\nAnd an een wiser man said \"bruh.\"\n"
    Речник(7): { "Dont-Don't", "jyst-just", "djundjalunga-Oops", "een-even", "bruh-No", "said -said:", "wizer-wiser" }

    Output:
    Math 101: 1 + 1 = 2, 2 - 3 =  - 1, 5 * 5 = 25, 9 / 3 = 3, 2 ^ 3 = 8, 2 (3 + 4) = 14.
    Don't you ever just . , ; : ! ? .
    A wise man once said:  "Oops."
    And an even wiser man said: "No."
    .
*/