#include <bits/stdc++.h>
using namespace std;

int main()
{
    double num1,num2;
    char operation;
    cout<<"\nEnter calculation: ";
    cin>>num1>>operation>>num2;
    cout<<"ANSWER = ";
    if(operation=='+')
        cout<<num1+num2;
    else if(operation=='-')
        cout<<num1-num2;
    else if(operation=='*')
        cout<<num1*num2;
    else if(operation=='/')
        cout<<num1/num2;
    else
        cout<<"Invalid operation";
    cout<<"\n\n";

    return 0;
}