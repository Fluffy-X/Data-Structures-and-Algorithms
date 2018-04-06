#include <bits/stdc++.h>
using namespace std;
struct node {
    int x;
    int y;
};
class Solution {
public:
    vector<int> mx = { 1, 0, -1, 0};
    vector<int> my = { 0, 1, 0, -1};
    int dfs( vector<vector<int> >& matrix, vector<vector<int> >& dp, int x, int y) {
        int curr = 0;
        for ( int i = 0; i < 4; i++) {
            if ( (x + mx[i] >= 0) && (x + mx[i] < matrix.size() ) && (y + my[i] >= 0) && (y + my[i] < matrix[0].size() ) ) {
                if ( matrix[x + mx[i]][y + my[i]] > matrix[x][y]) {
                    if ( dp[x + mx[i]][y + my[i]] != -1)
                        curr = max(curr, dp[x + mx[i]][y + my[i]]);
                    else
                        curr = max (curr, 1 + dfs( matrix, dp, x + mx[i], y + my[i]) );
                }
            }
        }
        dp[x][y] = curr + 1;
        return curr ;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if ( matrix.size() == 0)
            return 0;
        int r = matrix.size();
        int c = matrix[0].size();
        //vector<vector<int> > visited(r, vector<int> (c,-1));
        vector<vector<int> > dp(r, vector<int> (c,1));
        for ( int i = 0; i < r; i++) {
            for ( int j = 0; j < c; j++) {
                if ( dp[i][j] == 1)
                    dfs(matrix, dp, i, j);
            }
        }
        int ans = 1;
        for ( int i = 0; i < r; i++) {
            for ( int j = 0; j < c; j++)
                ans = max(ans, dp[i][j]);
        }
        return ans;
    }
};
int main() {
    Solution o;



}
