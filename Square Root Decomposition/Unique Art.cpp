#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
#define blocksize 1000
using namespace std;
int cursum;
struct node {
	int start;
	int end;
	int index;
};
bool cmp( const node &a, const node &b) {
	if ( a.start/blocksize == b.start/blocksize)
		return a.end < b.end;
	return a.start < b.start;
}
vector<int> v;
vector<int> mod;
set<int> st;
int um[1000005];
void add(int i) {
    if ( um[v[i]] == 0 ) {
    	cursum++;
    	um[v[i]]++;
    }
    else if (um[v[i]] == 1) {
		cursum--;
		um[v[i]]++;
    }
    else {
    	um[v[i]]++;
    }
}
void remove(int i) {
	if ( um[v[i]] == 2) {
    	cursum++;
    	um[v[i]]--;
    }
    else if (um[v[i]] == 1) {
		cursum--;
		um[v[i]]--;
    }
    else {
        um[v[i]]--;
    }
}
int main() {
    fio;
    //freopen("input.txt", "r", stdin);
	int n, q;
	cin >> n;
	v.resize(n);
    // Compression Starts
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		st.insert(v[i]);
	}
    mod.resize(n);
    int kcount = 1;
    unordered_map<int, int> hsh;
    for (auto x : st) {
        hsh[x] = kcount;
        kcount++;
    }
    for (int i = 0; i < n; i++) {
        v[i] = hsh[v[i]];
    }
    // Compression Ends 
    // Mo's Algorithm Starts
    cin >> q;
	vector<node> queries;
	for(int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		queries.push_back({a-1, b-1, i});
	}
	sort(queries.begin(), queries.end(), cmp);
	vector<int> ans(q);
	int L = 0; int R = 0;
	um[v[0]]++;
	cursum = 1;
	for (int i = 0; i < q; i++) {
		while ( L < queries[i].start) {
			remove(L);
			L++;
		}
		while( L > queries[i].start) {
			L--;
			add(L);
		}
		while ( R > queries[i].end) {
			remove(R);
			R--;
		}
		while ( R < queries[i].end) {
			R++;
			add(R);
		}
		ans[queries[i].index] = cursum;
	}
	for (auto &x : ans)
		cout << x << endl;
	return 0;
}
