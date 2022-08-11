#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

stack<int> s;

int main()
{

    string exp;
    cout<<"Enter postfix expression: ";
    cin>>exp;

    for(int i=0;i<exp.length();i++)
        {

        if (isdigit(exp[i]))
            s.push(exp[i]-'0');

        else
            {
            int op2=s.top();
            s.pop();
            int op1=s.top();
            s.pop();

            if(exp[i]=='+')
                s.push(op1+op2);
            else if(exp[i]=='-')
                s.push(op1-op2);
            else if(exp[i]=='*')
                s.push(op1*op2);
            else if(exp[i]=='/')
                s.push(op1/op2);
             }
    }
    cout<<"After evalution we get: "<<s.top();
    return 0;
}

