#include <bits/stdc++.h>
using namespace std;
struct Node{
    long rank;
    long data;
    Node* parent;
};
class Disjoint_Sets{
public:
    long elements;
    Disjoint_Sets(long size);
    vector<Node*> address;
    void uniond(long a, long b);
    long findset(long a);
};
struct edge{
    long u;
    long v;
    long w;
};
bool compare_by_weight(const edge &a, const edge &b)
{
    return a.w < b.w;// Ascending Order
}
class Graph{
public:
    long V;
    void addEdge(long u, long v, long w);
    Graph(long v);
    vector<struct edge> edge_sort;
    long kruskal();
    list<int> *adj;
    long no_of_edges=0;
    vector<int> visited;
    Disjoint_Sets dj;
    long no_of_connected_components=0;
    void DFS(long start);
    long connected_components();
};
long Graph::connected_components()
{
    for(long i=0; i<V; i++)
    {
        if(visited[i]==0)
        {
            DFS(i);
            no_of_connected_components++;
        }
    }
    return no_of_connected_components;
}
void Graph::DFS(long start)
{
    visited[start] = 1;
    for( auto itr=adj[start].begin(); itr!=adj[start].end(); itr++)
    {
        if(visited[*itr]==0)
        {
            DFS(*itr);
        }
    }

}
long Graph::kruskal()
{
    //sort(edge_sort.begin(), edge_sort.end(), compare_by_weight);
    long i=0,j=0,weight=0;
    while(j < no_of_edges)
    {
        if(dj.findset(edge_sort[j].u) != dj.findset(edge_sort[j].v))
        {
            dj.uniond(edge_sort[j].u,edge_sort[j].v);
            weight += edge_sort[j].w;
        }
        j++;
    }
    return weight;
}
Graph::Graph(long v):dj(v)
{
    V = v;
    visited.resize(V,0);
    adj = new list<int>[V];
}
void Graph::addEdge(long u, long v, long w)
{
    struct edge temp;
    no_of_edges++;
    adj[u].push_back(v);
    adj[v].push_back(u);
    temp.u = u;
    temp.v = v;
    temp.w = w;
    edge_sort.push_back(temp);
}

Disjoint_Sets::Disjoint_Sets(long size)
{
    for(long i=0; i<size; i++)
    {
        Node* newnode = new Node;
        newnode->data=i;
        newnode->rank=0;
        newnode->parent = newnode;
        address.push_back(newnode);
    }
}
void Disjoint_Sets::uniond(long a, long b)
{
    //Standard Disjolong Set Implemetation without union by rank
/*
    Node* tempa = address[a];
    long tempdata = address[a]->data;
    while(tempa->parent->data != tempdata)
    {
        tempdata = tempa->parent->data;
        tempa = address[tempa->parent->data]->parent;

    }
    tempa->parent = address[b];
*/
    //Union By Rank
    Node* tempa  = address[a];
    long adata = address[a]->data;
    long bdata = address[b]->data;
    Node* tempb = address[b];
    while(tempa->parent->data != adata)
    {
        adata = tempa->parent->data;
        tempa = tempa->parent;
    }
    while(tempb->parent->data != bdata)
    {
        bdata = tempb->parent->data;
        tempb = tempb->parent;
    }
    if(tempa->rank > tempb->rank)
        tempb->parent = tempa;
    else if(tempa->rank < tempb->rank)
        tempa->parent = tempb;
    else
    {
        tempa->parent = tempb;
        tempb->rank++;
    }
}
long Disjoint_Sets::findset(long a)
{
    //Standard Disjolong Set Implemetation
/*  Node* tempa = address[a]->parent;
    long tempdata = address[a]->data;
    while(tempa->data != tempdata)
    {
        tempdata = tempa->data;
        tempa = address[tempa->data]->parent;
    }
    return tempdata;
*/
    //Using Path Compression Technique

    stack<Node*> s;
    Node* temp = address[a];
    long tempdata = a;
    while(temp->parent->data != tempdata)
    {
        s.push(temp);
        tempdata = temp->parent->data;
        temp = temp->parent;
    }
    while(!s.empty())
    {
        s.top()->parent = temp;
        s.pop();
    }
    return temp->data;
}
long roadsAndLibraries(long n, long c_lib, long c_road, vector < vector<int> > cities) {
    // Complete this function
    Graph g(n);

    for(long i=0; i<cities.size(); i++)
    {
        g.addEdge(cities[i][0]-1,cities[i][1]-1,1);
    }
    if(c_road > c_lib)
    {
        return n*c_lib;
    }
    else
    {
        //cout << g.connected_components() << " " << g.kruskal() << endl;
        return g.connected_components()*c_lib + g.kruskal()*c_road;
    }

}

int main() {
    long q;
    cin >> q;
    for(long a0 = 0; a0 < q; a0++){
        long n;
        long m;
        long c_lib;
        long c_road;
        cin >> n >> m >> c_lib >> c_road;
        vector< vector<int> > cities(m,vector<int>(2));
        for(long cities_i = 0;cities_i < m;cities_i++){
           for(long cities_j = 0;cities_j < 2;cities_j++){
              cin >> cities[cities_i][cities_j];
           }
        }
        long result = roadsAndLibraries(n, c_lib, c_road, cities);
        cout << result << endl;
    }
    return 0;
}
