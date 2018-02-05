#include <bits/stdc++.h>

using namespace std;

long getWays(long n, vector < long > v){
    vector<vector<long> > memo(v.size()+1,vector<long>((n+1),0));
    for(long i=0; i<=v.size(); i++)
        memo[i][0]=1;
    for(long i=1; i<=v.size(); i++)
    {
        for(long j =1; j<=n; j++)
        {
            if(j-v[i-1] >= 0)
                memo[i][j] = memo[i][j-v[i-1]] + memo[i-1][j];
            else
                memo[i][j] = memo[i-1][j];
        }
    }
    return memo[v.size()][n];
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, c);
    cout << ways ;
    return 0;
}
