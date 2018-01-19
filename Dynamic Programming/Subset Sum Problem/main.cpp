#include <bits/stdc++.h>
using namespace std;

bool subset(int n, vector<int>& v)
{
    vector<vector<bool> > memo(n+1,vector<bool>(v.size()+1,false));
    for(int i=0; i<=v.size(); i++)
        memo[0][i]=true;
    for(int i=1; i<=v.size(); i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(j-v[i] >=0)
                memo[j][i] = memo[j-v[i]][i-1] || memo[j][i-1];
            else
                memo[j][i] = memo[j][i-1];
        }
    }
    return memo[n][v.size()];
}
int main()
{
    vector<int> v = {3,34,1,12,5,2};
    int n = 35;
    cout << subset(n,v);
    return 0;
}
