#include <bits/stdc++.h>
using namespace std;
struct Node{
    int rank;
    int data;
    Node* parent;
};
class Disjoint_Sets{
public:
    int elements;
    Disjoint_Sets(int size);
    vector<Node*> address;
    void uniond(int a, int b);
    int findset(int a);
};
struct edge{
    int u;
    int v;
    int w;
};
bool compare_by_weight(const edge &a, const edge &b){
    return a.w < b.w;// Ascending Order
}
class Graph{
public:
    int V;
    void addEdge(int u, int v, int w);
    Graph(int v);
    vector<struct edge> edge_sort;
    int kruskal();
    int no_of_edges=0;
    list<int> *adj;
    vector<int> visited;
    Disjoint_Sets dj;
};
int Graph::kruskal()
{
    sort(edge_sort.begin(), edge_sort.end(), compare_by_weight);
    int i=0,j=0,weight=0;
    while(i < V-1)
    {
        if(dj.findset(edge_sort[j].u) != dj.findset(edge_sort[j].v))
        {
            dj.uniond(edge_sort[j].u,edge_sort[j].v);
            weight += edge_sort[j].w;
            i++;
        }
        j++;
    }
    return weight;
}
Graph::Graph(int v):dj(v)
{
    V = v;
    visited.resize(V,0);
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v, int w)
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

Disjoint_Sets::Disjoint_Sets(int size)
{
    for(int i=0; i<size; i++)
    {
        Node* newnode = new Node;
        newnode->data=i;
        newnode->rank=0;
        newnode->parent = newnode;
        address.push_back(newnode);
    }
}
void Disjoint_Sets::uniond(int a, int b)
{
    //Standard Disjoint Set Implemetation without union by rank
/*
    Node* tempa = address[a];
    int tempdata = address[a]->data;
    while(tempa->parent->data != tempdata)
    {
        tempdata = tempa->parent->data;
        tempa = address[tempa->parent->data]->parent;

    }
    tempa->parent = address[b];
*/
    //Union By Rank
    Node* tempa  = address[a];
    int adata = address[a]->data;
    int bdata = address[b]->data;
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
int Disjoint_Sets::findset(int a)
{
    //Standard Disjoint Set Implemetation
/*  Node* tempa = address[a]->parent;
    int tempdata = address[a]->data;
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
    int tempdata = a;
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
int main()
{
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    cout << g.kruskal();
    return 0;
}
