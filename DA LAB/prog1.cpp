#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
#define forab(i,a,b,c) for(int i=a;i<=b;i+=c)
int main()
{
    int n;
    cin>>n;
    int a[n];
    forn(i,n)
    cin>>a[i];
    int b[n];
    int c[n];
    forn(i,n)
    {
        b[i]=a[i];
        c[i]=a[i];
    }
    cout<<"-----------------BUBBLE SORT----------------\n";
    for(int i=0;i<n;i++)
    {
        cout<<"The array after "<<(i+1)<<"th iteration = \n";
        for(int j=0;j<(n-i-1);j++)
        {
            if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
        }
        forn(i,n)
        {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    cout<<"---------------SELECTION SORT----------------\n";
    for(int i=0;i<n;i++)
    {
        cout<<"The array after "<<(i+1)<<"th iteration = \n";
        int mi = INT_MAX;
        int index = -1;
        for(int j=i;j<n;j++)
        {
            if(b[j]<mi)
            {
                mi = b[j];
                index = j;
            }
        }
        swap(b[i],b[index]);
        forn(i,n)
        {
            cout<<b[i]<<" ";
        }
        cout<<"\n";
    }
    cout<<"---------------INSERTION SORT--------------\n";
    int i=1;
    while(i<=n)
    {
        sort(c,c+i);
        cout<<"The array after "<<i<<"th iteration = \n";
        forn(j,n)
        {
            cout<<c[j]<<" ";
        }
        cout<<"\n";
        i++;
    }
}