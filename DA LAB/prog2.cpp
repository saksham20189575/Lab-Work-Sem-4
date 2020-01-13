#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
#define forab(i,a,b,c) for(int i=a;i<=b;i+=c)
int main()
{

    /*//CASE 1:-
    //FOR ARRAY IN ASCENDING ORDER
    int n;
    n = 500;
    int a[n];
    forn(i,n)
    {
        a[i]=(i+1);
    }*/
    /*//CASE 2:-
    //FOR ARRAY IN DESCENDING ORDER
    int n;
    n = 500;
    int a[n];
    forn(i,n)
    {
    a[i]=(500-i);
    }*/
    /*//CASE 3:-
    // FOR RANDOM NUMBER
    int n = 500;
    int a[n];
    forn(i,n)
    {
        a[i]=rand();
    }*/
    //CASE 4:-
    // WITHOUT DUPLICATE ELEMENT RANDOM NUMBER
    /*int n = 500;
    int a[n];
    set<int> s;
    int j = 0;
    forn(i,100000)
    {
        int y = rand();
        if(s.find(y)==s.end())
        {
            a[j]=y;
            j++;
            s.insert(y);
        }
        if(j>=500)
        break;
    }*/
    //CASE 5:-
    //FOR USER DEFINED INPUT
    /*int n;
    cin>>n;
    int a[n];
    forn(i,n)
    {
        cin>>a[i];
    }*/
    int b[n];int c[n];
    forn(i,n)
    {
        b[i]=a[i];
        c[i]=a[i];
    }
    int ans1=0,ans2=0,ans3=0;int ans4=0,ans5=0,ans6=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(n-i-1);j++)
        {
            if(a[j]>a[j+1])
            {
            ans1++;
            swap(a[j],a[j+1]);
            }
            ans4++;
        }

    }
    for(int i=0;i<n;i++)
    {
        int index = i;
        for(int j=i+1;j<n;j++)
        {
            if(b[j]<b[index])
            {
                index = j;
            }
            ans5++;
        }
        swap(b[i],b[index]);
        if(index!=i)
        {
        ans2++;
        }
    }
    int i=0;
    while(i<n)
    {
        int j = i-1;
        int key = c[i];
        while(j>=0&&c[j]>key)
        {
            c[j+1]=c[j];
            j-=1;
            ans3++;
            ans6++;
        }
        ans6++;
        c[j+1]=key;
        i++;
    }
    cout<<"--------------------------------------------\n";
    cout<<"The count(SWAPS) of BUBBLE SORT = "<<ans1<<"\n";
    cout<<"The count(COMPARISON) of BUBBLE SORT = "<<ans4<<"\n";
    cout<<"--------------------------------------------\n";
    cout<<"The count(SWAPS) of SELECTION SORT = "<<ans2<<"\n";
    cout<<"The count(COMPARISON) of SELECTION SORT = "<<ans5<<"\n";
    cout<<"--------------------------------------------\n";
    cout<<"The count(SWAPS) of INSERTION SORT = "<<ans3<<"\n";
    cout<<"The count(COMPARISON) of INSERTION SORT = "<<ans6<<"\n";
    cout<<"--------------------------------------------\n";
    return 0;
}