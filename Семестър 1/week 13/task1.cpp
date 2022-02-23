// Намерете всички пермутации на думата "rat".
#include <iostream>
#include <cstring>
using namespace std;

void permutation(char *str, int index, int size)
{
    if (index == size - 1)
    {
        std::cout << str << std::endl;
        return;
    }

    for (int j = index; j < size; j++)
    {
        swap(str[index], str[j]);
        permutation(str, index + 1, size);
        swap(str[index], str[j]);
    }
}

int main()
{
    const unsigned MAX_LEN = 128;

    char buffer[MAX_LEN];
    cin.getline(buffer, '\n');
    cout << endl;

    char *str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);

    permutation(str, 0, strlen(str));

    delete[] str;

    return 0;
}