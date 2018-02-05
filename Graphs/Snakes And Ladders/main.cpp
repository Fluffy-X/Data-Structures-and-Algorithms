#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    int V;
    list<pair<int,int> > *adj;
    vector<int> distance;
    void addEdge(int u, int v, int w);
    void dijkstra(int source);//Didn't used this
    Graph(int v);
    priority_queue < pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    void bellman(int source);
    vector<int> sshp;
};
void Graph::bellman(int source)
{
    sshp[source]= 0;
    for(int j=0; j<V; j++)
    {
        for(int i=0; i<V; i++)
        {
            for(auto itr=adj[i].begin(); itr!=adj[i].end(); itr++)
            {
                sshp[itr->first] = min(sshp[itr->first], sshp[i]+itr->second);
            }
        }
    }
}
Graph::Graph(int v)
{
    V = v;
    sshp.resize(V,10000);
    distance.resize(V,-1);
    adj = new list<pair<int,int> >[V];
}
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v,w));
}
void Graph::dijkstra(int source)
{
    int count=0;
    pq.push(make_pair(0,source));
    while(!pq.empty())
    {
        if(count==V)
            break;
        if(distance[pq.top().second]!=-1)
        {
            pq.pop();
            continue;
        }
        else
        {
            for(auto itr = adj[pq.top().second].begin(); itr!=adj[pq.top().second].end(); itr++)
            {
                pq.push(make_pair(pq.top().first+itr->second,itr->first));
            }
            distance[pq.top().second] = pq.top().first;
            count++;
            pq.pop();
        }
    }
}
int quickestWayUp(vector < vector<int> > ladders, vector < vector<int> > snakes)
{
    unordered_map<int,int> l;
    unordered_map<int,int> s;
    for(int i=0; i<ladders.size(); i++)
        l.insert(make_pair(ladders[i][0],ladders[i][1]));
    for(int i=0; i<snakes.size(); i++)
        s.insert(make_pair(snakes[i][0],snakes[i][1]));
    Graph g(100);
    for(int i=0; i<100; i++) // 0->1, 5->6,  99->100
    {
        if(l.find(i+1) != l.end())
        {
            auto itr = l.find(i+1);
            g.addEdge(i,itr->second-1,0);
        }
        else if(s.find(i+1) != s.end())
        {
            auto itr = s.find(i+1);
            g.addEdge(i,itr->second-1,0);
        }
        else
        {
            for(int j=1; j<=6 && i+j <100; j++)
            {
                g.addEdge(i,i+j,1);
            }
        }
    }
    g.bellman(0);
    if(g.sshp[99]==10000)
        return -1;
    return g.sshp[99];
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector< vector<int> > ladders(n,vector<int>(2));
        for(int ladders_i = 0;ladders_i < n;ladders_i++){
           for(int ladders_j = 0;ladders_j < 2;ladders_j++){
              cin >> ladders[ladders_i][ladders_j];
           }
        }
        int m;
        cin >> m;
        vector< vector<int> > snakes(m,vector<int>(2));
        for(int snakes_i = 0;snakes_i < m;snakes_i++){
           for(int snakes_j = 0;snakes_j < 2;snakes_j++){
              cin >> snakes[snakes_i][snakes_j];
           }
        }
        int result = quickestWayUp(ladders, snakes);
        cout << result << endl;
    }
    return 0;
}
