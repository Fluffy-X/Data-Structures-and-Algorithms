#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl "\n"
using namespace std;
long long v[100005], segtree[300005], lazy[300005];
void update(long long ql, long long qr, long long l, long long r, long long val, long long i) {
	
	if ( qr < l || ql > r ) {
		lazy[2*i+1] += lazy[i];
		lazy[2*i+2] += lazy[i];
		segtree[i] += lazy[i]*(r-l+1);
		lazy[i] = 0;
	}
	else if ( ql <= l && qr >= r) {
		lazy[2*i+1] += lazy[i] + val;
		lazy[2*i+2] += lazy[i] + val;
		segtree[i] += (lazy[i] + val)*(r-l+1);
	}
	else {
		lazy[2*i+1] += lazy[i];
		lazy[2*i+2] += lazy[i];
		update(ql,qr,l,(l+r)/2,val,2*i+1);
		update(ql,qr,1+(l+r)/2,r,val,2*i+2);
		segtree = segtree[2*i+1] + segtree[2*i+2];
		lazy[i] = 0;
	}
}
long long query(long long ql, long long qr, long long l, long long r, long long i) {
	long long ans = 0;
	if ( qr < l || ql > r ) {
		lazy[2*i+1] += lazy[i];
		lazy[2*i+2] += lazy[i];
		segtree[i] += lazy[i]*(r-l+1);
		lazy[i] = 0;
		return 0;
	}
	else if ( ql <= l && qr >= r) {
		lazy[2*i+1] += lazy[i];
		lazy[2*i+2] += lazy[i];
		segtree[i] += (lazy[i])*(r-l+1);
		return segtree[i];
	}
	else {
		lazy[2*i+1] += lazy[i];
		lazy[2*i+2] += lazy[i];
		ans += query(ql,qr,l,(l+r)/2,2*i+1);
		ans += query(ql,qr,1+(l+r)/2,r,2*i+2);
		segtree = segtree[2*i+1] + segtree[2*i+2];
		lazy[i] = 0;
		return ans;
	}
	
}

int main() {
//    freopen("input.txt", "r", stdin);
    fio;
    long long t;
    cin >> t;
    while(t--) {
    	long long n, c;
    	cin >> n >> c;
    	for (long long i = 0; i < c; i++) {
    		long long type, l, r;
    		cin >> type >> l >> r;
    		if ( type == 0) {
    			long long val;
    			cin >> val;
    			update( l-1, r-1, 0, n-1, val, 0);
    		}
    		else {
    			cout << query(l-1, r-1, 0, n-1, 0) << endl;
    		}
    	}
    }
//    update( 0, 5, 0, 6, 5, 0);
//
//    for ( long long i = 0; i < 20; i++) cout << i << " " << segtree[i] << endl;
	return 0;
}
