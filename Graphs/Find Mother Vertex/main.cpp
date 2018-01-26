#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    int V;
    list<int> *adj;
    void addEdge(int u, int v);
    Graph(int v);
    void DFS(int start);
    vector<int> visited;
    vector<int> departure;
    vector<int> arrival;
    int c=0;
    void mothervertex();
};
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}
Graph::Graph(int v)
{
    V = v;
    adj = new list<int>[V];
    visited.resize(V,0);
    arrival.resize(V,0);
    departure.resize(V,0);
}
void Graph::DFS(int start)
{
    visited[start]=1;
    arrival[start]=c;
    for(auto itr=adj[start].begin(); itr!=adj[start].end(); itr++)
    {
        if(visited[*itr]==0)
        {
            c++;
            DFS(*itr);
        }
    }
    c++;
    departure[start]=c;
}
void Graph::mothervertex()
{
    for(int i=0; i<V; i++)
    {
        if(visited[i]==0)
            DFS(i);
    }
    int max=-1;
    int index;
    for(int i=0; i<V; i++)
    {
        if(departure[i]>max)
        {
            max = departure[i];
            index = i;
        }
    }
    c=0;
    std::fill(visited.begin(), visited.end(), 0);
    DFS(index);
    for(int i=0; i<V; i++)
    {
        if(visited[i]==0)
        {
            cout << "No Mother Vertex Exist";
            return;
        }
    }
    cout << "Mother Vertex is : " << index ;

}
int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);
    g.mothervertex();
    return 0;
}
