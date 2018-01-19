#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > memo(10+1,vector<int>(10+1,-1));
vector<int> v = {0,1,-1,0};
int ways(int n, int sum)
{
    int temp=0;
    if(n==0)
    {
        if(sum==0)
            return 1;
        else
            return 0;
    }
    for(int i=0; i<4; i++)
    {
        if(memo[n-1][sum+v[i]]!=-1)
            temp += memo[n-1][sum+v[i]];
        else
        {
            memo[n-1][sum+v[i]] = ways(n-1,sum+v[i]);
            temp += memo[n-1][sum+v[i]];
        }
    }
    return temp;
}

int main()
{
    cout << ways(2,0);
    return 0;
}
