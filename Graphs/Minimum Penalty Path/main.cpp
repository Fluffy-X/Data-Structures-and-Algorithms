#include <bits/stdc++.h>
using namespace std;
struct node {
    int v;
    int d;
};
int main()
{
    int n,m;
    cin >> n >> m;
    node temp;
    temp.v=-1;temp.d=INT_MAX;
    int u, v, d;
    //vector<vector<node> >  graph(n+1,vector<node>(n+1,temp));
    vector<node> graph[n+1];
    for(int i=0; i<m; i++)
    {
        cin >> u >> v >> d;
        if(u==v)
            continue;
        temp.v = v;temp.d = d;
        graph[u].push_back(temp);
        temp.v = u;temp.d = d;
        graph[v].push_back(temp);

    }/*
    for(int i=1; i<n+1; i++)
    {
        cout << i << " : ";
        for(int j=0; j<graph[i].size(); j++)
        {
            cout << graph[i][j].v << " " << graph[i][j].d << "   ";
        }
        cout << endl;
    }*/
    int start, destination;
    cin >> start >> destination;
    vector<int> dist(n+1,INT_MAX);
    dist[start] = 0;
    for(int i=start; i<n+1; i++)
    {
        for(int j=0; j<graph[i].size(); j++)
        {
            dist[graph[i][j].v] = min(dist[graph[i][j].v], ((graph[i][j].d)|(dist[i])));
        }
    }
    for(int i=start; i<n+1; i++)
    {
        for(int j=0; j<graph[i].size(); j++)
        {
            dist[graph[i][j].v] = min(dist[graph[i][j].v], ((graph[i][j].d)|(dist[i])));
        }
    }2
    for(int i=1; i<n+1; i++)
        cout << i << " " << dist[i] << endl;
    if(dist[destination] == INT_MAX)
        dist[destination] = -1;
    cout << dist[destination] << endl;

    return 0;
}
