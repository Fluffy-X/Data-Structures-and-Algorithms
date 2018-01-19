#include <bits/stdc++.h>
using namespace std;

int lcss(string& x, string& y)
{
    int n = x.size();
    int m = y.size();
    vector<vector<int> > memo(m,vector<int>(n,0));
    for(int i=0; i<n; i++)
    {
        if(y[0]==x[i])
            memo[0][i]=1;
        if(x[0]==y[i])
            memo[i][0]=1;
    }
    int ans = 0;
    for(int i=1; i<min(n,m); i++)
    {
        for(int j=1; j<n; j++)
        {
            if(x[j]==y[i])
            {
                memo[i][j] = 1 + memo[i-1][j-1];
                ans = max(ans,memo[i][j]);
            }
        }
        for(int j=1; j<m; j++)
        {
            if(x[i]==y[j])
            {
                memo[j][i]=1+memo[j-1][i-1];
                ans = max(ans,memo[j][i]);
            }
        }
    }
    return ans;
}

int main()
{
    string x = "absitexgee";
    string y = "geeaxsite";
    cout << lcss(x,y);
    return 0;
}
