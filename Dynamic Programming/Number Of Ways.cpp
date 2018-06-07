#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)


int main() {
    //freopen("input.txt", "r", stdin);
    fio;
  	long long n, ans = 0, s = 0;
  	cin >> n;
  	vector<long long> v(n), Prefix(n, 0), Prefixfor2s(n, 0);
  	for ( long long i = 0; i < n; i++) {
  		cin >> v[i];
  		s += v[i];
  	}
  	if ( s % 3 != 0)
  		cout << 0;
  	else {
  		s = s / 3;
  		Prefix[0] = v[0];
  		if ( v[0] == 2*s)
            Prefixfor2s[0] = 1;
  		for ( long long i = 1; i < n; i++)
  			Prefix[i] = Prefix[i-1] + v[i];
  		for ( long long i = 1; i < n; i++) {
  			if ( Prefix[i] == 2*s)
                Prefixfor2s[i] = Prefixfor2s[i-1] + 1;
            else
                Prefixfor2s[i] = Prefixfor2s[i-1];
  		}
  		for ( long long i = 0; i <= n-2; i++) {
  			if ( Prefix[i] == s)
  				ans += Prefixfor2s[n - 2] - Prefixfor2s[i];
  		}
        cout << ans;
  	}
    return 0;
}
