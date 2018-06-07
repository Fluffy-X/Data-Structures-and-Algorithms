#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int n, ans;
vector<int> v;
map<int, int> dp;
int main() {
//    freopen("input.txt", "r", stdin);
    fio;
    cin >> n;
    v.resize(n);
	vector<int> ansv, nobugsplease(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	dp[v[n-1]] = 1;
	nobugsplease[n-1] = 1;
	int index;
	for ( int i = n-2; i >= 0; i--) {
		dp[v[i]] = dp[v[i]+1] + 1;
		nobugsplease[i] = dp[v[i]];
		if ( ans < dp[v[i]]) {
			index = i;
            ans = max(ans, dp[v[i]]);
		}
	}
	if ( n == 1) {
        cout << 1 << endl << 1;
        return 0;
	}
	cout << ans << endl;
	ansv.push_back(index);
	int i = index+1;
	for ( ; i < n; i++) {
		if ( (nobugsplease[index] == 1 + nobugsplease[i]) && (v[index] + 1 == v[i]) ) {
			ansv.push_back(i);
			index = i;
		}
	}
	for ( int j = 0; j < ans; j++)
		cout << ansv[j]+1 << " ";
    return 0;
}
