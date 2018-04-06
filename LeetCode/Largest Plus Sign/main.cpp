int kap = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int> > table(N, vector<int> (N,1) );
        if ( mines.size() == 0) {
            if ( N % 2 != 0)
                return N / 2 + 1;
            else
                return N / 2 ;
        }
        else {
            for ( int i =0; i < mines.size(); i++)
                table[mines[i][0]][mines[i][1]] = 0;
            int Leftfix[N][N];
            memset( Leftfix, 0, sizeof(Leftfix[0][0]));
            for ( int i = 0; i < N; i++) {
                int c = 0;
                for ( int j = 0; j < N; j++) {
                    if ( table[i][j] == 1) {
                        Leftfix[i][j] = c;
                        c++;
                    }
                    else
                        c = 0;
                }
            }
            int Rightfix[N][N];
            memset( Rightfix, 0, sizeof(Rightfix[0][0]));
            for ( int i = 0; i < N; i++) {
                int c = 0;
                for ( int j = N - 1; j >= 0; j--) {
                    if ( table[i][j] == 1) {
                        Rightfix[i][j] = c;
                        c++;
                    }
                    else
                        c = 0;
                }
            }
            int Upfix[N][N];
            memset( Upfix, 0, sizeof(Upfix[0][0]));
            for ( int i = 0; i < N; i++) {
                int c = 0;
                for ( int j = 0; j < N; j++) {
                    if ( table[j][i] == 1) {
                        Upfix[j][i] = c;
                        c++;
                    }
                    else
                        c = 0;
                }
            }
            int DownFix[N][N];
            memset( DownFix, 0, sizeof(DownFix[0][0]));
            for ( int i = 0; i < N; i++) {
                int c = 0;
                for ( int j = N - 1; j >= 0; j--) {
                    if ( table[j][i] == 1) {
                        DownFix[j][i] = c;
                        c++;
                    }
                    else
                        c = 0;
                }
            }
            int ans = 0;
            for ( int i = 0; i < N; i++) {
                for ( int j = 0; j < N; j++) {
                    if ( table[i][j] == 0)
                        continue;
                    ans = max(ans, 1 + min(DownFix[i][j], min(Leftfix[i][j], min(Upfix[i][j], Rightfix[i][j]) ) ) );
                }
            }
            return ans;
            }
    }
};
