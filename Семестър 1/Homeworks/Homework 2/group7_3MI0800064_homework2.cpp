#include <iostream>
#include <cstring>

//-----------------------------------------------------------Task0----------------------------------------------------------

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

void inputTextSizeTask0(int &textSize)
{
    do
    {
        std::cout << "> Text size: ";
        std::cin >> textSize;
    } while (textSize < 0 || textSize > 1024);
}

void inputTextTask0(char *text, int textSize)
{
    std::cin.get();
    std::cout << "> Text:" << std::endl;
    for (int i = 0; i < textSize; i++)
        std::cin.get(text[i]);
    text[textSize] = '\0';
}

void inputDictionarySizeTask0(int &dictionarySize)
{
    do
    {
        std::cout << "\n> Dictionary size: ";
        std::cin >> dictionarySize;
    } while (dictionarySize < 0 || dictionarySize > 128);
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

void Task0()
{
    std::cout << "\n\nTask 0:\n";

    const unsigned MAX_LEN = 1024;
    char buffer[MAX_LEN];

    int textSize;
    inputTextSizeTask0(textSize);
    inputTextTask0(buffer, textSize);

    char *text = new char[textSize + 1];
    strcpy(text, buffer);

    int dictionarySize;
    inputDictionarySizeTask0(dictionarySize);
    char **dictionary = allocateMatrixMemmory(dictionarySize);
    inputDictionaryTask0(dictionary, dictionarySize);

    autoCorrect(text, dictionary, textSize, dictionarySize);

    delete[] text;
    deleteMatrixMemmory(dictionary, dictionarySize);
}

//-----------------------------------------------------------Task1----------------------------------------------------------

void inputMatrixSize(int &N1, int &M1, int &N2, int &M2)
{
    do
    {
        std::cout << "> N1: ";
        std::cin >> N1;
    } while (N1 <= 0);

    do
    {
        std::cout << "> M1: ";
        std::cin >> M1;
    } while (M1 <= 0);

    do
    {
        std::cout << "> N2: ";
        std::cin >> N2;
    } while (N2 <= 0);

    do
    {
        std::cout << "> M2: ";
        std::cin >> M2;
    } while (M2 <= 0);
}

int **allocateMatrixMemmory(int n, int m)
{
    int **matrix = new int *[n];

    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];

    return matrix;
}

void deleteMatrixMemmory(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
        delete[] matrix[i];

    delete[] matrix;
}

void inputMatrix(int **matrix, int n, int m)
{
    std::cout << "> Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> matrix[i][j];
}

void printMatrix(int **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << matrix[i][j] << " ";

        std::cout << std::endl;
    }
}

void transformMatrix(int **matrixA, int **matrixB, int &N1, int &M1, int N2, int M2)
{
    if (N2 < N1)
        N1 = N2;

    if (M2 < M1)
        M1 = M2;

    for (int i = 0; i < N1; i++)
        for (int j = 0; j < M1; j++)
            if (matrixA[i][j] < matrixB[i][j])
                matrixA[i][j] = matrixB[i][j];
            else if (matrixA[i][j] > matrixB[i][j])
                matrixA[i][j] *= -1;

    std::cout << std::endl;
    printMatrix(matrixA, N1, M1);
}

void Task1()
{
    std::cout << "\n\nTask 1:\n";

    int N1, M1, N2, M2;
    inputMatrixSize(N1, M1, N2, M2);

    int **matrixA = allocateMatrixMemmory(N1, M1);
    int **matrixB = allocateMatrixMemmory(N2, M2);

    inputMatrix(matrixA, N1, M1);
    inputMatrix(matrixB, N2, M2);

    transformMatrix(matrixA, matrixB, N1, M1, N2, M2);

    deleteMatrixMemmory(matrixA, N1);
    deleteMatrixMemmory(matrixB, N2);
}

//-----------------------------------------------------------Task2----------------------------------------------------------

void inputMatrixSize(int &N, int &M)
{
    do
    {
        std::cout << "> N: ";
        std::cin >> N;
    } while (N < 2 || N > 20);

    do
    {
        std::cout << "> M: ";
        std::cin >> M;
    } while (M < 2 || M > 20);
}

template <typename T>
T **allocateMatrixMemmory(int n, int m)
{
    T **matrix = new T *[n];

    for (int i = 0; i < n; i++)
        matrix[i] = new T[m];

    return matrix;
}

template <typename T>
void deleteMatrixMemmory(T **matrix, int n)
{
    for (int i = 0; i < n; i++)
        delete[] matrix[i];

    delete[] matrix;
}

void inputMatrix(char **matrix, int n, int m)
{
    std::cout << "> Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> matrix[i][j];
}

void printMatrix(char **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << matrix[i][j] << " ";

        std::cout << std::endl;
    }
}

bool isAritmetic(int *path, int count)
{
    int d = path[1] - path[0];
    for (int i = 0; i < count - 1; i++)
        if (d + path[i] != path[i + 1])
            return false;
    return true;
}

bool endCondition(int x, int y, int N, int M)
{
    if (x < 0 || x >= N || y < 0 || y >= M)
        return false;
    return true;
}

void findStartCell(char **matrix, bool **visited, char *path, int pathIndex, int N, int M)
{
    int maxLength = 0;
    int curLength = 0;
    int x = 0;
    int y = 0;
    int finalX = 0;
    int finalY = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            x = i;
            y = j;

            while (endCondition(x, y, N, M) && visited[x][y] != true)
            {
                visited[x][y] = true;

                switch (matrix[x][y])
                {
                case 'L':
                    y--;
                    break;
                case 'R':
                    y++;
                    break;
                case 'D':
                    x++;
                    break;
                case 'U':
                    x--;
                    break;
                }

                curLength++;
            }

            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    visited[i][j] = false;

            if (curLength > maxLength)
            {
                maxLength = curLength;
                finalX = i;
                finalY = j;
            }

            curLength = 0;
        }
    }

    std::cout << "Starting coordinates: " << finalX << " " << finalY << std::endl;
}

void Task2()
{
    std::cout << "\n\nTask 2:\n";

    int N = 4, M = 4;
    inputMatrixSize(N, M);

    char *path = new char[N * M];

    int **grid = allocateMatrixMemmory<int>(N, M);

    bool **visited = allocateMatrixMemmory<bool>(N, M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visited[i][j] = false;

    char **board = allocateMatrixMemmory<char>(N, M);
    inputMatrix(board, N, M);

    findStartCell(board, visited, path, 0, N, M);

    delete[] path;
    deleteMatrixMemmory(board, N);
    deleteMatrixMemmory(visited, N);
}

//--------------------------------------------------------------------------------------------------------------------------

int main()
{
    // Task0();

    // Task1();

    // Task2();

    return 0;
}