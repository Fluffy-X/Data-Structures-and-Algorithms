#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    int V;
    list<pair<int,int> > *adj;
    void addEdge(int u, int v, int w);
    Graph(int ve);
    int SSHP_recursive(int u, int v, int k);//
    int SSHP_DP(int u, int v);
    std::vector<std::vector<int>> memo;
    void preDP(int u, int v);
};
Graph::Graph(int ve)
{
    V = ve;
    adj = new list<pair<int,int> >[V];
   // vector<vector<int> > memo;
    memo.resize(V);
    for (int i = 0; i < V; ++i)
        memo[i].resize(V,10000);

}
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
int Graph::SSHP_recursive(int u, int v, int k) // initially k = V-1
{
    int ans = 10000;
    if(u==v)
        return 0;
    if(k==0)
    {
        if(u!=v)
            return 10000;
        else
            return 0;
    }
    for(auto itr=adj[u].begin(); itr!=adj[u].end(); itr++)
        ans = min(ans, SSHP_recursive(itr->first,v,k-1)+itr->second);
    return ans;
}
int Graph::SSHP_DP(int u, int v) // initially k = V-1
{
    int ans = 10000;
    for(int i=2; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            for(auto itr=adj[j].begin(); itr!=adj[j].end(); itr++)
                ans = min(ans, memo[i-1][itr->first]+itr->second);
            memo[i][j] = min(ans,memo[i-1][j]);
            ans = 10000;
        }
    }
    for(int i=1; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }
}
void Graph::preDP(int u, int v)
{
    memo.resize(V);
    for (int i = 0; i < V; ++i)
        memo[i].resize(V,10000);
    memo[0][v] = 0;
    for(int i=0; i<V; i++)
    {
        for(auto itr=adj[i].begin(); itr!=adj[i].end(); itr++)
        {
            if(itr->first==v)
                memo[1][i] = itr->second;
        }

    }
    SSHP_DP(u,v);

}
int main()
{
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.preDP(2,4);

    return 0;
}
