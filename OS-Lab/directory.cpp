#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
class File
{
    public:
    string s;
    vector<int> blocks;
    File(string name,vector<int> b)
    {
        this->s = name;
        forn(i,b.size())
        {
            this->blocks.push_back(b[i]);
        }
    }
};
class dir
{
    public:
    string s;
    vector<dir*> list_of_sub_dir;
    vector<File*> list_of_files;
    dir(string name)
    {
        this->s = name;
        this->list_of_sub_dir = {};
        this->list_of_files = {};
    }
};
class Tree
{
    public:
    dir* root;
    Tree(string name)
    {
        root = new dir(name);
    }
    void addDir(string s,string parent)
    {
        bool flag = false;
        dir* new_d = new dir(s);
        queue<dir*> q;
        q.push(root);
        dir* ans;
        while(!q.empty())
        {
            dir* f = q.front();
            if(f->s==parent)
            {
                flag = true;
                ans = f;
                break;
            }
            q.pop();
            vector<dir*>::iterator ptr;
            for(ptr = f->list_of_sub_dir.begin();ptr!=f->list_of_sub_dir.end();ptr++)
            {
                q.push(*ptr);
            }
        }
        if(flag)
        ans->list_of_sub_dir.push_back(new_d);
        else
        {
            cout<<"You entered the wrong parent directory name \n";
        }
    }
    void addFiles(string s,string parent,vector<int> b)
    {
        File* new_d = new File(s,b);
        queue<dir*> q;
        q.push(root);
        dir* ans;
        bool flag = false;
        while(!q.empty())
        {
            dir* f = q.front();
            if(f->s==parent)
            {
                flag = true;
                ans = f;
                break;
            }
            q.pop();
            vector<dir*>::iterator ptr;
            for(ptr = f->list_of_sub_dir.begin();ptr!=f->list_of_sub_dir.end();ptr++)
            {
                q.push(*ptr);
            }
        }
        if(flag)
        ans->list_of_files.push_back(new_d);
        else
        {
            cout<<"You entered wrong parent directory name \n";
        }
    }
    void display(string name)
    {
        queue<dir*> q;
        q.push(root);
        dir* ans;
        bool flag = false;
        while(!q.empty())
        {
            dir* f = q.front();
            if(f->s==name)
            {
                flag = true;
                ans = f;
                break;
            }
            q.pop();
            vector<dir*>::iterator ptr;
            for(ptr = f->list_of_sub_dir.begin();ptr!=f->list_of_sub_dir.end();ptr++)
            {
                q.push(*ptr);
            }
        }
        if(flag)
        {
            vector<dir*>::iterator ptr;
            vector<File*>::iterator ptr1;
            cout<<"The current node = "<<ans->s<<"\n";
            if(ans->list_of_files.size()==0)
            {
                cout<<"No Files in "<<ans->s<<"\n";
            }
            else
            {
            cout<<"The list of files in "<<ans->s<<":- \n";
            for(ptr1 = ans->list_of_files.begin();ptr1!=ans->list_of_files.end();ptr1++)
            {
                File* p = *ptr1;
                cout<<p->s<<"\n";
                forn(i,p->blocks.size())
                cout<<p->blocks[i]<<" ";
                cout<<"\n";
            }
            }
            if(ans->list_of_sub_dir.size()==0)
            {
                cout<<"No subdirectories in "<<ans->s<<"\n";
            }
            else
            {
            cout<<"The list of subdirectories in "<<ans->s<<":- \n";
            for(ptr = ans->list_of_sub_dir.begin();ptr!=ans->list_of_sub_dir.end();ptr++)
            {
                dir* p = *ptr;
                //display(p->s);
                cout<<p->s<<"\n";
            }
            }

        }
        else
        {
            cout<<"You entered the wrong directory name \n";
        }
    }
};


int main()
{
    bool flag = false;
    cout<<"Enter the name of root directory = \n";
    string s;
    cin>>s;
    Tree t(s);
    while(1)
    {
        cout<<"---------------------------------\n";
        cout<<"Enter your choice = \n";
        cout<<"1. Add directory \n";
        cout<<"2. Add Files in Directory \n";
        cout<<"3. Display contents of any directory \n";
        cout<<"4. Exit \n";
        int x;
        cin>>x;
        if(x==1)
        {
            cout<<"Enter the name of new directory you want = \n";
            string new_d,parent;
            cin>>new_d;
            cout<<"Enter the name of parent directory = \n";
            cin>>parent;
            t.addDir(new_d,parent);
        }
        if(x==2)
        {
            cout<<"Enter the name of file you want to create = \n";
            string s;
            cin>>s;
            cout<<"Enter the name of parent directory = \n";
            string parent;
            cin>>parent;
            cout<<"Enter the number of blocks = \n";
            int n;
            cin>>n;
            vector<int> b;
            for(int i=0;i<n;i++)
            {
                int y;
                cin>>y;
                b.push_back(y);
            }
            t.addFiles(s,parent,b);
        }
        if(x==3)
        {
            cout<<"Enter the name of directory you want to Display \n";
            string s;cin>>s;
            t.display(s);
        }
        if(x==4)
        {
            break;
        }
    }
    return 0;
}