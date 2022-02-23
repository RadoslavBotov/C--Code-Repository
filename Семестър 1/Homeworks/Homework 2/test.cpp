#include <iostream>
#include <cstring>
using namespace std;

void addSpaceAt(char *text, char *str, int textSize, int &strSize, char symbol = ' ')
{
    textSize++;
    char *index = text + textSize;

    while (index != str)
    {
        *index = *(index - 1);
        index--;
    }
}



int main()
{
    char text[] = "qwe*1*abs";
    // char text[] = "Math 101:1+1=2,2-3=-1,5*5=25,9/3=3,2^3=8,2(3+4)=14\nDont you ever jyst.,;:!?.\nA wise man once said:\"djundjalunga\"\nAnd an een wiser man said \"bruh.\""
    char dictionary[8][100] = {
        {"Dont-Don't"},
        {"jyst-just"},
        {"djundjalunga -Oops"},
        {"een-even"},
        {"bruh-No"},
        {"said -said:"},
        {"wizer-wiser"},
        {"abs-!!!"},
    };

    char *ptr = strstr(text, "abs");
    int size = 1;
    // removeElementAt(text, ptr, strlen(text), size);

    std::cout << text;

    // autoCorrect(text, dictionary, strlen(text), 8);

    return 0;
}