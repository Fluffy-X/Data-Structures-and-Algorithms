#include <bits/stdc++.h>
using namespace std;
class Graph{
public:
    int V;
    list<pair<int,int> > *adj;
    vector<int> visited;
    vector<int> sshp;
    int visitednumber=0;
    Graph(int v);
    void addEdge(int u, int v, int w);
    void shortestpathstack(int source);
    void bellman(int source);
    void print(int source);
    int cycle=0;

};
void Graph::bellman(int source)
{

    sshp[source]= 0;
    for(int j=0; j<V-1; j++)
    {
        for(int i=0; i<V; i++)
        {
            for(auto itr=adj[i].begin(); itr!=adj[i].end(); itr++)
            {
                sshp[itr->first] = min(sshp[itr->first], sshp[i]+itr->second);
            }
        }
    }
    for(int i=0; i<V; i++)
    {
        for(auto itr=adj[i].begin(); itr!=adj[i].end(); itr++)
        {
            if(sshp[itr->first] > sshp[i]+itr->second)
                cycle=1;
        }
    }
    if(cycle==0)
        cout << "No negative cycle" << endl;
    else
        cout << "Negative Cycle Exists" << endl;
}
void Graph::shortestpathstack(int source)
{
    stack<int> s;// first is vertex and second is distance label
    stack<int> s1;
    s.push(source);
    sshp[source]=0;
    for(int i=0; i<V; i++)
    {
        while(!s.empty())
        {
            visitednumber++;
            visited[s.top()]=1;
            for(auto itr=adj[s.top()].begin(); itr != adj[s.top()].end(); itr++)
            {
                if(visited[itr->first]==0)
                {
                    sshp[itr->first] = min(sshp[itr->first], itr->second+sshp[s.top()]);
                    s1.push(itr->first);
                }
                else
                {
                    sshp[itr->first] = min(sshp[itr->first], itr->second+sshp[s.top()]);
                }
            }
            s.pop();
        }
        s=s1;
        stack<int>().swap(s1);
    }
    for(int j=0; j<V; j++)
        s.push(j);
    while(!s.empty())
    {
        for(auto itr=adj[s.top()].begin(); itr != adj[s.top()].end(); itr++)
            sshp[itr->first] = min(sshp[itr->first], itr->second+sshp[s.top()]);
        s.pop();
    }
}
void Graph::print(int source)
{
    //shortestpathstack(source);
    bellman(source);
    for(int i=0; i<V; i++)
        cout << source << " -> " << i << " : " << sshp[i] << endl;
}
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));

}
Graph::Graph(int v)
{
    V = v;
    adj = new list<pair<int,int> >[V];
    sshp.resize(V,10000);
    visited.resize(V,0);
}
int main()
{
    Graph g(4);
    g.addEdge(0,1,24);
    g.addEdge(0,3,20);
    g.addEdge(2,0,3);
    g.addEdge(3,2,12);
    g.print(0);
    return 0;

}
