#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int v[305][305];
#define INF -1000000000
int dp[305][305][305];
int n;
int state(int i1, int d, int i2) {
    if ( i1 == n || i2 == n || d-i1 == n || d-i2 == n)
        return INF;
    if ( i1 == n-1 && i2 == n-1 && d-i1 == n-1 && d-i2 == n-1 )
        return v[n-1][n-1];
    int val ;
    if ( i1 == i2 && d-i1 == d-i2 )
        val = v[i1][d-i1];
    else
        val = v[i1][d-i1] + v[i2][d-i2];
    if ( dp[i1+1][d+1][i2+1] == INF )
        dp[i1+1][d+1][i2+1] = state(i1+1, d+1, i2+1);

    if ( dp[i1+1][d+1][i2] == INF)
        dp[i1+1][d+1][i2]= state(i1+1, d+1, i2);

    if ( dp[i1][d+1][i2]  == INF)
        dp[i1][d+1][i2] = state(i1, d+1, i2);

    if ( dp[i1][d+1][i2+1]  == INF)
        dp[i1][d+1][i2+1] = state(i1, d+1, i2+1);

    return val + max(dp[i1+1][d+1][i2+1],
                    max( dp[i1+1][d+1][i2],
                       max(dp[i1][d+1][i2], dp[i1][d+1][i2+1])));
}

int main() {
//    freopen("input.txt", "r", stdin);
    fio;
    cin >> n;
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    for ( int i = 0; i < 305; i++) {
        for ( int j = 0; j < 305; j++) {
            for ( int k = 0; k < 305; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    cout << state(0,0,0);
    return 0;
}
