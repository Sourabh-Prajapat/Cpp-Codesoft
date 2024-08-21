#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<char>> game)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<game[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool check(vector<vector<char>> game)
{
    if(game[1][1]!='_' && game[1][1]==game[0][0] && game[1][1]==game[2][2])
        return true;
    if(game[1][1]!='_' && game[1][1]==game[0][2] && game[1][1]==game[2][0])
        return true;
    for(int i=0;i<3;i++)
    {
        if(game[i][0]!='_' && game[i][0]==game[i][1] && game[i][0]==game[i][2])
            return true;
        if(game[0][i]!='_' && game[0][i]==game[1][i] && game[0][i]==game[2][i])
            return true;
    }
    return false;
}

int main()
{
    char ans='Y';
    vector<int> v={11,12,13,21,22,23,31,32,33};
    cout<<endl<<"Lets play the game tic tac toe.\n"<<endl;
    cout<<"X assigned to Player1."<<endl;
    cout<<"O assigned to Player2."<<endl<<endl;

    while(ans=='Y' || ans=='y')
    {
        cout<<"Postions of the board: "<<endl;
        cout<<"11  12  13\n21  22  23\n31  32  33\n"<<endl;
        cout<<"Board:"<<endl;
        vector<vector<char>> game={{'_','_','_'},{'_','_','_'},{'_','_','_'}};
        display(game);
        int x=0;
        int p1,p2;
        while(x<9)
        {
            while(true)
            {
                cout<<"X Enter the position of your mark: ";
                cin>>p1;
                auto n=find(v.begin(),v.end(),p1);
                int i=p1/10-1,j=p1%10-1;
                if(n-v.begin()==9 || game[i][j]!='_')
                {
                    cout<<"Enter empty position.\n"<<endl;
                }
                else 
                {
                    game[i][j]='X';
                    break;
                }
            }
            cout<<"\nBoard:\n\n";
            display(game);
            if(check(game))
            {
                cout<<"Player1 (X) wins."<<endl;
                break;
            }
            x++;
            if(x==9) break;
            while(true)
            {
                cout<<"O Enter the position of your mark: ";
                cin>>p2;
                auto n=find(v.begin(),v.end(),p2);
                int i=p2/10-1,j=p2%10-1;
                if(n-v.begin()==9 || game[i][j]!='_')
                {
                    cout<<"Enter empty position.\n"<<endl;
                }
                else
                {
                    game[i][j]='O';
                    break;
                }
            }
            cout<<"\nBoard:\n\n";
            display(game);
            if(check(game))
            {
                cout<<"Player2 (O) wins."<<endl;
                break;
            }
            x++;
        }
        if(x==9)
        {
            cout<<"\nGame draw."<<endl;;
        }

        cout<<endl<<"Want to play again?(Y/N) ";
        cin>>ans;
        cout<<endl;
    }

    return 0;
}