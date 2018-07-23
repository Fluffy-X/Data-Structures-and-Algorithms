// Facebook Hacker Cup 2018 
// Problem : Let It Flow
// Solution : Dynamic Programming
/** State : direction of previous pipe
    left = 0;
    right = 1;
    up = 2;
    down = 3;
**/
#include <bits/stdc++.h>
using namespace std;
int n, MOD=1000000007;
vector<string> grid;
int dp[3][1005][4];
int rec(int i, int j, int state) {
	if ( i == 2 && j == n && state == 0)
		return 1;
    if ( j > n)
        return 0;
    if ( grid[i][j]=='#')
        return 0;
    if(dp[i][j][state] != -1)
        return dp[i][j][state];
	if(i == 0) {
		if (state == 1)
			return 0;
		else if ( state == 3) {
            dp[i][j][state] = rec(i,j+1,0);
			return dp[i][j][state];
		}
		else if (state == 0){
		    dp[i][j][state] = rec(i+1, j, 2);
			return dp[i][j][state];
		}
		else
			return 0;
	}
	else if ( i == 2) {
		if (state == 1)
			return 0;
		else if ( state == 2) {
            dp[i][j][state] = rec(i, j+1, 0);
			return dp[i][j][state];
		}
		else if (state == 0){
		    dp[i][j][state] = rec(i-1, j, 2);
			return dp[i][j][state];
		}
		else
			return 0;
	}
	else if ( i == 1) {
		if ( state == 2) {
            dp[i][j][state] = rec(i,j+1,0);
			return dp[i][j][state];
		}
		else if(state == 0) {
		    dp[i][j][state] = (rec(i+1, j, 2) + rec(i-1, j, 3))%MOD;
			return dp[i][j][state];
		}
		else if(state == 3) {
		    dp[i][j][state] = rec(i,j+1,0);
			return dp[i][j][state];
		}
	}
}
int main() {
    freopen("input.txt", "r", stdin);
    cin>>n;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 1005; j++)
            for(int k = 0; k < 4; k++)
                dp[i][j][k]=-1;
    grid.resize(3);
    for(int i = 0; i < 3; i++)
        cin>>grid[i];
    cout<<rec(0,0,0);
    return 0;
}
