#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define INF LLONG_MAX
int n, m;
vector<vector<pair<int,int> > > railmap, roadmap;
vector<long long> rail, road;
class myComparator {
public:
    int operator()(const pair<int, long long>& p1, const pair<int, long long>& p2) {
        return p1.second > p2.second;
    }
};
long long finalc=INF;
vector<int> railvisited, roadvisited;
void rec(int railstart, int roadstart, int distance) {
	railvisited[railstart] = 1; roadvisited[roadstart] = 1;
	if ( railstart == n) {
		finalc = min ( finalc, distance + road[roadstart]);
		return;
	}
	if ( roadstart == n) {
		finalc = min ( finalc, distance + rail[railstart]);
		return;
	}

	for ( auto x : railmap[railstart]) {
		if ( railvisited[x.first] == -1) {
			for ( auto y : roadmap[roadstart]) {
				if ( roadvisited[y.first] == -1) {
					rec(x.first, y.first, distance+1);
                }
            }
        }
	}
	return;
}
int main() {
//    freopen("input.txt", "r", stdin);
    fio;
    cin >> n >> m;
    railmap.resize(n+1);
    rail.resize(n+1, INF);
    road.resize(n+1, INF);
    railvisited.resize(n+1, -1);
    roadvisited.resize(n+1, -1);
    roadmap.resize(n+1);
    while(m--){
    	int a, b; cin >> a >> b;
    	railmap[a].push_back({b, 1});
    	railmap[b].push_back({a, 1});
    }
    for ( int i = 1; i <= n; i++) {
    	unordered_set<int> us;
    	for ( auto x : railmap[i]) {
    		us.insert(x.first);
    	}
    	for ( int j = 1; j <= n; j++) {
    		if ( us.find(j) == us.end()) {
    			roadmap[i].push_back({j, 1});
    			roadmap[j].push_back({i, 1});
    		}
    	}
    }
    priority_queue<pair<int, long long>, vector<pair<int, long long> >,  myComparator > minheap;
    minheap.push({1, 0});
    rail[1] = 0;
    vector<int> visited(n+1, -1);
    while(!minheap.empty()) {
    	pair<int, long long> p = minheap.top();
    	minheap.pop();
    	visited[p.first] = 1;
    	for ( auto x : railmap[p.first]) {
    		if ( (rail[x.first] > p.second + x.second) && (visited[x.first] == -1) ) {
                minheap.push({x.first, p.second + x.second});
                rail[x.first] = p.second + x.second;
            }
        }
    }
    minheap.push({1, 0});
    road[1] = 0;
    fill(visited.begin(), visited.end(), -1);
    while(!minheap.empty()) {
    	pair<int, long long> p = minheap.top();
    	minheap.pop();
    	visited[p.first] = 1;
    	for ( auto x : roadmap[p.first]) {
    		if ( (road[x.first] > p.second + x.second) && (visited[x.first] == -1) ) {
                minheap.push({x.first, p.second + x.second});
                road[x.first] = p.second + x.second;
            }
        }
    }
    if ( road[n] == INF || rail[n] == INF) {
        cout << -1;
    }
    else {
        cout << max( road[n], rail[n]);
    }
	return 0;
}
