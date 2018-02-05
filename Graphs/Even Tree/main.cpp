#include <bits/stdc++.h>
using namespace std;

class Graph{
  public:
    int V;
    list<int> *adj;
    void addEdge(int u, int v);
    vector<int> distance;
    vector<int> visited;
    int DFS(int start);
    Graph(int v);
};
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
Graph::Graph(int v)
{
    adj = new list<int>[v];
    V = v;
    distance.resize(V,0);
    visited.resize(V,0);
}
int Graph::DFS(int start)
{
    visited[start] = 1;
    for(auto itr=adj[start].begin(); itr!=adj[start].end(); itr++)
    {
        if(visited[*itr]==0)
        {
            distance[start] += DFS(*itr);
        }
    }
    distance[start]++;
    return distance[start];
}
int evenTree(int n, int m, vector < vector<int> > tree) {
    // Complete this function
    if(n%2==1)
        return 0;
    else
    {
        Graph g(n);
        for(int i=0; i<m; i++)
        {
            g.addEdge(tree[i][0]-1,tree[i][1]-1);
        }
        g.DFS(0);
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(g.distance[i]%2==0)
                ans++;
        }
        return ans-1;
    }
}
int main() {
    int n;
    int m;
    cin >> n >> m;
    vector< vector<int> > tree(m,vector<int>(2));
    for(int tree_i = 0;tree_i < m;tree_i++){
       for(int tree_j = 0;tree_j < 2;tree_j++){
          cin >> tree[tree_i][tree_j];
       }
    }
    int result = evenTree(n, m, tree);
    cout << result << endl;
    return 0;
}
