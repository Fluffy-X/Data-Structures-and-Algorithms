#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100];
vector<int> visited(100);
stack<int> s;
int c=0;
vector<vector<int> >ways;

void backdfs(int u, int depth, int n)
{
    visited[u] =1;
  //  s.push(u);
    for(auto itr=graph[u].begin(); itr!=graph[u].end(); itr++)
    {
        if(visited[*itr]==0)
            backdfs(*itr,depth+1,n);
    }
    if(depth==n)
        c++;
//    s.pop();
    visited[u]=0;
}


int main()
{
    int n,a,b,e;
    cin >> n;
    cin >> e;
    for(int i=1; i<=e; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<=n; i++)
    {
        fill(visited.begin(), visited.end(),0);
        backdfs(i,1,n);
    }
    cout << c << endl;
    return 0;
}
