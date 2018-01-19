#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

vector<int> v={1,3,5};
int c=0;

void ways(int sum, int x)
{
    for(int i=0; i<v.size(); i++)
    {
        if(sum==x)
            c++;
        if( sum+v[i] <= x)
        {
            ways(sum+v[i],x);
        }
        else
            return;
    }
}
int main()
{
    sort(v.begin(),v.end());
    int x=6;
    ways(0,x);
    cout << c;
    return 0;
}
