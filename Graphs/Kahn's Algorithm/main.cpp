#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    int V;
    list<int> *adj;
    vector<int> visited;
    vector<int> indegree;
    int visitednumber=0;
    Graph(int v);
    void addEdge(int u, int v);
    void DFS(int start);
    void preDFS();
    void kahn();
    void kahnefficient();
};
void Graph::kahn()
{
    priority_queue < pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > > pq;
    for(int i=0; i<V; i++)
        pq.push(make_pair(indegree[i],i));
    int i=0;
    vector<int> ans;
    while(i!=V)
    {
        int a=pq.top().second;
        if(find(ans.begin(), ans.end(), a) != ans.end())
        {
            pq.pop();
            continue;
        }
        ans.push_back(a);
        for(auto itr=adj[a].begin(); itr!=adj[a].end(); itr++)
            pq.push(make_pair(--indegree[*itr],*itr));
        pq.pop();
        i++;
    }
    for(int i=0; i<V; i++)
        cout << ans[i] << " ";
}
void Graph::kahnefficient()
{
    queue<int> v;
    for(int i=0; i<V; i++)
    {
        if(indegree[i]==0)
            v.push(i);
    }
    while(!v.empty())
    {
        for(auto itr=adj[v.front()].begin(); itr!=adj[v.front()].end(); itr++)
        {
            --indegree[*itr];
            if(indegree[*itr]==0)
                v.push(*itr);

        }
        cout << v.front() << " ";
        v.pop();
    }

}
void Graph::preDFS()
{
    for(int i=0; i<V; i++)
    {
        if(visited[i]==0)
            DFS(i);
    }
    kahnefficient();
}
void Graph::DFS(int start)
{
    visited[start]=1;
    for(auto itr=adj[start].begin(); itr!=adj[start].end(); itr++)
    {
        indegree[*itr]++;
        if(visited[*itr]==0)
            DFS(*itr);
    }
}
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}
Graph::Graph(int v)
{
    V = v;
    adj = new list<int>[V];
    indegree.resize(V,0);
    visited.resize(V,0);
}
int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.preDFS();
    return 0;
}
