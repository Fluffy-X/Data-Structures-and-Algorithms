int kap = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
        ans[0] = 0;
        ans[1] = 1;
        if ( num == 1)
            return ans;
        for ( int i = 2; i <= num; i++)
            ans[i] = ans[(i&(i-1))] + 1;
        return ans;
    }
};
