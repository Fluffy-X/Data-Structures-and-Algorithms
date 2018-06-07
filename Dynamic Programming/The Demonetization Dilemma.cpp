#include <bits/stdc++.h>
using namespace std;
 
int main(){
    //freopen("AC.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> coins(m+1,0);
        for ( int i = 1; i <= m; i++)
            cin >> coins[i];
        vector<vector<int> > dp(2, vector<int>(n+1,0));
        for ( int i = 0; i <= n; i++)
            dp[0][i] = INT_MAX/2;
        for ( int j = 1; j < m+1; j++) {
            for ( int i = 1; i < n+1; i++) {
                if ( i - coins[j] == 0) {
                    dp[1][i] = min(1, dp[0][i]);
                }
                else if ( i - coins[j] > 0) {
                    dp[1][i] = min(1+dp[1][i-coins[j]],dp[0][i]);
                }
                else
                    dp[1][i] = dp[0][i];
            }
            dp[0] = dp[1];
        }
        if ( dp[1][n] == INT_MAX/2)
            cout << "No solution" << endl;
        else
            cout << dp[1][n] << endl;
    }
    return 0;
}