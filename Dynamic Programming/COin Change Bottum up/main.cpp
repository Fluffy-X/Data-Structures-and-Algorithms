#include <bits/stdc++.h>
using namespace std;

int coin_change_ways(vector<int>& v, int n)
{
    vector<vector<int> > memo(v.size()+1,vector<int>((n+1),0));
    for(int i=0; i<=v.size(); i++)
        memo[i][0]=1;
    for(int i=1; i<=v.size(); i++)
    {
        for(int j =1; j<=n; j++)
        {
            if(j-v[i-1] >= 0)
                memo[i][j] = memo[i][j-v[i-1]] + memo[i-1][j];
            else
                memo[i][j] = memo[i-1][j];
        }
    }
    for(int i=0; i<=v.size(); i++)
    {
        for(int j =0; j<=n; j++)
        {
            cout << memo[i][j] << " " ;
        }
        cout << endl;
    }
    return memo[v.size()][n];
}


int main()
{
    int n = 10;
    vector<int> v = {2,5,3,6};
    cout << coin_change_ways(v,n);




    return 0;
}
