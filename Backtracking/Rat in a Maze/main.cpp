#include <iostream>

using namespace std;
int matrix[4][4] = {0};

int visited[4][4] = {
                      {1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {0, 1, 0, 0},
                      {1, 1, 1, 1}
                    };
int alreadyvisited[4][4] = {0};

int backtrack(int r, int c, int i)
{
    int  k = 0;
    alreadyvisited[r][c] = 1;
    matrix[r][c] = i;

    if(r+1>=0 && r+1<=3 && c>=0 && c<=3 && alreadyvisited[r+1][c]==0 && visited[r+1][c]==1)
    {
        k=backtrack(r+1,c,i+1);
        if(k==63)
            return 63;
    }
    if(r>=0 && r<=3 && c+1>=0 && c+1<=3 && alreadyvisited[r][c+1]==0 && visited[r][c+1]==1)
    {
        k=backtrack(r,c+1,i+1);
        if(k==63)
            return 63;
    }

    if(r==3 && c==3)
        return 63;
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

    backtrack(0,0,1);
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            cout << matrix[i][j] << "       " ;
        }
        cout << endl ;
    }
    return 0;
}
