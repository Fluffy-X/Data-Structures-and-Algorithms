/* Go Do Shit */
#include <bits/stdc++.h>
const int inf = (int)1e9;
using namespace std;
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
vector<int> tree(300005);
vector<int> v(100005);
void build(int i, int start, int end) {
	if ( start == end) {
		tree[i] = v[start];
		return ;
	}
	build(2*i+1, start, (start+end)/2);
	build(2*i+2, 1+(start+end)/2, end);
	tree[i] = min (tree[2*i+1], tree[2*i+2]);
}
int query(int start, int end, int qstart, int qend, int i) {
	if ( qstart <= start && end <= qend)
		return tree[i];
    else if ( qend < start || qstart > end)
        return inf;
	else
		return min( query(start, (start+end)/2, qstart, qend, 2*i+1), query(1+(start+end)/2, end, qstart, qend, 2*i+2));
}
void update(int val, int i, int start, int end, int index) {
	if ( start == end && start == index) {
		tree[i] = val;
		return ;
	}
	if ( start <= index && index <= end) {
		update ( val, 2*i+1, start, (start+end)/2, index);
		update ( val, 2*i+2, 1+(start+end)/2, end, index);
		tree[i] = min(tree[2*i+1], tree[2*i+2]);
	}
	return;
}
int main()
{
//    freopen("input.txt", "r", stdin);
	fio;
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++)
        cin >> v[i];
    build(0, 0, n-1);
    for ( int i = 0; i < q; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if ( c == 'q') {
            cout << query(0, n-1, a-1, b-1, 0) << endl;
        }
        else {
            update(b, 0, 0, n-1, a-1);
        }
    }
	return 0;
}
