#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ans;
vector<int> b;
vector<ll> ydp;
vector<ll> ndp;
void precompute(vector<int>& v) {
	ll n = v.size();
	if ( -v[0] + v[1] > 0)
		b[0] = 1;
	if ( -v[n-1] + v[n-2] > 0)
		b[n-1] = 1;
	for (int i = 1; i < n - 1; ++i) {
		if ( ( v[i-1] - v[i] > 0 ) && ( -v[i] + v[i + 1] > 0) ) {
			b[i] = 1;
		}
	}
}
void changesign(vector<int>& v) {
	ll n = v.size() - 1;
	if ( b[n-1] == 0 && b[n] == 0) {
		ydp[n] = v[n];
		ndp[n] = v[n];
		ydp[n-1] = v[n] + v[n-1];
		ndp[n-1] = v[n] + v[n-1];
	}
	if ( b[n-1] == 0 && b[n] == 1) {
		ydp[n] = -v[n];
		ndp[n] = v[n];
		ydp[n-1] = -v[n] + v[n-1];
		ndp[n-1] = v[n] + v[n-1];
	}
	if ( b[n-1] == 1 && b[n] == 0) {
		ydp[n] = v[n];
		ndp[n] = v[n];
		ydp[n-1] = v[n] - v[n-1];
		ndp[n-1] = v[n] + v[n-1];
	}
	for ( int i = n-2; i >= 0; i--) {
		if ( b[i] == 0) {
			ydp[i] = ydp[i+1] + v[i];
			ndp[i] = ndp[i+1] + v[i];
		}
		else {
			if ( b[i+2] == 1 ) {
				if ( -v[i] + v[i+1] - v[i+2] > 0 ) {
	 				ydp[i] = -v[i] + min(ydp[i+1], ndp[i+1]);
	 				ndp[i] = v[i] + min(ydp[i+1], ndp[i+1]);
	 			}
	 			else {
	 				ydp[i] = -v[i] + ndp[i+1];
	 				ndp[i] = v[i] +  min(ydp[i+1], ndp[i+1]);
	 			}
			}
			else {
				ydp[i] = -v[i] + min(ydp[i+1], ndp[i+1]);
				ndp[i] = v[i] + min(ydp[i+1], ndp[i+1]);
			}
		}
	}
	ll start =  min(ydp[0], ndp[0]);
	char state;
	if ( ydp[0] > ndp[0])
        state = 'n';
    else
        state = 'y';
	for ( int i = 0; i <= n; i++) {
		if ( b[i] == 0)
		    ans[i] = v[i];
		else {
			if ( b[i+2] == 1 ) {
				if ( -v[i] + v[i+1] - v[i+2] > 0 ) {
                    if ( state == 'y') {
                        start = start + v[i];
                        ans[i] = -v[i];
                        if ( ydp[i+1] > ndp[i+1] )
                            state = 'n';
                        else
                            state = 'y';
                    }
                    else if ( state == 'n') {
                        start = start - v[i];
                        ans[i] = v[i];
                        if ( ydp[i+1] > ndp[i+1] )
                            state = 'n';
                        else
                            state = 'y';
                    }
	 			}
	 			else {
                    if ( state == 'y') {
                        start = start + v[i];
                        ans[i] = -v[i];
                        state = 'n';
                    }
                    else if ( state == 'n') {
                        start = start - v[i];
                        ans[i] = v[i];
                        if ( ydp[i+1] > ndp[i+1] )
                            state = 'n';
                        else
                            state = 'y';
                    }
	 			}
			}
			else {
                if ( state == 'y') {
                    start = start + v[i];
                    ans[i] = -v[i];
                    if ( ydp[i+1] > ndp[i+1] )
                        state = 'n';
                    else
                        state = 'y';
                }
                 else if ( state == 'n') {
                    start = start - v[i];
                    ans[i] = v[i];
                    if ( ydp[i+1] > ndp[i+1] )
                        state = 'n';
                    else
                        state = 'y';
                }
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		ans.clear(); ans.resize(n);
		b.clear(); b.resize(n, 0);
		ndp.clear(); ndp.resize(n, 0);
		ydp.clear(); ydp.resize(n, 0);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		precompute(v);
		changesign(v);
		for ( int i = 0; i < n; i++)
            cout << ans[i] << " ";
		cout << endl;
	}
}
