#include <bits/stdc++.h>
using namespace std;
#define x first
#define height second
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
vector<pair<int, int> > v;
map<pair<int, int>, int> dp;
int recurse(int i, int prev) {
    if ( i == v.size() - 1)
        return 0;
    int rt = INT_MIN, lft = INT_MIN;
	if ( v[i].first + v[i].height < v[i+1].x ) {
		if ( dp.count({i+1, v[i].x + v[i].height}) == 0)
			dp[{i+1, v[i].x + v[i].height}] = recurse(i + 1, v[i].x + v[i].height);
		rt = 1 + dp[{i+1, v[i].x + v[i].height}];
	}
	if ( prev < v[i].x - v[i].height) {
		if ( dp.count({i + 1, v[i].x}) == 0)
			dp[{i + 1, v[i].x}] = recurse(i + 1, v[i].x);
		rt = 1 + dp[{i + 1, v[i].x}];
	}
	if ( dp.count({i + 1, v[i].x}) == 0)
		dp[{i + 1, v[i].x}] = recurse(i + 1, v[i].x);
	return max(rt, max(lft, dp[{i + 1, v[i].x}]));
}

int main() {
    //freopen("input.txt", "r", stdin);
    fio;
    int n; cin >> n;
    v.clear();
    dp.clear();
    v.resize(n);
    for ( int i = 0; i < n; i++) {
    	int a, b;
    	cin >> a >> b;
    	v[i] = {a, b};
    }
    if ( n <= 2)
        cout << n;
    else
        cout << 2 + recurse(1, v[0].x);
    return 0;
}
