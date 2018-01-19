#include <bits/stdc++.h>
using namespace std;
//Exponential Order 
//Recursive Solution with memoization/DP
int recursive(int i, int j, int c, vector<int>& a)
{
    int sol=0;
    if(j==0)
    {
        if(c%a[0]==0)
            return 1;
        else
            return 0;
    }
    if(c<0)
        return 0;
    for(int k=0; k<=c/a[j]; k++)
        sol += recursive(i,j-1,c-a[j]*k,a);
    return sol;
}
int main()
{
    vector<int> v = {2,2,2};
    cout << recursive(0,v.size()-1,10000,v);
    return 0;
}
