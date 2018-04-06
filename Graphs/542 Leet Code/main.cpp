#include <bits/stdc++.h>
using namespace std;
struct node {
	long long v;
	long long d;

};
int main() {
	long long v;
	long long e;
	long long t;
	cin >> v >> e;
	long long a,b,c;
	node n;
	vector<vector<int> > graph(v+1, vector<int>(v+1,1e8) );
	for ( long long i = 0; i < e; i++) {
		cin >> a >> b >> c;
		graph[a][b] = c;
	}
	vector<vector<long long> > dp(v+1, vector<long long>(v+1,1e8));
	for ( long long i = 1; i <= v; i++) {
        dp[i][i] = 0;
	}
	int g =0;
	for ( long long k = 1; k <= v; k++) {
        for ( long long i = 1; i <= v; i++) {
            for ( long long j = 1; j <= v; j++) {
                if ( i == j) continue;g=0;
                for ( auto itr = graph[i].begin(); itr != graph[i].end(); itr++,g++) {
                    if ( graph[i][j] != 1e8)
                    dp[i][j] = min ( *itr + dp[g][j], dp[i][j]);
                }
            }
        }
	}
	for ( long long i = 1; i <= v; i++ ) {
		for ( long long j = 1; j <= v; j++) {
			if (dp[i][j] == 1e8)
				dp[i][j] = -1;
		}
	}/*
	for ( int i = 1; i <= v; i++ ) {
		for ( int j = 1; j <= v; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cin >> t;
	long long s,d;
	while ( t--) {
        cin >> s >> d;
        cout << dp[s][d] << endl;
	}
    return 0;
}
