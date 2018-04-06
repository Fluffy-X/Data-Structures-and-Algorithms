int kap = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool pre(string& a, string& b, string& c, int i, int j, std::vector<std::vector<int> >& memo) {
        if (memo[i][j] != -1)
    		return memo[i][j];
        if ( i == a.size()) {
            if ( b.substr(j, b.size() - j) == c.substr(i+j, c.size()-i+j)) {
                memo[i][j] = 1;
                return true;
            }
            else {
            	memo[i][j] = 0;
                return false;
            }
        }
        if ( j == b.size()) {
            if ( a.substr(i, a.size() - i) == c.substr(i+j, c.size() - i+j)) {
                memo[i][j] = 1;
                return true;
            }
            else {
            	memo[i][j] = 0;
                return false;
            }
        }
        if ( a[i] != c[i + j] && b[j] != c[i + j]) {
        	memo[i][j] = 0;
            return false;
        }
        if (a[i] == c[i + j] && b[j] != c[i + j]) {
        	memo[i+1][j] = pre(a, b, c, i+1, j, memo);
            return memo[i+1][j];
        }
        if (a[i] != c[i + j] && b[j] == c[i + j]) {
        	memo[i][j+1] = pre(a, b, c, i, j+1, memo);
            return memo[i][j+1];
        }
        if (a[i] == c[i + j] && b[j] == c[i + j] ) {
        	memo[i+1][j] = pre(a, b, c, i+1, j, memo);
        	memo[i][j+1] = pre(a, b, c, i, j+1, memo);
            memo[i][j] = memo[i+1][j] || memo[i][j+1];
            return memo[i+1][j] || memo[i][j+1];
        }
    }
    bool isInterleave(string& a, string& b, string& c) {
        if ( a.size() + b.size() != c.size())
            return false;
        if ( c.size() == 0)
            return true;
        vector<vector<int> > memo(a.size()+5, vector<int>(b.size()+5,-1));
        return pre(a, b, c, 0, 0, memo);

    }
};
