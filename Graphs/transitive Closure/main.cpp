#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    int V;
    list<int> *adj;
    void addEdge(int u, int v);
    Graph(int v);
    void DFS(int start, int first);
    vector<int> visited;
    void resetvisited();
    int c=0;
    vector<vector<bool> > vec;
    void transitive();
};
void Graph::resetvisited()
{
    fill(visited.begin(),visited.end(),0);
}
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}
Graph::Graph(int v)
{
    V = v;
    adj = new list<int>[V];
    vec.resize(V,vector<bool>(V,0));
    visited.resize(V,0);
}
void Graph::DFS(int start,int first)
{
    vec[first][start]=1;
    visited[start]=1;
    for(auto itr=adj[start].begin(); itr!=adj[start].end(); itr++)
    {
        if(visited[*itr]==0)
        {
            c++;
            DFS(*itr,first);
        }
    }
    c++;
}
void Graph::transitive()
{
    for(int i=0; i<V; i++)
    {
        DFS(i,i);
        resetvisited();
    }
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
    Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
    g.addEdge(4, 3);
    g.addEdge(2, 4);
    g.transitive();

    return 0;
}
