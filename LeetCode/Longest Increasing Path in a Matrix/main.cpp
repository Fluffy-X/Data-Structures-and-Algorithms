int kap = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int mx[4] = { 1, 0, -1, 0};
    int my[4] = { 0, 1, 0, -1};
    int dfs( vector<vector<int> >& matrix, vector<vector<int> >& dp, vector<vector<int> >& visited, int x, int y) {
        int curr = 0;
        if ( visited[x][y] == 1)
            return dp[x][y] - 1;
        visited[x][y] = 1;
        for ( int i = 0; i < 4; i++) {
            if ( (x + mx[i] >= 0) && (x + mx[i] < matrix.size() ) && (y + my[i] >= 0) && (y + my[i] < matrix[0].size() ) ) {
                if ( matrix[x + mx[i]][y + my[i]] > matrix[x][y]) {
                    if ( visited[x + mx[i]][y + my[i]] != -1)
                        curr = max(curr, dp[x + mx[i]][y + my[i]]);
                    else
                        curr = max (curr, 1 + dfs( matrix, dp, visited, x + mx[i], y + my[i]) );
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
        vector<vector<int> > visited(r, vector<int> (c,-1));
        vector<vector<int> > dp(r, vector<int> (c,-1));
        int ans = 1;
        for ( int i = 0; i < r; i++) {
            for ( int j = 0; j < c; j++) {
                if ( visited[i][j] == -1)
                    dfs(matrix, dp, visited, i, j);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
