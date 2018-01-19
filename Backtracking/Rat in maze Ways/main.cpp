#include <vector>
#include <iostream>
#define n 16
using namespace std;
int matrix[n][n] = {0};
long long int ways = 0;
vector<int> visited[n];
int alreadyvisited[n][n] = {0};
int backtrack(int r, int c, int i)
{
    int  k = 0;
    alreadyvisited[r][c] = 1;
    matrix[r][c] = i;

    if(r+1>=0 && r+1<=n-1 && c>=0 && c<=n-1 && alreadyvisited[r+1][c]==0 && visited[r+1][c]==1)
    {
        k=backtrack(r+1,c,i+1);
        if(k==63)
            return 63;
    }
    if(r>=0 && r<=n-1 && c+1>=0 && c+1<=n-1 && alreadyvisited[r][c+1]==0 && visited[r][c+1]==1)
    {
        k=backtrack(r,c+1,i+1);
        if(k==63)
            return 63;
    }
    if(r==n-1 && c==n-1)
    {
        ways++;
        alreadyvisited[r][c] = 0;
        return 62;
    }
    else
    {
        alreadyvisited[r][c] = 0;
        matrix[r][c] = 0;
        return 62;
    }
}
int main()
{
    int i = 0, j = 0;
    for(i=0;i<n;i++)
    {
        visited[i].resize(n);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            visited[i][j]=1;
        }
    }
    backtrack(0,0,0);
    cout << " Ways : " << ways ;
    return 0;
}
