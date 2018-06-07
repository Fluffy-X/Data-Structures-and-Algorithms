#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define INF -90000000000
int main() {
//    freopen("input.txt", "r", stdin);
    fio;
    int n, k; cin >> n >> k;
    int v[n];
    for ( int i = 0; i < n; i++)
    	cin >> v[i];
    vector<int> ans(n, 0);
    int sum = 0;
    ans[0] = 0;
    for ( int i = 1; i < n; i++) {
    	if ( ans[i-1] + v[i] + v[i-1] >= k)
    		ans[i] = 0;
    	else
    		ans[i] = k - ans[i-1] - v[i] - v[i-1];
    }
    for (int i = 0; i < n; ++i)
    	sum += ans[i];
    cout << sum << endl;
    for (int i = 0; i < n; ++i)
    	cout << ans[i] + v[i] << " ";
    return 0;
}
