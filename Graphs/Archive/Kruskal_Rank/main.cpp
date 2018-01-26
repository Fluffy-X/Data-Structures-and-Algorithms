#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
struct vertices
{
    int vertex;
    vertices *next;
    int height;
};
vertices node_initialize(int x)
{
    vertices mypoint = {x,NULL,1};
    return mypoint;
}
class Graph
{
    public:
    int V, E;
    vector<vertices*> ptr;
    vector<vertices> adj;
    //vector< pair< int , pair< int , pair< string , pair< int , int > > > > >
    vector<pair<int, pair<int, int>> > vec;
    void addEdge(int s, int d, int w);
    Graph(int v, int e);
    int kunion(vertices* source,vertices* destination);
    vertices* find(int source);

};
Graph::Graph(int v, int e)
{
    V=v;E=e;
    int i = 0;
    for(i=0;i<V;i++)
        adj.push_back(node_initialize(i));
    for(i=0;i<V;i++)
        ptr.push_back(&adj[i]);
}
void Graph::addEdge(int s, int d, int w)
{
    vec.push_back(make_pair(w,make_pair(s,d)));
}
int Graph::kunion(vertices* source,vertices* destination)
{
    if(source==destination)
        return -1;
    else
    {
        if(source->height > destination->height)
        {
            source->height = source->height + destination->height;
            destination->next = source;
        }
        else
        {
            destination->height = destination->height + source->height;
            source->next = destination;
        }
        return +1;
    }
}
vertices* Graph::find(int source)
{
    vertices* s = ptr[source];
    if(s->next==NULL)
        return s;
    else
    {
        for(;s->next!=NULL;)
            s = s->next;
        return s;
    }
}
int main()
{
     Graph g(7,11);
    g.addEdge(0,1,1);
    g.addEdge(0,2,4);
    g.addEdge(0,5,4);
    g.addEdge(0,4,7);
    g.addEdge(4,3,9);
    g.addEdge(4,5,6);
    g.addEdge(3,2,2);
    g.addEdge(3,1,5);
    g.addEdge(1,2,3);
    g.addEdge(1,6,8);
    g.addEdge(3,6,10);


    sort(g.vec.begin(),g.vec.end());
    int i;
    for(i = 0; i<g.E; i++)
    {
        cout << g.vec[i].first << " " << g.vec[i].second.first << " " << g.vec[i].second.second << endl;
    }

    for(i = 0; i<g.V; i++)
    {
        if(g.ptr[i]->next==NULL)
            cout << i << " is NULL " << endl;
    }
    int KMST = 0;vertices* v1;vertices* v2;
    for(i = 0; i<g.E; i++)
    {
        if(g.kunion(g.find(g.vec[i].second.first),g.find(g.vec[i].second.second))==+1)
            KMST+=g.vec[i].first;
    }
    for(i = 0; i<6; i++)
    {
        cout << i << " " << g.ptr[i]->height << endl;
    }
    cout << "KMST : " << KMST ;
    return 0;
}
