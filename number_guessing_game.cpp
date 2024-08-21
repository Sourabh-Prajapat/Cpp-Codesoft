
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x=-1;
    srand(time(0));
    int num=rand()%100;
    cout<<endl<<"Guess a number between 0 to 99."<<endl;
    while(x!=num)
    {
        cout<<"\nGuess a number: ";
        cin>>x;
        if(x==num)
        {
            cout<<"\nYou guessed the right number.\n"<<endl;
            break;
        }
        if(x<num)
        {
            cout<<"Your number is too low."<<endl;
        }
        else
        {
            cout<<"Your number is too high."<<endl;
        }
    }

    return 0;
}