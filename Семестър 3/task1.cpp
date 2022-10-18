#include <iostream>
#include <vector>
#include <exception>
using namespace std;

class MyStack
{
public:
    void push(char el)
    {
        arr.push_back(el);
    }

    char pop()
    {
        try
        {
            if (arr.empty())
                throw exception();
            else
            {
                char temp = arr.back();
                arr.pop_back();
                return temp;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        return '/';
    }

    char peek() const
    {
        return arr[0];
    }

    size_t size() const
    {
        return arr.size();
    }

private:
    std::vector<char> arr;
};

int main()
{
    std::string expr1 = "(1+[2*3])";
    std::string expr2 = "[1+(2*3)]";

    MyStack st;

    for (int i = 0; i < expr1.length(); i++)
    {
        if (expr1[i] == '(' || expr1[i] == ')' || expr1[i] == '[' || expr1[i] == ']')
            st.push(expr1[i]);
    }

    for (int i = 0; i < st.size(); i++)
        cout << st.pop();

    return 0;
}
