#include <bits/stdc++.h>
using namespace std;
struct node {
	int startORend;
	char c;
};

bool cmp (const node &a, const node &b) {
	return a.startORend < b.startORend;
}

int main() {
	int n;
	cin >> n;
	vector<node> v;
	for( int i = 0; i < n; i++) {
		int s;
		cin >> s;
		int e;
		cin >> e;
		v.push_back({s, 's'});
		v.push_back({e, 'e'});
	}
	sort(v.begin(), v.end(), cmp);
	int cur = 0, ans = 0, mincandies;
	for (int i = 0; i < v.size(); i++) {
		if( v[i].c == 's') {
			cur++;
			if ( ans < cur) {
				ans = cur;
				mincandies = v[i].startORend;
			}
		}
		else {
			cur--;
		}
	}
	cout << mincandies << " " << ans;

}
