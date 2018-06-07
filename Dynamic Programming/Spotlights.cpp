#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n, m, ans = 0;
	cin >> n >> m;
	vector<vector<int> > v(n, vector<int>(m));
	for ( int i = 0; i < n; i++) {
		for ( int j = 0; j < m; j++)
			cin >> v[i][j];
	}
	if ( n == 1 && m == 1) {
        cout << 0;
        return 0;
	}
	if ( n == 1) {
        vector<int> Prefix(m, 0);
        vector<int> Suffix(m, 0);
        Prefix[0] = v[0][0];
        Suffix[m-1] = v[0][m-1];
        for ( int i = 1; i < m; i++) {
            Prefix[i] = Prefix[i-1] + v[0][i];
        }
        for ( int i = m - 2; i >= 0; i--) {
            Suffix[i] = Suffix[i+1] + v[0][i];
        }
        for ( int i = 1; i < m-1; i++) {
            if ( v[0][i] == 0) {
                if (Prefix[i-1] >= 1)
                    ans++;
                if (Suffix[i+1] >= 1)
                    ans++;
            }
        }
        if ( v[0][0] == 0 && Suffix[1] >= 1) {
            ans++;
        }
        if ( v[0][m-1] == 0 && Prefix[m-1] >= 1) {
            ans++;
        }
        cout << ans;
        return 0;
	}
	else if( m == 1) {
        vector<vector<int> > vprime(1, vector<int>(n));
        for ( int i = 0; i < n; i++)
            vprime[0][i] = v[i][0];
        v.clear();
        v = vprime;
        m = n;
        vector<int> Prefix(m, 0);
        vector<int> Suffix(m, 0);
        Prefix[0] = v[0][0];
        Suffix[m-1] = v[0][m-1];
        for ( int i = 1; i < m; i++) {
            Prefix[i] = Prefix[i-1] + v[0][i];
        }
        for ( int i = m - 2; i >= 0; i--) {
            Suffix[i] = Suffix[i+1] + v[0][i];
        }
        for ( int i = 1; i < m-1; i++) {
            if ( v[0][i] == 0) {
                if (Prefix[i-1] >= 1)
                    ans++;
                if (Suffix[i+1] >= 1)
                    ans++;
            }
        }
        if ( v[0][0] == 0 && Suffix[1] >= 1) {
            ans++;
        }
        if ( v[0][m-1] == 0 && Prefix[m-1] >= 1) {
            ans++;
        }
        cout << ans;
        return 0;
	}
	else {
        vector<vector<int>> L_R(n, vector<int>(m, 0));
	vector<vector<int>> R_L(n, vector<int>(m, 0));
	vector<vector<int>> T_B(n, vector<int>(m, 0));
	vector<vector<int>> B_T(n, vector<int>(m, 0));
	for ( int i = 0; i < n; i++) {
		for ( int j = 0; j < m; j++) {
			if ( j == 0)
				L_R[i][j] = v[i][j];
			else
				L_R[i][j] = L_R[i][j-1] + v[i][j];
		}
	}
	for ( int i = n - 1; i >= 0; i--) {
		for ( int j = m - 1; j >= 0; j--) {
			if ( j == m - 1)
				R_L[i][j] = v[i][j];
			else
				R_L[i][j] = R_L[i][j+1] + v[i][j];
		}
	}
	for ( int j = 0; j < m; j++) {
		for ( int i = 0; i < n; i++) {
			if ( i == 0)
				T_B[i][j] = v[i][j];
			else
				T_B[i][j] = T_B[i - 1][j] + v[i][j];
		}
	}
	for ( int j = m - 1; j >= 0; j--) {
		for ( int i = n - 1; i >= 0; i--) {
			if ( i == n - 1)
				B_T[i][j] = v[i][j];
			else
				B_T[i][j] = B_T[i + 1][j] + v[i][j];
		}
	}
	for ( int i = 1; i < n-1; i++) {
		for ( int j = 1; j < m-1; j++) {
			if ( v[i][j] == 0) {
				if ( B_T[i+1][j] >= 1)
					ans++;
				if ( T_B[i-1][j] >= 1)
					ans++;
				if ( L_R[i][j-1] >= 1)
					ans++;
				if ( R_L[i][j+1] >= 1)
					ans++;
			}
		}
	}
	for ( int i = 1; i < n - 1; i++) {
		if ( v[i][0] == 0) {
			if ( B_T[i+1][0] >= 1)
				ans++;
			if ( T_B[i-1][0] >= 1)
				ans++;
			if ( R_L[i][1] >= 1)
				ans++;
		}
	}
	for ( int i = 1; i < n - 1; i++) {
		if ( v[i][m-1] == 0) {
			if ( B_T[i+1][m-1] >= 1)
				ans++;
			if ( T_B[i-1][m-1] >= 1)
				ans++;
			if ( L_R[i][m-2] >= 1)
				ans++;
		}
	}
	for ( int j = 1; j < m - 1; j++) {
		if ( v[0][j] == 0) {
			if ( B_T[1][j] >= 1)
				ans++;
			if ( L_R[0][j-1] >= 1)
				ans++;
			if ( R_L[0][j+1] >= 1)
				ans++;
		}
	}
	for ( int j = 1; j < m - 1; j++) {
		if ( v[n-1][j] == 0) {
			if ( L_R[n-1][j-1] >= 1)
				ans++;
			if ( R_L[n-1][j+1] >= 1)
				ans++;
			if ( T_B[n-2][j] >= 1)
				ans++;
		}
	}
	if ( v[0][0] == 0 ) {
		if ( B_T[1][0] >= 1 )
			ans++;
		if ( R_L[0][1] >= 1 )
			ans++;
	}
	if ( v[n-1][m-1] == 0 ) {
		if ( L_R[n-1][m-2] >= 1)
			ans++;
		if ( T_B[n-2][m-1] >= 1)
			ans++;
	}
	if ( v[0][m-1] == 0 ) {
		if ( L_R[0][m-2] >= 1 )
			ans++;
		if ( B_T[1][m-1] >= 1 )
			ans++;
	}
	if ( v[n-1][0] == 0 ) {
		if ( T_B[n-2][0] >= 1 )
			ans++;
		if ( R_L[n-1][1] >= 1)
			ans++;
	}
	cout << ans ;
	return 0;
	}
}
