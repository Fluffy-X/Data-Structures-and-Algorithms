#include <bits/stdc++.h>
using namespace std;

int maximum(vector<int>& v, vector<int>& p)
{
    int n = v.size();
    vector<vector<int> > memo(n+1,vector<int>(n,0));
    for(int i=1; i<=n; i++)
        memo[i][0]=p[0]*i;
    for(int i=1; i<n; i++)
        memo[1][i]=p[0];
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(j-v[i] >=0)
                memo[j][i] = max(memo[j-v[i]][i]+p[i],memo[j][i-1]);
            else
                memo[j][i]=memo[j][i-1];
        }
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<n; j++)
            cout << memo[i][j] << " " ;
        cout << endl;
    }
    return memo[n][v.size()-1];
}
int main()
{
    vector<int> v ={1,2,3,4,5,6,7,8};
    int n=v.size();
    vector<int> p={3,5,8,9,10,17,17,20};
    cout << maximum(v,p);
    return 0;
}
