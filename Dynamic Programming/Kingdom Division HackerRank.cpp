#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MOD 1000000007
map<pair<long long, pair<char, pair<char, long long> > >, long long> dp;
vector<vector<long long> > tree;

long long dfs(long long start, char curcolor, char prevcolor, long long parent) {
    if ( prevcolor == curcolor ) {
        long long ways = 1;
        long long j = 0;
        for ( auto x : tree[start]) {
            if ( x != parent ) {
	            j++;
	            long long w = 0;
	            if ( dp.count( { x, { 'r', {curcolor, start} } } ) == 0)
                    dp[{ x, { 'r', {curcolor, start} } }] = dfs(x, 'r', curcolor, start);
	            w = (w + dp[{ x, { 'r', {curcolor, start} } }] ) % MOD;
	            if ( dp.count( { x, { 'b', {curcolor, start} } } ) == 0)
                    dp[{ x, { 'b', {curcolor, start} } }] = dfs(x, 'b', curcolor, start);
	            w = (w + dp[{ x, { 'b', {curcolor, start} } }] ) % MOD;
	            ways = (ways*w) % MOD;
    		}
        }
        if ( j == 0 )
        	return 1;
        return ways;
    }
    else /*( prevcolor != curcolor)*/ {
        if ( curcolor == 'r' ) {
            long long ways = 1;
            long long waysplus = 1, waysminus = 1;
        	long long j = 0;
	        for ( auto x : tree[start]) {
	            if ( x != parent ) {
		            j++;
	                long long w = 0;
	                if ( dp.count( { x, { 'r', {curcolor, start} } } ) == 0)
                        dp[{ x, { 'r', {curcolor, start} } }] = dfs(x, 'r', curcolor, start);
                    w = (w + dp[{ x, { 'r', {curcolor, start} } }] ) % MOD;
                    if ( dp.count( { x, { 'b', {curcolor, start} } } ) == 0)
                        dp[{ x, { 'b', {curcolor, start} } }] = dfs(x, 'b', curcolor, start);
                    w = (w + dp[{ x, { 'b', {curcolor, start} } }] ) % MOD;
	                waysplus = (waysplus*w) % MOD;
	            }
	        }
	        if ( j == 0 )
	        	return 0;
	        for ( auto x : tree[start]) {
	            if ( x != parent ) {
	                long long w = 0;
	                if ( dp.count( { x, { 'b', {curcolor, start} } } ) == 0)
                        dp[{ x, { 'b', {curcolor, start} } }] = dfs(x, 'b', curcolor, start);
                    w = (w + dp[{ x, { 'b', {curcolor, start} } }] ) % MOD;
	                waysminus = (waysminus*w) % MOD;
	            }
            }
            return (waysplus - waysminus + MOD)%MOD;
        }
        if ( curcolor == 'b' ) {
            long long ways = 1;
            long long waysplus = 1, waysminus = 1;
            long long j = 0;
	        for ( auto x : tree[start]) {
	            if ( x != parent ) {
		            j++;
	                long long w = 0;
	                if ( dp.count( { x, { 'r', {curcolor, start} } } ) == 0)
                        dp[{ x, { 'r', {curcolor, start} } }] = dfs(x, 'r', curcolor, start);
                    w = (w + dp[{ x, { 'r', {curcolor, start} } }] ) % MOD;
                    if ( dp.count( { x, { 'b', {curcolor, start} } } ) == 0)
                        dp[{ x, { 'b', {curcolor, start} } }] = dfs(x, 'b', curcolor, start);
                    w = (w + dp[{ x, { 'b', {curcolor, start} } }] ) % MOD;

	                waysplus = (waysplus*w) % MOD;
	            }
            }
            if ( j == 0 )
	        	return 0;
	        for ( auto x : tree[start]) {
	            if ( x != parent ) {
	                long long w = 0;
	                if ( dp.count( { x, { 'r', {curcolor, start} } } ) == 0)
                        dp[{ x, { 'r', {curcolor, start} } }] = dfs(x, 'r', curcolor, start);
                    w = (w + dp[{ x, { 'r', {curcolor, start} } }] ) % MOD;
	                waysminus = (waysminus*w) % MOD;
				}
            }
            return (waysplus - waysminus + MOD)%MOD;
        }
    }
    return 0;
}
int main() {
    //freopen("input.txt", "r", stdin);
    fio;
    long long n; cin >> n;
    tree.clear(); tree.resize(n+1);
    for ( long long i = 0; i < n-1; i++) {
    	long long a, b;
    	cin >> a >> b;
    	tree[a].push_back(b);
    	tree[b].push_back(a);
    }
    cout << (dfs(1, 'r', 'b', 0) + dfs(1, 'b', 'r', 0) )%MOD;
	return 0;
}
