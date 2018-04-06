int kap = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int numSquares(int n) {
        int c = sqrt(n) + 1;
        int r = n+1;
        int dp[r][c];
        memset(dp, 0, sizeof(dp[0][0]) * r * c);
        for ( int i = 1; i < r; i++)
            dp[i][0] = INT_MAX-10;
        for ( int i = 1; i < c; i++) {
            for ( int j = 1; j < r; j++) {
                if ( (j-(i*i)) >= 0)
                    dp[j][i] =  min( dp[j][i - 1] , dp[(j-(i*i))][i] + 1);
                else
                    dp[j][i] = dp[j][i - 1];
            }
        }
        return dp[r-1][c-1];
    }
};
