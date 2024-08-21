#include <bits/stdc++.h>
using namespace std;

void add_task(vector<vector<string>>& v)
{
    while(true)
    {
        cout<<"\n-----------------------------------------------------\n";
        cout<<"\nEnter 1 for add."<<endl;
        cout<<"Enter 2 for exit.\n"<<endl;
        int c;
        cin>>c;
        if(c==2)
            return;
        cout<<"\nEnter name of the task: ";
        string t;
        cin>>t;
        while(true)
        {
            cout<<"\nEnter 1 for Completed, and 0 for incomplete: ";
            int x;
            cin>>x;
            if(x==1)
                v.push_back({t,"Completed"});
            else if(x==0)
                v.push_back({t,"Incomplete"});
            else
            {
                cout<<"\n*****Enter valid choice.*****\n";
                continue;
            }
            break;
        }
    }
    cout<<"\n.....Tasks added successfully......\n";
}

int find_task(vector<vector<string>>& v,string s)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i][0]==s)
        {
            return i;
        }
    }
    return -2;
}

void display_task(vector<vector<string>>& v)
{
    cout<<"\nTasks: \n\n";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i][0]<<" : "<<v[i][1]<<endl;
    }
}

int main()
{
    vector<vector<string>> v;
    cout<<"\n***** Add tasks to the list ******\n";
    add_task(v);
    while(true)
    {
        cout<<"\n\nEnter 1 for add task.\n";
        cout<<"Enter 2 for display tasks.\n";
        cout<<"Enter 3 for update status.\n";
        cout<<"Enter 4 for delete task.\n";
        cout<<"Enter 5 for exit.\n"<<endl;
        int a;
        cout<<"Enter: ";
        cin>>a;
        if(a==1)
        {
            add_task(v);
        }
        else if(a==2)
        {
            if(v.empty())
                cout<<"\n.....List is empty......\n";
            else
                display_task(v);
        }
        else if(a==3)
        {
            if(v.empty())
            {
                cout<<"\n.....List is empty......\n";
                continue;
            }
            string t;
            cout<<"\nEnter name of the task you want to update: ";
            cin>>t;
            int i=find_task(v,t);
            if(i==-2)
                cout<<"\n.....Task not exist in the list......\n"<<endl;
            else
            {
                if(v[i][1]=="Completed")
                {
                    cout<<"\n.....Task already completed......\n";
                }
                else
                {
                    v[i][1]="Completed";
                    cout<<"\n.....Status updated successfully......\n";
                }
            }
        }
        else if(a==4)
        {
            if(v.empty())
            {
                cout<<"\n.....List is empty......\n";
                continue;
            }
            string d;
            cout<<"\nEnter name of the task you want to delete: ";
            cin>>d;
            int i=find_task(v,d);
            if(i==-2)
                cout<<"\n.....Task not exist in the list......\n"<<endl;
            else
            {
                v.erase(v.begin()+i);
                cout<<"\n.....Task deleted successfully......\n"<<endl;
            }
        }
        else if(a==5)
            break;
        else
        {
            cout<<"\n*****Enter valid choice.*****"<<endl;
            continue;
        }
    }
    cout<<"\n.....You exit successfully......\n\n";

    return 0;
}