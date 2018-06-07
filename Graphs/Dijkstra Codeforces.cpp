#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
vector<vector<pair<int,int> > > graph;
#define INF LLONG_MAX
class myComparator
{
public:
    int operator()(const pair<int, long long>& p1, const pair<int, long long>& p2)
    {
        return p1.second > p2.second;
    }
};
int main() {
//    freopen("input.txt", "r", stdin);
    fio;
    int n, m;
    cin >> n >> m;
    graph.resize(n+1);
    while(m--){
    	int a, b, c; cin >> a >> b >> c;
    	graph[a].push_back({b, c});
    	graph[b].push_back({a, c});
    }
    priority_queue<pair<int, long long>, vector<pair<int, long long> >,  myComparator > minheap;
    minheap.push({1, 0});
    vector<long long> ans(n+1, INF);
    ans[1] = 0;
    vector<int> visited(n+1, -1);
    vector<int> lastedge(n+1, -1);
    lastedge[1] = -1;
    while(!minheap.empty()) {
    	pair<int, long long> p = minheap.top();
    	minheap.pop();
    	visited[p.first] = 1;
    	for ( auto x : graph[p.first]) {
    		if ( (ans[x.first] > p.second + x.second) && (visited[x.first] == -1) ) {
                minheap.push({x.first, p.second + x.second});
                lastedge[x.first] = p.first;
                ans[x.first] = p.second + x.second;
            }
        }
    }
    long long i = n;
    vector<int> f;
    while(i != -1) {
        f.push_back(i);
        i = lastedge[i];
    }
    if ( ans[n] == INF)
        cout << -1;
    else {
        for ( long long j = f.size()-1; j >= 0; j--)
            cout << f[j] << " ";
    }
	return 0;
}
