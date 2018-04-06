#include <bits/stdc++.h>
using namespace std;
vector<int> visited(100005,0);
vector<int> graph[100005];

int dfs ( int start, int d) {
    visited[start] = 1;
    for (auto itr = graph[start].begin(); itr != graph[start].end(); itr++) {
        if (visited[*itr] == 0)
            return dfs( *itr, d+1);
        else
            return d+1;
    }
    return -1;
}

int lilysHomework(vector <int>& orig) {
    map<int,int> m;
    vector<int> o = orig;
    int index;
	std::vector<int> sorted = orig;
	sort(sorted.begin(), sorted.end());
	for (int i = 0; i < orig.size(); i++) {
		m.insert(make_pair(sorted[i],i));
	}
    for ( int i = 0; i < orig.size(); i++) {
        auto itr = m.find(orig[i]);
        index = itr->second;
        if (index != i)
            graph[i].push_back(index);
    }
    /*for ( int i = 0; i < orig.size(); i++) {
            cout << i << " ";
        for ( auto itr = graph[i].begin(); itr != graph[i].end(); itr++) {
            cout << *itr << " ";
        }
        cout << endl;
    }*/
    int ans=0;
    int temp = 0;
    for ( int i = 0; i < orig.size(); i++ ) {
        if (visited[i] == 0) {
            temp = dfs( i, 0);
            if (temp != -1)
                ans += temp-1;
        }
    }
   // cout << ans << " go" << endl;
    fill(visited.begin(), visited.end(), 0);
    for ( int i = 0 ; i < 100005; i++) {
        graph[i].clear();
    }
    int a = INT_MAX;
    a = min (a, ans);
    ans=0;
    temp = 0;
    map<int,int> md;
	sort(sorted.begin(), sorted.end(), greater<int>());
	for (int i = 0; i < o.size(); i++) {
		md.insert(make_pair(sorted[i],i));
	}
    for ( int i = 0; i < o.size(); i++) {
        auto itr = md.find(o[i]);
        index = itr->second;
        if (index != i)
            graph[i].push_back(index);
    }
    for ( int i = 0; i < orig.size(); i++ ) {
        if (visited[i] == 0) {
            temp = dfs( i, 0);
            if (temp != -1)
                ans += temp-1;
        }
    }
    //cout << ans << " go" << endl;

    return min(ans,a);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int a[5] = {1,2,3,4,5};
    int result = lilysHomework(arr);
    cout << result << endl;
    return 0;
}
