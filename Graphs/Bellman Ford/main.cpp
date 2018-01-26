#include <bits/stdc++.h>
using namespace std;
class Graph{
public:
    list<pair<int,int> > *adj;
    void addEdge(int u, int v, int w);
    Graph(int v);
    int V;
    vector<int> arrival;
    vector<int> departure;
    vector<int> visited;
    void DFS(int start);
    void bellman(int start);
    void prebellman(int start);
    int bell=0;
    stack<pair<int,int> > s;
    int c=0;
};
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v,w));
}
Graph::Graph(int v)
{
    V = v;
    adj = new list<pair<int,int> >[V];
    visited.resize(V,0);
    arrival.resize(V,0);
    departure.resize(V,0);
}
void Graph::DFS(int start)
{
    visited[start]=1;
    arrival[start] = c;
    for(auto itr=adj[start].begin(); itr!=adj[start].end(); itr++)
    {
        if(visited[itr->first]==0)
        {
            c++;
            DFS(itr->first);
        }
    }
    c++;
    departure[start]=c;
}
void Graph::prebellman(int start)
{
    DFS(start);
    fill(visited.begin(),visited.end(),0);
    s.push(make_pair(0,-1));
    bellman(start);
    if(bell==0)
        cout << "No Negative Cycle";
    else
        cout << "It has a Negative Cycle";
}
void Graph::bellman(int start)
{
    visited[start]=1;
    for(auto itr=adj[start].begin(); itr!=adj[start].end(); itr++)
    {
        if(visited[itr->first]==0)
        {
            s.push(make_pair(itr->first,itr->second));
            bellman(itr->first);
        }
        else if(arrival[start] > arrival[itr->first] && departure[start] < departure[itr->first] )
        {
            stack<pair<int,int> > s1 = s;
            int sum=itr->second;
            while(s1.top().first != itr->first)
            {
                sum = sum + s1.top().second;
                s1.pop();
            }
            if(sum < 0)
                bell=1;
        }
    }
    s.pop();
}
int main()
{
    Graph g(4);
    g.addEdge(0,1,);
    g.addEdge(1,2,-1);
    g.addEdge(2,3,-1);
    g.addEdge(3,0,-1);
    g.prebellman(0);
    return 0;
}
