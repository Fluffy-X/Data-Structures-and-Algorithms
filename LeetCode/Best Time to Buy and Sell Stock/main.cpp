int kap = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if ( prices.size() == 0)
            return 0;
        int n = prices.size();
        int Suffix[n];
        Suffix[n-1] = prices[n-1];
        for ( int i = n-2; i >= 0; i--) {
            Suffix[i] = max(Suffix[i+1], prices[i]);
        }
        int ans = 0;
        for ( int i = 0; i < n - 1; i++) {
        	if ( prices[i] < Suffix[i+1])
                ans = max(ans, Suffix[i+1] - prices[i]);
        }
        return ans;
    }
};
