#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
vector<int> dp(1000001);
vector<vector<int> > Prefix(10, vector<int>(1000001, 0));
int dfs(int val) {
	if ( val < 10)
		return val;
	int t = val;
	int ans = 1;
	while(t != 0) {
        if ( t % 10 != 0)
             ans *= (t % 10);
		t = t / 10;
	}
	return dfs(ans);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //fio;
    int n; cin >> n;
    for (int i = 1; i <= 1000000; i++) {
    	int val = dfs(i);
        for ( int j = 1; j <= 9; j++) {
        	if ( j == val)
        		Prefix[val][i] = Prefix[val][i - 1]+1;
        	else
                Prefix[j][i] = Prefix[j][i - 1];
        }
    }
    while(n--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << Prefix[k][r] - Prefix[k][l-1] << endl;
    }
    return 0;
}
