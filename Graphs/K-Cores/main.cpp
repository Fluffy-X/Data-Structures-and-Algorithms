#include <bits/stdc++.h>
using namespace std;
class Graph{
public:
    list<int> *adj;
    void addEdge(int u, int v);
    Graph(int v);
    int V;
    vector<int> arrival;
    vector<int> departure;
    vector<int> visited;
    vector<int> degree;
    void DFS(int start);
    void k_cores(int k);
};
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    degree[u]++;
    degree[v]++;
    adj[v].push_back(u);
}
void Graph::k_cores(int k)
{
    int vertices=0;
    for(int i=0; i<V; i++)
    {
        if(degree[i] < k && degree[i]!=0)
        {
            vertices++;
            for(auto itr=adj[i].begin(); itr!=adj[i].end(); itr++)
            {
                adj[*itr].remove(i);
                degree[*itr]--;
            }
            adj[i].erase(adj[i].begin(),adj[i].end());
            degree[i]=0;
            i=0;
        }
    }
    for(int i=0; i<V; i++)
    {
        if(degree[i]!=0)
        {
            cout << "[" << i << "] -> ";
            for(auto itr=adj[i].begin(); itr!=adj[i].end(); itr++)
            {
                cout << *itr;
                itr++;
                if(itr==adj[i].end())
                    break;
                else
                {
                    itr--;
                    cout << " -> ";
                }
            }
            cout << endl;
        }
    }
}
Graph::Graph(int v)
{
    V = v;
    adj = new list<int>[V];
    visited.resize(V,0);
    degree.resize(V,0);
}
void Graph::DFS(int start)
{
    visited[start]=1;
    for(auto itr=adj[start].begin(); itr!=adj[start].end(); itr++)
    {
        if(visited[*itr]==0)
        {
            DFS(*itr);
        }
    }
}
int main ()
{
    Graph g1(9);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 5);
    g1.addEdge(2, 3);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);
    g1.addEdge(2, 6);
    g1.addEdge(3, 4);
    g1.addEdge(3, 6);
    g1.addEdge(3, 7);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(5, 8);
    g1.addEdge(6, 7);
    g1.addEdge(6, 8);
    g1.k_cores(3);

    return 0;
}
