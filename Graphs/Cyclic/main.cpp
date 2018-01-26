// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;
vector<int> dfs_array;
int global = 1;
bool search(vector<int>& g, int n)
{
    int i = 0;
    vector <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
    {
        if(g[i]==n)
        {
            return 1;
        }
        i++;
    }
    return 0;
}
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices

    // Pointer to an array containing adjacency
    // lists
    list<int> *adj;
public:
    Graph(int V);  // Constructor
    // function to add an edge to graph
    void addEdge(int v, int w);
    // prints BFS traversal from a given source s
    void BFS(int s);
    void DFS(int s);
};

Graph::Graph(int x)
{
    V = x;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int a)
{
    // Mark all the vertices as not visited
    queue<int> q;
    q.push(a);
    vector<int> array;
    array.push_back(a);
    list<int>::iterator it;
    while(!q.empty())
    {
        for(it=adj[q.front()].begin(); it!=adj[q.front()].end(); it++)
        {
            if(!search(array,*it))
            {
                q.push(*it);
                array.push_back(*it);
            }
        }
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl ;
}
void Graph::DFS(int a)
{
    if(global)
    {
        dfs_array.push_back(a);
        cout << a << " " ;
        global--;
    }
    list<int>::iterator it;
    for(it=adj[a].begin(); it !=adj[a].end(); it++)
    {

        if(!search(dfs_array,*it))
        {
            dfs_array.push_back(*it);
            cout << *it << " " ;
            DFS(*it);
        }
    }
}
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(0, 1);

    g.addEdge(1, 2);
    g.addEdge(1, 3);

    g.addEdge(2, 0);

    g.addEdge(3, 4);

    g.addEdge(4, 2);

    g.addEdge(5, 0);
    g.addEdge(5, 3);
    g.DFS(0);

    return 0;
}
