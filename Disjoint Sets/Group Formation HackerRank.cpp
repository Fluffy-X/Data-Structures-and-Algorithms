#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
vector<int> disjoint, rankd, firstsize, secondsize, thirdsize;
unordered_map<string, int> um;
unordered_map<string, int> strtonum;
int n, m, minimum, maximum, maxfirst, maxsecond, maxthird;
void uniond(int a, int b) {
	int roota = a, rootb = b;
	while(disjoint[roota] != roota)
		roota = disjoint[roota];
	while(disjoint[rootb] != rootb)
		rootb = disjoint[rootb];
	if ( rankd[roota] + rankd[rootb] > maximum)
		return;
	if ( firstsize[roota] + firstsize[rootb] > maxfirst)
		return;
	if ( secondsize[roota] + secondsize[rootb] > maxsecond)
		return;
	if ( thirdsize[roota] + thirdsize[rootb] > maxthird)
		return;
	if ( rankd[roota] > rankd[rootb]) {
		rankd[roota] += rankd[rootb];
		firstsize[roota] += firstsize[rootb];
		secondsize[roota] += secondsize[rootb];
		thirdsize[roota] += thirdsize[rootb];
		disjoint[rootb] = disjoint[roota];
	}
	else {
		rankd[rootb] += rankd[roota];
		firstsize[rootb] += firstsize[roota];
		secondsize[rootb] += secondsize[roota];
		thirdsize[rootb] += thirdsize[roota];
		disjoint[roota] = disjoint[b];
	}
}
int findd(int a, int b) {
	int roota = a, rootb = b;
	while(disjoint[roota] != roota) {
		roota = disjoint[roota];
	}
	while(disjoint[rootb] != rootb) {
		rootb = disjoint[rootb];
	}
	if ( disjoint[roota] == disjoint[rootb] )
		return 1;
	return 0;
}
int main() {
    //freopen("input.txt", "r", stdin);
    fio;
    cin >> n >> m >> minimum >> maximum >> maxfirst >> maxsecond >> maxthird;
    disjoint.clear(); disjoint.resize(n, 0);
	rankd.clear(); rankd.resize(n, 1);
	for ( int i = 0; i < n; i++)
		disjoint[i] = i;
    unordered_map<string, int> um;
    unordered_map<string, int> strtonum;
    unordered_map<int, string> numtostr;
 	firstsize.clear(); firstsize.resize(n, 0);
	secondsize.clear(); secondsize.resize(n, 0);
	thirdsize.clear(); thirdsize.resize(n, 0);
    for ( int i = 0; i < n; i++) {
    	int itemp; string stemp;
    	cin >> stemp >> itemp;
    	//um[stemp] = itemp;
    	strtonum[stemp] = i;
    	numtostr[i] = stemp;
    	if ( itemp == 1)
    		firstsize[i] = 1;
    	if ( itemp == 2)
    		secondsize[i] = 1;
    	if ( itemp == 3)
    		thirdsize[i] = 1;
    }
    for ( int i = 0; i < m; i++) {
    	string parse1, parse2;
    	cin >> parse1 >> parse2;
    	if ( findd(strtonum[parse1], strtonum[parse2]) == 0)
            uniond(strtonum[parse1], strtonum[parse2]);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
    	if ( ans <= rankd[i]) {
    		ans = rankd[i];
    	}
    }
    set<string> finald;
    if ( ans == 1 || ans < minimum)
    	cout << "no groups";
    else {
        for (int j = 0; j < n; ++j)
        {
            if ( ans == rankd[j]) {
                for ( int i = 0; i < n; i++) {
                    if ( findd( disjoint[j], i))
                        finald.insert(numtostr[i]);
                }
            }
        }
    }
    for ( auto x : finald)
    	cout << x << endl;
    return 0;
}
