<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    int v;
    vector<int> *adj;
    unordered_set<int> s;
    map<int, int, greater<int> > m;
    vector<int> visited;
    Graph(int V);
    void add_edge(int u, int v);
    int countDFS(int start, int c, int mem);
    int DFS(int current, int parent, int grandparent);
    int triangle_easy();
    void visitedreset();
    int c=1;
};
void Graph::visitedreset()
{
    fill(visited.begin(), visited.end(), 0);
}
Graph::Graph(int V)
{
    v=V;
    visited.resize(V,0);
    adj = new vector<int> [V];
}
void Graph::add_edge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int Graph::countDFS(int start,int ca, int mem) // initially c=1 and start = mem and reset c after every iteration
{
    visited[start]=1;
    s.erase(start);
    auto itr=adj[start].begin();
    for( ; itr!=adj[start].end(); itr++)
    {
        if(visited[*itr]==0)
        {
            c++;
            countDFS(*itr,c,start);
        }
    }
    if(mem==start)
        return c;
    return 0;
}
int Graph::DFS(int current, int parent, int grandparent)
{
    int temp=-5;
    visited[current]=1;
    for(auto itr=adj[current].begin(); itr!=adj[current].end(); itr++)
    {
        if(*itr==grandparent && grandparent!=-1)
        {
            return 0;
        }
        if(visited[*itr]==0)
        {
            if(DFS(*itr,current,parent)==0)
                return 0;
        }
    }
    return 1;
}

int Graph::triangle_easy()
{
    int a=10;
    int ans =10;
    if(v<3)
        return 10000;
    else
    {
        for(int i=0; i<v ; i++)
            s.insert(i);
        while(!s.empty())
        {
            auto itr = s.begin();
            c=1;
            countDFS(*itr,1,*itr);
            m.insert(make_pair(c,*itr));
            c=1;
        }
        visitedreset();
        auto itr = m.begin();
        if(itr->first==2)
            return 2;
        if(itr->first==1)
            return 3;
        else
        {
            for(auto itr=m.begin(); itr!=m.end(); itr++)
            {
                a = DFS(itr->second,-1,-1);
                ans = min(ans,a);
                if(ans==0)
                    return 0;
            }
            return 1;
        }
    }
}
int main()
{
    vector<int> x={0,2,1,2};
    vector<int> y={3,0,2,3};
    int vertices=20;
    Graph g(vertices);
    for(int i=0 ; i<x.size(); i++)
        g.add_edge(x[i],y[i]);
    cout << g.triangle_easy();
    return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    int v;
    vector<int> *adj;
    unordered_set<int> s;
    map<int, int, greater<int> > m;
    vector<int> visited;
    Graph(int V);
    void add_edge(int u, int v);
    int countDFS(int start, int c, int mem);
    int DFS(int current, int parent, int grandparent);
    int triangle_easy();
    void visitedreset();
    int c=1;
};
void Graph::visitedreset()
{
    fill(visited.begin(), visited.end(), 0);
}
Graph::Graph(int V)
{
    v=V;
    visited.resize(V,0);
    adj = new vector<int> [V];
}
void Graph::add_edge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int Graph::countDFS(int start,int ca, int mem) // initially c=1 and start = mem and reset c after every iteration
{
    visited[start]=1;
    s.erase(start);
    auto itr=adj[start].begin();
    for( ; itr!=adj[start].end(); itr++)
    {
        if(visited[*itr]==0)
        {
            c++;
            countDFS(*itr,c,start);
        }
    }
    if(mem==start)
        return c;
    return 0;
}
int Graph::DFS(int current, int parent, int grandparent)
{
    int temp=-5;
    visited[current]=1;
    for(auto itr=adj[current].begin(); itr!=adj[current].end(); itr++)
    {
        if(*itr==grandparent && grandparent!=-1)
        {
            return 0;
        }
        if(visited[*itr]==0)
        {
            if(DFS(*itr,current,parent)==0)
                return 0;
        }
    }
    return 1;
}

int Graph::triangle_easy()
{
    int a=10;
    int ans =10;
    if(v<3)
        return 10000;
    else
    {
        for(int i=0; i<v ; i++)
            s.insert(i);
        while(!s.empty())
        {
            auto itr = s.begin();
            c=1;
            countDFS(*itr,1,*itr);
            m.insert(make_pair(c,*itr));
            c=1;
        }
        visitedreset();
        auto itr = m.begin();
        if(itr->first==2)
            return 2;
        if(itr->first==1)
            return 3;
        else
        {
            for(auto itr=m.begin(); itr!=m.end(); itr++)
            {
                a = DFS(itr->second,-1,-1);
                ans = min(ans,a);
                if(ans==0)
                    return 0;
            }
            return 1;
        }
    }
}
int main()
{
    vector<int> x={0,2,1,2};
    vector<int> y={3,0,2,3};
    int vertices=20;
    Graph g(vertices);
    for(int i=0 ; i<x.size(); i++)
        g.add_edge(x[i],y[i]);
    cout << g.triangle_easy();
    return 0;
}
>>>>>>> 809b7f018bed7c1396e0b7468538907694cff57c
