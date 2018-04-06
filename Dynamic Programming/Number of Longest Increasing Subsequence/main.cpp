#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int r = triangle.size();
        int c = triangle[r-1].size();
        vector<vector<int> > memo(r,vector<int>(c,INT_MAX));
        memo[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) {
                    memo[i][j] = triangle[i][j] + memo[i-1][j];
                }
                else
                    memo[i][j] = triangle[i][j] + min( memo[i-1][j], memo[i-1][j-1] );
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < c; i++) {
            ans = min(memo[r-1][i], ans);
        }
        return ans;
    }
};
int main()
{
    vector<vector<int> > t = {
                         {2},
                        {3,4},
                       {6,5,7},
                      {4,1,8,3}
                    };
    Solution o;
    cout << o.minimumTotal(t);
    return 0;
}
