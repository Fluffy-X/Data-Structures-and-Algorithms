#include <bits/stdc++.h>
#define n 4
#define m 4
long long mem[n][m]={0};
using namespace std;


long long ways(long long x, long long y)
{
    if(x==n-1 || y==m-1)
    {
        mem[x][y]=1;
        return mem[x][y];
    }
    if(mem[x][y]!=0)
        return mem[x][y];
    else
    {
        mem[x][y]=ways(x+1,y)+ways(x,y+1);
        return mem[x][y];
    }
}

int main()
{
    cout << ways(0,0);
    return 0;
}
