#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
int main()
{
    cout<<"Enter the size of array = \n";
    int n;
    cin>>n;
    vector<int> v;
    cout<<"Enter the array elements = \n";
    forn(i,n)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<"The current array = \n";
    forn(i,v.size())
    cout<<v[i]<<" ";
    cout<<"\n";
    stack<int> ma;
    stack<int> s,u;
    stack<int> ins1;
    stack<int> del1,del2;
    while(1)
    {
        cout<<"Enter your choice = \n";
        cout<<"1. Swap two index of array \n";
        cout<<"2. Insert the element \n";
        cout<<"3. Delete the element \n";
        cout<<"4. Undo the last change \n";
        cout<<"5. Exit \n";
        int x;
        cin>>x;
        if(x==1)
        {
            cout<<"Enter two index = \n";
            int y,z;
            cin>>y>>z;
            s.push(y);
            u.push(z);
            swap(v[y],v[z]);
            forn(i,v.size())
            cout<<v[i]<<" ";
            cout<<"\n";
            ma.push(1);
        }
        else if(x==2)
        {
            cout<<"Enter the element to be inserted = \n";
            int y;
            cin>>y;
            cout<<"Enter the position to be inserted = \n";
            int z;
            cin>>z;
            vector<int>::iterator it = v.insert((v.begin()+z),y);
            ins1.push(z);
            forn(i,v.size())
            cout<<v[i]<<" ";
            cout<<"\n";
            ma.push(2);
        }
        else if(x==3)
        {
            cout<<"Enter the position of which element is to be deleted = \n";
            int z;
            cin>>z;
            del1.push(z);
            del2.push(v[z]);
            v.erase((v.begin()+z));
            forn(i,v.size())
            cout<<v[i]<<" ";
            cout<<"\n";
            ma.push(3);
        }
        else if(x==4)
        {
            if(ma.empty())
            {
                cout<<"No last change. \n";
            }
            else
            {
                int to = ma.top();
                if(to==1)
                {
                    if(s.empty())
                    {
                    cout<<"No last change.\n";
                    }
                    else
                    {
                    swap(v[s.top()],v[u.top()]);
                    u.pop();
                    s.pop();
                    forn(i,v.size())
                    cout<<v[i]<<" ";
                    cout<<"\n";
                    }
                }
                else if(to==2)
                {
                    if(ins1.empty())
                    {
                        cout<<"No last change.\n";
                    }
                    else
                    {
                        int t = ins1.top();
                        ins1.pop();
                        v.erase((v.begin()+t));
                        forn(i,v.size())
                        cout<<v[i]<<" ";
                        cout<<"\n";
                    }
                }
                else
                {
                    if(del1.empty())
                    {
                        cout<<"No last change.\n";
                    }
                    else
                    {
                        int pos = del1.top();
                        int val = del2.top();
                        del1.pop();
                        del2.pop();
                        vector<int>::iterator it = v.insert((v.begin()+pos),val);
                        forn(i,v.size())
                        cout<<v[i]<<" ";
                        cout<<"\n";
                    }
                }
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}