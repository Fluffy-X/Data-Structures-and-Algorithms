#include <bits/stdc++.h>
using namespace std;
vector<int> strongly;
class Graph{
public:
    list<int> *adj;
    void addEdge(int u, int v);
    Graph(int v);
    int V;
    vector<int> arrival;
    vector<int> departure;
    vector<int> visited;
    unordered_set<int> s;
    void DFS(int start);
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
}
void Graph::DFS(int start)
{
    s.insert(start);
    for(auto itr=adj[start].begin(); itr!=adj[start].end(); itr++)
    {
        if(s.find(*itr)==s.end() && visited[*itr]==0)
        {
            DFS(*itr);
        }
    }
}
int main()
{
    Graph g(5);
    g.addEdge(0,3);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,0);
    strongly.resize(g.V,0);
    Graph r(g.V);
    for(int i=0; i<g.V; i++)
    {
        for(auto itr=(g.adj[i]).begin(); itr!=(g.adj[i]).end(); itr++)
        {
            r.addEdge(*itr,i);
        }
    }
    vector<vector<int> > ans;
    for(int i=0; i<strongly.size(); i++)
    {
        if(strongly[i]==0)
        {
            vector<int> v;
            g.DFS(i);
            r.DFS(i);
            while( !g.s.empty() && !r.s.empty() )
            {
                auto itr = g.s.begin();
                if(r.s.find(*itr)!=r.s.end())
                {
                    strongly[*itr]=1;
                    r.visited[*itr]=1;
                    g.visited[*itr]=1;
                    r.s.erase(*itr);
                    g.s.erase(*itr);
                    v.push_back(*itr);
                }
                else
                {
                    g.s.erase(*itr);
                }
            }
            r.s.clear();
            g.s.clear();
            ans.push_back(v);
        }
    }
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
