#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    public:
    int V;
    int count;
    vector<int> *adj;
    vector<int> left;
    vector<int> right;
    vector<int> visited;
    vector<int> arrival;
    vector<int> departure;
    void add_edge(int u, int v);
    void DFS(int start);
    int planar(int start, int parent);
    Graph(int v);
};
void Graph::add_edge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
Graph::Graph(int v)
{
    V = v;
    count = 0;
    visited.resize(V);
    arrival.resize(V);
    departure.resize(V);
    adj = new vector<int> [V];
}
void Graph::DFS(int start)
{
    visited[start] = 1;
    vector<int> ::iterator it;
    arrival[start]=count;
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

int Graph::planar(int start, int parent)
{
    int buffer = 1000;
    visited[start] = 1;
    vector<int>::iterator it;
    for(it=adj[start].begin(); it!=adj[start].end(); it++)
    {
        if(visited[*it]!=1)
        {
            if(planar(*it,start)==-1)
                return -1;
        }
    }
    int a = 0,b = 0;
    for(it=adj[start].begin(); it!=adj[start].end(); it++)
    {
        if(*it!=parent && arrival[*it]<arrival[start])
        {
            for(a = arrival[*it]; a != arrival[start]; a++)
            {
                if(left[a]==1)
                {
                    for(b = arrival[*it]; b != arrival[start]; b++)
                    {
                        if(right[b]==1);
                            return -1;
                    }
                    right[*it]=1;
                    break;
                }
                if(right[a]==1)
                {
                    for(b = arrival[*it]; b != arrival[start]; b++)
                    {
                        if(right[b]==1);
                        return -1;
                    }
                    left[*it] = 1;
                    break;
                }
            }
            if(right[*it]==0 && left[*it]==0)
                right[*it]=1;
        }
    }
    return +1;
}


int main()
{
    Graph g(5);
    g.add_edge(0,1);
    g.add_edge(2,1);
    g.add_edge(2,3);
    g.add_edge(3,4);
    g.add_edge(0,4);g.add_edge(2,4);
    g.add_edge(3,1);g.add_edge(0,3);
    g.add_edge(0,2);

    g.DFS(0);
    fill(g.visited.begin(),g.visited.end(),0);
    cout << g.planar(0,0);
    for(int i =0; i<g.V; i++)
    {
        cout << i << " " << g.arrival[i] << " " << g.departure[i] << endl;
    }
    return 0;
}
