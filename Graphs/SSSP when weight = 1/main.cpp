#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    int V;
    list<int> *adj;
    void addEdge(int u, int v);
    vector<int> visited;
    vector<int> d;
    Graph(int v);
    void sshp_using_BFS(int source);
    void print(int source);
};
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);

}
void Graph::print(int source)
{
    sshp_using_BFS(source);
    for(int i=0; i<V; i++)
        cout << i << " -> " << d[i] << endl;
}
void Graph::sshp_using_BFS(int source)
{
    queue<int> q;
    q.push(source);
    d[source]=0;
    while(!q.empty())
    {
        visited[q.front()] = 1;
        for(auto itr=adj[q.front()].begin(); itr!=adj[q.front()].end(); itr++)
        {
            if(visited[*itr]==0)
            {
                d[*itr] = d[q.front()]+1;
                q.push(*itr);
                visited[*itr] = 1;
            }
        }
        q.pop();
    }
}
Graph::Graph(int v)
{
    V=v;
    adj = new list<int>[v];
    d.resize(V,10000);
    visited.resize(V,0);
}
int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.print(0);
    return 0;
}
