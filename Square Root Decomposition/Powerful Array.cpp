#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
#define blocksize 800
using namespace std;
long long cursum;
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
int v[200005];
int um[1000005]; // val, freq
void add(int i) {
    cursum += (2*um[v[i]]+1) * v[i];
    um[v[i]]++;
}
void remove(int i) {
	cursum -= v[i]*(2*um[v[i]]-1);
	um[v[i]]--;
}
int main() {
    fio;
//    freopen("input.txt", "r", stdin);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> v[i];
	vector<node> queries;
	for(int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		queries.push_back({a-1, b-1, i});
	}
	sort(queries.begin(), queries.end(), cmp);
	vector<long long> ans(q);
	int L = 0; int R = 0;
	um[v[0]]++;
	cursum = v[0];
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
	for (auto x : ans)
		cout << x << endl;
	return 0;
}