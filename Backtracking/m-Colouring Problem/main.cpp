#include <iostream>
#define v 10
#define m 3
using namespace std;
//http://www.geeksforgeeks.org/wp-content/uploads/graph_col.png
int graph[v][v] ={
                  {0,1,0,0,1,1,0,0,0,0},
                  {1,0,1,0,0,0,1,0,0,0},
                  {0,1,0,1,0,0,0,1,0,0},
                  {0,0,1,0,1,0,0,0,1,0},
                  {1,0,0,1,0,0,0,0,0,1},
                  {1,0,0,0,0,0,0,1,1,0},
                  {0,1,0,0,0,0,0,0,1,1},
                  {0,0,1,0,0,1,0,0,0,1},
                  {0,0,0,1,0,1,1,0,0,0},
                  {0,0,0,0,1,0,1,1,0,0}
                 };
                 /*{
                 {0,1,1,0,0},
                 {1,0,1,1,0},
                 {1,1,0,1,0},
                 {0,1,1,0,1},
                 {0,0,0,1,0},
                 };*/
int visited[v] = {0};
int answer[v] = {0};
int colourmatrix[v][m]={0};
void backtrack(int i)
{
    int j=0, k=0, r=0;
    if(visited[i]==0)
    {
        visited[i]=1;
        for(j=0;j<m;j++)
        {
            if(colourmatrix[i][j]==0)
            {
                k=j;
                colourmatrix[i][j]=1;
                answer[i]=j;
                break;
            }
        }
        for(r=0;r<v;r++)
        {
            if(r!=i && graph[i][r]==1)
            {
                colourmatrix[r][k]=-1;
            }
        }
        for(j=0;j<v;j++)
        {
            if(graph[i][j]==1 && visited[j]!=1)
            {
                backtrack(j);
            }
        }
    }
}
int main()
{
    int i=0,j=0;
    backtrack(0);
    for(i=0;i<v;i++)
    {
        for(j=0;j<m;j++)
        {
            cout << colourmatrix[i][j] << "  " ;
        }
        cout << endl ;
    }
    cout << endl;
    for(j=0;j<v;j++)
    {
        cout << answer[j] << "  " ;
    }
    return 0;
}
