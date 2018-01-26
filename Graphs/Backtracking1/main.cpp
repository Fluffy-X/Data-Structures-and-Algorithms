#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector<int> visited;
vector<int> possibledistance;
//int possdist;
class Graph
{
public:
    int V;
    vector<pair<int, int> > *adj;
    Graph(int V);
    void addEdge(int v, int w, int weight);
    void backtracking(int start,int buffer);
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
void Graph::backtracking(int start, int buffer)// initially buffer = 0
{
    visited[start] = 1;
    vector<pair<int,int> >::iterator it;
    for(it=adj[start].begin(); it!=adj[start].end();it++)
    {
        if(visited[(*it).first]==0)
        {
            backtracking((*it).first,(*it).second + buffer);
        }
    }
    visited[start] = 0;

    possibledistance.push_back(buffer);
}
int main()
{
    Graph g(10);
    int i = 0;
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
    g.addEdge( 6, 8, 60);
    g.addEdge( 7, 8, 72);
    g.addEdge( 9, 8, 60);
    g.addEdge( 7, 2, 72);

    visited.resize(g.V,0);
    g.backtracking(0,0);
    vector<int>::iterator it;
    sort(possibledistance.begin(), possibledistance.end());
    for(it=possibledistance.begin(); it!=possibledistance.end();it++)
    {
        cout << *it << endl;
    }
    return 0;
}
