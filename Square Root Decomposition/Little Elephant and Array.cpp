#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define N 311111
#define A 1111111
#define BLOCK 555 // ~sqrt(N)

int cnt[A], a[N], ans[N], answer = 0;

struct node {
	int L, R, i;
}q[N];

bool cmp(const node &x, const node &y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}

void add(int position) {
    if ( a[position] > (int)1e5 )
        return;
    if ( cnt[a[position]] == a[position])
		answer--;
    ++cnt[a[position]];
	if ( cnt[a[position]] == a[position])
		answer++;
}

void remove(int position) {
    if ( a[position] > (int)1e5 )
        return;
    if ( cnt[a[position]] == a[position] )
		answer--;
    cnt[a[position]]--;
	if ( cnt[a[position]] == a[position] )
		answer++;
}

int main() {
//    freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);

	for(int i=0; i<m; i++) {
		scanf("%d%d", &q[i].L, &q[i].R);
		q[i].L--; q[i].R--;
		q[i].i = i;
	}
	sort(q, q + m, cmp);
	int left = 0, right =0;
	add(0);
	for (int i = 0; i < m; i++) {
		while( left < q[i].L) {
			remove(left);
			left++;
//			cout << " A ";
		}
		while( right < q[i].R) {
			right++;
			add(right);
//			cout << " B ";
		}
		while( left > q[i].L) {
			left--;
			add(left);
//			cout << " C ";
		}
		while( right > q[i].R) {
			remove(right);
			right--;
//			cout << " D ";
		}
		ans[q[i].i] = answer;
//		cout << answer << " ";
	}
	for (int i = 0; i < m; i++)
		cout << ans[i] << endl;
}