class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int> > dp(n, vector<int> (k+1, INT_MAX-20000));
        vector<vector<int> > graph(n, vector<int> (n,0));
        for ( int i = 0; i < flights.size(); i++) {
        	graph[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        for ( int i = 0; i <= k; i++) {
       		dp[dst][i] = 0;
        }
        for ( int i = 0; i < n; i++) {
      		if ( graph[i][dst] != 0)
        		dp[i][0] = graph[i][dst];
        }
        for ( int j = 1; j <= k; j++) {
        	for ( int i = 0; i < n; i++) {
        		for ( int g = 0; g < n; g++) {
        		    if ( i == g)
                        continue;
        			else if ( graph[i][g] != 0) {
        				dp[i][j] = min (dp[i][j-1], min (dp[i][j], dp[g][j-1] + graph[i][g]));
        			}
        		}
        	}
        }
        for ( int i = 0; i < dp.size(); i++) {
        	for ( int j = 0; j < dp[0].size(); j++) {
                    cout << dp[i][j] << " ";
        	}
        	cout << endl;
        }

        if ( dp[src][k] >= INT_MAX - 30000)
            return -1;
        return dp[src][k];
    }
};
