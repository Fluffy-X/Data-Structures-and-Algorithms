int kap = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int magic(string& a, string& b, int i, int j, vector<vector<int> >& memo) {
        if ( j < 0)
            return 1;
        if ( memo[i][j] != -1)
            return memo[i][j];
        int ans = 0;
        for ( int c = 0 ; c <= i - j; c++) {
            if ( a[i - c] == b[j])
                ans += magic(a, b, i - 1 - c, j - 1, memo);
        }
        memo[i][j] = ans;
        return ans;
    }
    int numDistinct(string& s, string& t) {
        if (s.size() < t.size())
            return 0;
        vector<vector<int> > memo(s.size()+1, vector<int> (t.size()+1,-1));
        return magic(s, t, s.size()-1, t.size()-1, memo);
    }
};
