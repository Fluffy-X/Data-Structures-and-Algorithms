#include <bits/stdc++.h>
using namespace std;

int F(int n, int m, vector<int>& v)
{
    if(m==1 && n==0)
        return 0;
    if(m==0)
        return 0;
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    if(m==1)
    {
        if(n%v[m-1]==0)
        {
            return 1;
        }
        else
            return 0;
    }
    return F(n,m-1,v)+F(n-v[m-1],m,v);
}
int DP(int n, int m, vector<int>& v, vector<vector<int> >& memo)
{
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    if(m==1)
    {
        if(n%v[m-1]==0)
        {
            return 1;
        }
        else
            return 0;
    }
    if(memo[n][m-1]!=-1)
    {
        if( (n-v[m-1]) < 0)
            return memo[n][m-1];
        if(memo[n-v[m-1]][m]!=-1)
        {
            return memo[n][m-1] + memo[n-v[m-1]][m];
        }
        else
        {
            memo[n-v[m-1]][m] = DP(n-v[m-1],m,v,memo);
            return memo[n][m-1] + memo[n-v[m-1]][m];
        }
    }
    else
    {
        memo[n][m-1] = DP(n,m-1,v,memo);
        if( (n-v[m-1]) < 0)
            return memo[n][m-1];
        if(memo[n-v[m-1]][m]!=-1)
        {
            return memo[n][m-1] + memo[n-v[m-1]][m];
        }
        else
        {
            memo[n-v[m-1]][m] = DP(n-v[m-1],m,v,memo);
            return memo[n][m-1] + memo[n-v[m-1]][m];
        }
    }
}
int main()
{
    vector<int> v={1,2,3};
    int n = 10;
    vector<vector<int> > memo(n+1, vector<int>(v.size()+1,-1));
    cout << DP(n,v.size(),v,memo) << endl;
    //cout << F(n,v.size(),v);
    //cout << memo[n][v.size()];
    return 0;
}
