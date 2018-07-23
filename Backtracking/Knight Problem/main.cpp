#include <iostream>
#include <vector>
using namespace std;
int visited[8][8] = {0}, matrix[8][8] = {0};
int sample[2][2] = {
                    {1,2},
                    {3,4}
                    };
int backtrack(int r, int c, int i) {
    int  k = 0;
    visited[r][c] = 1;
    matrix[r][c] = i;
    if(r-2>=0 && r-2<=7 && c-1>=0 && c-1<=7 && visited[r-2][c-1]==0) {
        k=backtrack(r-2,c-1,i+1);
        if(k==63)
            return 63;
    }
    if(r-1>=0 && r-1<=7 && c-2>=0 && c-2<=7 && visited[r-1][c-2]==0) {
        k=backtrack(r-1,c-2,i+1);
        if(k==63)
            return 63;
    }
    if(r+1>=0 && r+1<=7 && c-2>=0 && c-2<=7 && visited[r+1][c-2]==0) {
        k=backtrack(r+1,c-2,i+1);
        if(k==63)
            return 63;
    }
    if(r+2>=0 && r+2<=7 && c-1>=0 && c-1<=7 && visited[r+2][c-1]==0) {
        k=backtrack(r+2,c-1,i+1);
        if(k==63)
            return 63;
    }
    if(r+2>=0 && r+2<=7 && c+1>=0 && c+1<=7 && visited[r+2][c+1]==0) {
        k=backtrack(r+2,c+1,i+1);
        if(k==63)
            return 63;
    }
    if(r+1>=0 && r+1<=7 && c+2>=0 && c+2<=7 && visited[r+1][c+2]==0) {
        k=backtrack(r+1,c+2,i+1);
        if(k==63)
            return 63;
    }
    if(r-1>=0 && r-1<=7 && c+2>=0 && c+2<=7 && visited[r-1][c+2]==0) {
        k=backtrack(r-1,c+2,i+1);
        if(k==63)
            return 63;
    }
    if(r-2>=0 && r-2<=7 && c+1>=0 && c+1<=7 && visited[r-2][c+1]==0) {
        k=backtrack(r-2,c+1,i+1);
        if(k==63)
            return 63;
    }
    if(i==63)
        return i;
    else {
        visited[r][c] = 0;
        matrix[r][c] = 0;
        return i;
    }
}
int main()
{
    int i = 0, j = 0;
    backtrack(0,0,0);
    int sum=0;
    for(i=0;i<8;i++) {
        for(j=0;j<8;j++) {
            cout << matrix[i][j] << "       " ;
        }
        cout << endl ;
    }
    return 0;
}
