int kap = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
	void dfs(int start, vector<int> graph[], vector<int> t, vector<int> nums) {
		for ( auto itr = graph[start].begin(); itr != graph[start].end(); itr++) {
			t.push_back(nums[*itr]);
			ans.insert(t);
			dfs(*itr, graph, t, nums);
            t.pop_back();
		}
	}
	set<vector<int> > ans;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int> > ret;
        if ( nums.size() == 0 )
            return ret;
        vector<int> graph[nums.size()];
        for ( int i = 0; i < nums.size(); i++) {
            for ( int j = i + 1; j < nums.size(); j++) {
                if ( nums[i] <= nums[j] )
                    graph[i].push_back(j);
            }
        }
        for ( int i = 0; i < nums.size(); i++) {
        	vector<int> t = {nums[i]};
        	dfs(i, graph, t, nums);
        }
        for ( auto itr = ans.begin(); itr != ans.end(); itr++)
        	ret.push_back(*itr);https://leetcode.com/submissions/detail/147687032/
        return ret;
    }
};
