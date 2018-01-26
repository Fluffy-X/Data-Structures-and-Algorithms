#include <iostream>
#include <vector>

using namespace std;
int count=0;
int min(int a, int b)
{
    if(a>b)
        return b;
    else
        return a;
}
class Graph
{
    public:
    int V;
    vector<int> *adj;
    vector<int> arrival;
    vector<int> visited;
    vector<int> departure;
    Graph(int x);
    void DFS(int start);
    void add_edge(int u, int v);
    int two_vertex_connectivity(int current, int parent);
    int twoVC(int current, int parent);
};
int Graph::two_vertex_connectivity(int current, int parent)
{
    DFS(0);
    fill(visited.begin(),visited.end(),0);
    return twoVC(current, parent);
}
int Graph::twoVC(int current, int parent)
{
    visited[current]=1;
    int a=1000, b=1000, b1=1000, a1=1000;
    vector<int>::iterator it;
    for(it=adj[current].begin(); it!=adj[current].end(); it++)
    {
        if(visited[*it]==0)
        {
            b1=twoVC(*it,current);
            if(b1>arrival[parent])
                return -1;
            else
                b = min(b1,b);
        }
    }
    if(b!=1000)
        return b;
    for(it=adj[current].begin(); it!=adj[current].end(); it++)
    {
        if(*it!=parent)
        {
            a1=arrival[*it];
            a=min(a,a1);
        }
    }
    return a;
}
Graph::Graph(int x )
{
    V = x;
    adj = new vector<int> [V];
    arrival.resize(V);
    visited.resize(V);
    departure.resize(V);
}
void Graph::add_edge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Graph::DFS(int start)
{
    visited[start]=1;
    arrival[start] = count;
    vector<int>::iterator it;
    for(it=adj[start].begin(); it!=adj[start].end(); it++)
    {
        if(visited[*it]!=1)
        {
            count++;
            DFS(*it);
        }
    }
    count++;
    departure[start] = count;
}

int main()
{
    Graph g(8);
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(3,4);
    g.add_edge(4,5);
    g.add_edge(2,6);
    g.add_edge(6,7);
    g.add_edge(7,0);
    g.add_edge(5,0);

    cout << g.two_vertex_connectivity(0,0);
    int i = 0;
    cout << endl;
    for(i = 0; i < g.V ; i++)
    {
        cout << i << " " << g.arrival[i] << " " << g.departure[i] << endl;
    }

    return 0;
}
