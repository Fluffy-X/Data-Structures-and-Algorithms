// E Edge Connectivity in Undirected Graph

#include <iostream>
#include <vector>
using namespace std;
int arr[8]={0};
int count = 0;

class Graph
{
public:
    int V;
    vector<int> arrival;
    vector<int> visited;
    vector<int> departure;
    vector<int> *adj; // not adj[V]
    void add_edge(int u, int v);
    void DFS(int start);
    int two_edge_connectivity(int i, int parent);
    int twoEC(int i);
    Graph(int v);
    int stronglyconnected(int v);
    void visitedreset();
    void sc(int v);

};
void Graph::sc(int v)
{
    DFS(v);
    visitedreset();
    if(stronglyconnected(v)==-1)
        cout << "Not Strongly Connected";
    else
        cout << "Strongly Connected";
}
int Graph::stronglyconnected(int v)
{
    int a = 1000, temp=0;
    visited[v] = 1;
    for(auto itr=adj[v].begin(); itr!=adj[v].end(); itr++)
    {
        if(visited[*itr]==0)
        {
            temp = stronglyconnected(*itr);
            if(temp > arrival[*itr])
                return -1;
            a = min(a,temp);
        }
    }

    if(a==1000)
    {
        for(auto itr = adj[v].begin(); itr!=adj[v].end(); itr++)
            a = min(a,arrival[*itr]);
        if(a > arrival[v])
            return -1;
        else
            return a;
    }
    else
    {
        for(auto itr = adj[v].begin(); itr!=adj[v].end(); itr++)
            a = min(a,arrival[*itr]);
        return a;
    }
}
void Graph::visitedreset()
{
    fill(visited.begin(), visited.end(), 0);
}
Graph::Graph(int v)
{
    V = v;
    visited.resize(V,0);
    arrival.resize(V,0);
    departure.resize(V,0);
    adj = new vector<int> [V]; // error without this
}
void Graph::add_edge(int u, int v)
{
    adj[u].push_back(v);
    //adj[v].push_back(u);

}
int Graph::twoEC(int i)
{
    DFS(0);
    fill(visited.begin(),visited.end(),0);
    int a =  two_edge_connectivity(0,0);
    if(a==-1)
        cout << endl << "Graph is not 2 Edge connected " << endl;
    else
        cout << endl << "Graph is 2 Edge connected " << endl;
}

void Graph::DFS(int start)
{
    visited[start]=1;
    vector<int>::iterator it;
    arrival[start] = count;
    for(it=adj[start].begin();it !=adj[start].end();it++)
    {
        if(visited[*it]!=1)
        {
            count++;
            DFS(*it);
        }
    }
    departure[start] = count+1;
    count++;
}


int Graph::two_edge_connectivity(int i,int parent)
{
    int a=1000, b=1000, b1=1000, a1=1000;
    visited[i]=1;
    vector<int>::iterator it;
    for(it=adj[i].begin();it!=adj[i].end();it++)
    {
        if(visited[*it]==0)
        {
            b1=two_edge_connectivity(*it,i);
            if(b1>arrival[i])
                return -1;
            if(b1<b)
                b=b1;
        }
    }
    for(it=adj[i].begin();it!=adj[i].end();it++)
    {
        if((*it)!=parent)
        {
            a1=arrival[*it]; // deepest backedge of childs
            a = min(a,a1);
        }
    }
    if(b==1000)
        return a;
    else
        return min(a,b);
}
int main()
{
    /*Graph g(8);
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(3,4);
    g.add_edge(4,5);
    g.add_edge(2,6);
    g.add_edge(6,7);*/
    Graph g(8);
    g.add_edge(4,0);
    g.add_edge(5,4);
    g.add_edge(5,6);
    g.add_edge(6,7);
    g.add_edge(0,5);
    g.add_edge(7,0);
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(3,2);
    g.add_edge(3,0);
    g.add_edge(1,3);
    g.add_edge(2,0);
    g.sc(5);

    return 0;
}
