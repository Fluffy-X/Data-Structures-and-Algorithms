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
    int length_of_MST_prim();
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
int Graph::length_of_MST_prim()
{
    int MST = 0, temp = 0;
    vector<int> visited(V,0);
    priority_queue <pair<int,int>, vector<pair<int,int> >, myComparator > pq;
    vector<pair<int,int> >::iterator it;
    for(it=adj[0].begin(); it !=adj[0].end(); it++)
    {
        pq.push(*it);
    }
    visited[0] = 1;
    while(!pq.empty())
    {
        if(visited[pq.top().first]==1)
        {
            pq.pop();
            continue;
        }
        MST+=pq.top().second;
        temp = pq.top().first;
        pq.pop();
        if(visited[temp]==0)
        {
            for(it=adj[temp].begin(); it!=adj[temp].end();it++)
            {
                if(visited[(*it).first]==0)
                    pq.push(*it);
            }
            visited[temp] =1;
        }
    }
    return MST;
}
int main()
{
    Graph g(5);
    g.addEdge( 0, 1, 2);
    g.addEdge( 1, 2, 7);
    g.addEdge( 2, 3, 8);
    g.addEdge( 0, 3, 4);
    g.addEdge( 0, 4, 6);
    g.addEdge( 3, 4, 3);
    g.addEdge( 4, 2, 5);

    cout << g.length_of_MST_prim();
    return 0;

}

