#include <bits/stdc++.h>
#define MAX 10000
using namespace std;
vector<int> visited(MAX,0);
int ans =0;
vector<int> v[MAX];

struct Node
{
    int path;
    int depth;
};

Node lte(int i)
{
    visited[i] = 1;
    int c=0;
    int n1=0,n2=0,n3=0;
    for(auto itr=v[i].begin(); itr!=v[i].end(); itr++)
    {
        if(visited[*itr]==0)
        {
            c++;
            struct Node temp=lte(*itr);
            n2 = max(n2,temp.path);// 2
            if(n1 <= temp.depth) // 2
            {
                n3=max(n1,n3);//0
                n1=max(n1,temp.depth);//2
            }
            else
                n3 = max(n3,temp.depth);
        }
    }
    struct Node ans;
    if(c==0)
    {
        ans.depth=0;
        ans.path=0;
        //cout << ans.path << " " << ans.depth << endl;
        return ans;
    }
    else if(c==1)
    {
        ans.path = max(n2,n1+1);
        ans.depth = n1+1;
        //cout << ans.path << " " << ans.depth << endl;
        return ans;
    }
    else
    {
        ans.path = max(n2,n1+n3+2);
        ans.depth = n1+1;
        //cout << ans.path << " " << ans.depth << endl;
        return ans;
    }
}
int main()
{
    int n;
    cin >> n;
    int a=0,b=0;
    for(int i=0; i<n-1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout << lte(1).path;
    return 0;
}
