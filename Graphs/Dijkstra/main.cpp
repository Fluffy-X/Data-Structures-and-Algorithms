#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    int V;
    list<pair<int,int> > *adj;
    vector<int> distance;
    void addEdge(int u, int v, int w);
    void dijkstra(int source);
    Graph(int v);
    priority_queue < pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;//first is distance and second is vertex
};
Graph::Graph(int v)
{
    V = v;
    distance.resize(V,-1);
    adj = new list<pair<int,int> >[V];
}
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}
void Graph::dijkstra(int source)
{
    pq.push(make_pair(0,source));
    while(!pq.empty())
    {
        if(distance[pq.top().second]!=-1)
        {
            pq.pop();
            continue;
        }
        else
        {
            for(auto itr = adj[pq.top().second].begin(); itr!=adj[pq.top().second].end(); itr++)
                pq.push(make_pair(pq.top().first+itr->second,itr->first));
            distance[pq.top().second] = pq.top().first;
            pq.pop();
        }
    }
    for(int i=0; i<V; i++)
        cout << i << " : " << distance[i] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
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
    g.dijkstra(0);
    return 0;
}
