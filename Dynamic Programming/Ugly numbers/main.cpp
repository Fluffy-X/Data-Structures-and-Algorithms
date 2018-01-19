#include <bits/stdc++.h>
using namespace std;
set<long> s;
void ugly(long i, long n)
{
    if(i > n)
        return;
    if(s.find(2*i)==s.end())
    {
        s.insert(2*i);
        ugly(2*i,n);
    }
    if(s.find(3*i)==s.end())
    {
        s.insert(3*i);
        ugly(3*i,n);
    }
    if(s.find(5*i)==s.end())
    {
        s.insert(5*i);
        ugly(5*i,n);
    }
}
void uglyrecursive(long i, long n)
{
    if(i > n*n)
        return;
    s.insert(2*i);
    s.insert(3*i);
    s.insert(5*i);
    ugly(2*i,n);
    ugly(3*i,n);
    ugly(5*i,n);
}
int main()
{
    s.insert(1);
    long n=1953125;
    set<long>::iterator it;
    long count=1;
    //ugly(1,n);
    uglyrecursive(1,n);

    for(it=s.begin(); it!=s.end(); count++,it++)
    {
        if(*it==n)
            cout << count;
    }
    return 0;
}
