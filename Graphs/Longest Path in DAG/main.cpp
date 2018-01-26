#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V;
    vector<pair<int, int> > *adj;
    vector<int> visited;
    vector<int> departure;
    vector<int> arrival;
    vector<int> topological;
    void topologicalorering();
    vector<int> longestpath;
    vector<int> toploorder;
    Graph(int V);
    void addEdge(int v, int w, int weight);
    void DFS(int start);
    void longest(int u, int overhead);
    int c=0;
    void F(int start);
};
void Graph::F(int start)
{
    DFS(start);
    topologicalorering();
    longest(0,0);
    longestpath[start]=0;
    for(int i=0; i<longestpath.size(); i++)
        cout << i << " " << longestpath[i] << endl;
    cout << endl;
    for(int i=0; i<toploorder.size(); i++)
        cout << i << " " << toploorder[i] << endl;
}
void Graph::longest(int u, int overhead) // u =0 initially
{
    if(u==toploorder.size()-1)
        return;
    int i = toploorder[u];
    auto itr = adj[i].begin();
    for( ; itr != adj[i].end(); itr++)
    {
        if(longestpath[(*itr).first] < overhead+(*itr).second)
        {
            longestpath[(*itr).first] = overhead+(*itr).second;
            u++;
            longest(u,overhead+(*itr).second);
        }
        //cout << "LOL";
        //overhead = (*itr).first)
    }
}
void Graph::DFS(int start)
{
    visited[start]=1;
    arrival[start]=c;
    for(auto itr=adj[start].begin(); itr!=adj[start].end(); itr++)
    {
        if(visited[(*itr).first]!=1)
        {
            c++;
            DFS((*itr).first);
        }
    }
    c++;
    departure[start] = c;
    topological[c] = start;
}
void Graph::topologicalorering()
{
    int i=topological.size()-1;
    for( ;i>=0; i--)
    {
        if(topological[i]!=-1)
            toploorder.push_back(topological[i]);
    }
}
Graph::Graph(int x)
{
    V = x;
    adj = new vector<pair<int,int> >[V];
    visited.resize(V,0);
    departure.resize(V);
    arrival.resize(V);
    longestpath.resize(V,-10);
    topological.resize(2*V,-1);
}
void Graph::addEdge(int v, int w, int weight)
{
    adj[v].push_back(make_pair(w,weight));
}

int main()
{
    Graph g(5);
    g.addEdge(0, 1, 2);
	g.addEdge(1, 2, 2);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 10);
	g.addEdge(1, 3, 3);
	g.addEdge(0, 2, 1);
	g.addEdge(2, 4, 4);



    g.F(0);
    return 0;
}
