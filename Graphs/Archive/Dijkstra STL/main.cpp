#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <deque>
#include <stack>
using namespace std;
class myComparator
{
public:
    int operator() (const pair<int,int>& p1, const pair<int,int>& p2)
    {
        return p1.second > p2.second;
    }
};
class Graph
{
public:
    int V;
    vector<pair<int, int> > *adj;
    Graph(int V);
    void addEdge(int v, int w, int weight);
    int dijkstra(int start);
};
Graph::Graph(int x)
{
    V = x;
    adj = new vector<pair<int,int> >[V];
}
void Graph::addEdge(int v, int w, int weight)
{
    adj[v].push_back(make_pair(w,weight));
    adj[w].push_back(make_pair(v,weight));
}
int Graph::dijkstra(int start)
{
    int i = 0,v = 0,d = 0;
    vector<int> visited(V,1000);
    priority_queue <pair<int,int>, vector<pair<int,int> >, myComparator > pq;
    vector<pair<int,int> >::iterator it;
    for(i=0;i<V;i++)
    {
        if(i==start)
            pq.push(make_pair(i,0));
        else
            pq.push(make_pair(i,1000));
    }
    while(!pq.empty())
    {
        v = pq.top().first;
        d = pq.top().second;
        pq.pop();
        for(it=adj[v].begin(); it!=adj[v].end();it++)
        {
            if(visited[(*it).first] > (*it).second+d)
            pq.push(make_pair((*it).first,(*it).second+d));
        }
        if(visited[v]>d)
            visited[v] = d ;
    }
    for(i=0;i<V;i++)
    {
        cout << i << " " << visited[i] << endl;
    }
}
int main()
{
    Graph g(9);
    g.addEdge( 0, 1, 4);
    g.addEdge( 0, 7, 8);
    g.addEdge( 1, 2, 8);
    g.addEdge( 1, 7, 11);
    g.addEdge( 2, 3, 7);
    g.addEdge( 2, 8, 2);
    g.addEdge( 2, 5, 4);
    g.addEdge( 3, 4, 9);
    g.addEdge( 3, 5, 14);
    g.addEdge( 4, 5, 10);
    g.addEdge( 5, 6, 2);
    g.addEdge( 6, 7, 1);
    g.addEdge( 6, 8, 6);
    g.addEdge( 7, 8, 7);
    g.dijkstra(8);

    return 0;
}
