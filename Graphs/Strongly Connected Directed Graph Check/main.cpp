#include <iostream>
#include <vector>
using namespace std;
int count = 0;// for arrival and departure time

class Graph
{
public:
    int V;
    vector<int> arrival;
    vector<int> visited;
    vector<int> departure;
    vector<int> *adj; // not adj[V]
    void add_edge(int u, int v);
    void DFS(int start);
    Graph(int v);
    int stronglyconnected(int v);
    void visitedreset();
    void sc(int v);

};
void Graph::sc(int v)
{
    DFS(v);
    visitedreset();
    if(stronglyconnected(v)==-1)
        cout << "Not Strongly Connected";
    else
        cout << "Strongly Connected";
}
int Graph::stronglyconnected(int v)
{
    int a = 1000, temp=0;
    visited[v] = 1;
    for(auto itr=adj[v].begin(); itr!=adj[v].end(); itr++)
    {
        if(visited[*itr]==0)
        {
            temp = stronglyconnected(*itr);
            if(temp > arrival[*itr])
                return -1;
            a = min(a,temp);
        }
    }

    if(a==1000)
    {
        for(auto itr = adj[v].begin(); itr!=adj[v].end(); itr++)
            a = min(a,arrival[*itr]);
        if(a > arrival[v])
            return -1;
        else
            return a;
    }
    else
    {
        for(auto itr = adj[v].begin(); itr!=adj[v].end(); itr++)
            a = min(a,arrival[*itr]);
        return a;
    }
}
void Graph::visitedreset()
{
    fill(visited.begin(), visited.end(), 0);
}
Graph::Graph(int v)
{
    V = v;
    visited.resize(V,0);
    arrival.resize(V,0);
    departure.resize(V,0);
    adj = new vector<int> [V];
}
void Graph::add_edge(int u, int v)
{
    adj[u].push_back(v);
}


void Graph::DFS(int start)
{
    visited[start]=1;
    vector<int>::iterator it;
    arrival[start] = count;
    for(it=adj[start].begin();it !=adj[start].end();it++)
    {
        if(visited[*it]!=1)
        {
            count++;
            DFS(*it);
        }
    }
    departure[start] = count+1;
    count++;
}
int main()
{
    Graph g(8);
    g.add_edge(4,0);
    g.add_edge(5,4);
    g.add_edge(5,6);
    g.add_edge(6,7);
    g.add_edge(0,5);
    g.add_edge(7,0);
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(3,2);
    g.add_edge(3,0);
    g.add_edge(1,3);
    g.add_edge(2,0);
    g.sc(5);
    return 0;
}
