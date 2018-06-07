#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int ans = 1;
	for ( int i = 0; i < n - 1; i++) {
		int t = 1;
		while ( v[i] <= v[i+1]) {
			t++;
			//cout << "t : " << t << endl;
			ans = max(ans, t);
			i++;
			if ( i == n - 1)
                break;
		}
	}
	cout << ans;
	return 0;
}
