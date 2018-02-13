#include <bits/stdc++.h>
using namespace std;
vector<int> graph[1000];
vector<int> in(1000,0);
vector<int> out(1000,INT_MIN);
vector<int> visited(1000,0);
vector<int> height(1000,0);
int dfs(int start)
{
    visited[start] = 1;
    int h = INT_MIN;
    int c=0;
    for(auto itr=graph[start].begin(); itr!= graph[start].end(); itr++)
    {
        if(visited[*itr] == 0)
        {
            c++;
            h = max(h,dfs(*itr)+1);
        }
    }
    if(c==0)
    {
        in[start]=0;
        return 0;
    }
    else
    {
        in[start] = h;
        return h;
    }
}
void foo(int u, int p) // start is root initially
{
    if(p==-1)
    {
        visited[u] = 1;
        out[u] = INT_MIN;
        int h=INT_MIN;
        for(auto itr=graph[u].begin(); itr!=graph[u].end(); itr++)
        {
            if(visited[*itr]==0)
                foo(*itr,u);
            h = max(h,in[*itr]+1);
        }
        height[1] = h;
        return ;
    }
    visited[u]=1;
    int child = INT_MIN;
    int parentchild = INT_MIN;
    for(auto itr=graph[u].begin(); itr!=graph[u].end(); itr++)
    {
        if(*itr!=p)
            child = max(child,in[*itr]);
    }
    for(auto itr=graph[p].begin(); itr!=graph[p].end() ; itr++)
    {
        if(*itr!=u)
        parentchild = max(parentchild,in[*itr]);
    }
    height[u] = max(1+child,max(2+parentchild, 1+out[p]) );
    out[u] = max(parentchild+2,1+out[p]);
    for(auto itr=graph[u].begin(); itr!= graph[u].end(); itr++)
    {
        if(visited[*itr]==0)
            foo(*itr,u);
    }
}

void driver(int n)
{
    dfs(1);
    fill(visited.begin(),visited.end(),0);
    foo(1,-1);
}
int main()
{
    int n;
    cin >> n;
    int a,b;
    for(int i=0; i<n-1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        //graph[b].push_back(a);
    }
    driver(n);
    for(int i=1; i<=n; i++)
        cout << i << " : " << height[i] << endl;
    cout << endl;
    for(int i=1; i<=n; i++)
        cout << i << " : " << in[i] << endl;
    return 0;
}
