#include <iostream>
#include <stack>
#include <string>
#include <climits>
using namespace std;

int prec(char c)
{
    if (c == '*' || c == '/'){
        return 3;
    }
    if (c == '+' || c == '-'){
        return 4;
    }
   if (c == '&') {
        return 8;
    }
   if (c == '^') {
        return 9;
    }
    if (c == '|') {
        return 10;
    }

return INT_MAX;
}
bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

string infixToPostfix(string infix)
{
    stack<char> s;

    string postfix;

    for (char c: infix)
    {
        if (c == '(') {
            s.push(c);
        }

        else if (c == ')')
        {
            while (s.top() != '(')
            {
                postfix.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        else if (isOperand(c))
        {
            postfix.push_back(c);
        }
        else {
            while (!s.empty() && prec(c) >= prec(s.top()))
            {
                postfix.push_back(s.top());
                s.pop();
            }

            s.push(c);
        }
    }
    while (!s.empty())
    {
        postfix.push_back(s.top());
        s.pop();
    }
    return postfix;
}

int main()
{
    string infix;
    cout<<"enter string";
    cin>>infix;

    string postfix = infixToPostfix(infix);
    cout << postfix << endl;
   return 0;
}
