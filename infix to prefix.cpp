#include <bits/stdc++.h>
#include<iostream>
using namespace std;

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

string infixToPostfix(string infix)
{
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> s;
    string output;

    for (int i = 0; i < l; i++) {

        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];

        else if (infix[i] == '(')
            s.push('(');

        else if (infix[i] == ')')
        {
            while (s.top() != '(')
             {
                output += s.top();
                s.pop();
            }

            s.pop();
        }
         else
        {
            if (isOperator(s.top()))
            {
                if(infix[i] == '^')
                {
                      while (getPriority(infix[i]) <= getPriority(s.top()))
                       {
                         output += s.top();
                         s.pop();
                       }

                }
                else
                {
                    while (getPriority(infix[i]) < getPriority(s.top()))
                       {
                         output += s.top();
                         s.pop();
                       }

                }
                s.push(infix[i]);
            }
        }
    }
      while(!s.empty()){
          output +=s.top();
        s.pop();
    }
    return output;
}

string infixToPrefix(string infix)
{

    int l = infix.size();
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < l; i++) {

        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    string prefix = infixToPostfix(infix);

    reverse(prefix.begin(), prefix.end());

    return prefix;
}
int main()
{
    string s;
    cout<<"enter string";
    cin>>s;
    cout << infixToPrefix(s) << std::endl;
    return 0;
}
