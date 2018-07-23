#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > one_nine[10];
int initial_no = 0;
int ri=0,cj=0;
void update(vector<vector<int> >& m, int r, int c)
{
    int c1 = 0, r1 = 0;
    if(c < 3 && r < 3)
    {
        for(c1 = 0 ; c1 < 9 ; c1++) {
            m[r][c1] = 1;
        }
        for(r1 = 0 ; r1 < 9 ; r1++)
        {
            m[r1][c] = 1;
        }
        for(r1 = 0 ; r1 < 3 ; r1++)
        {
            for(c1 = 0 ; c1 < 3 ; c1++)
            {
                m[r1][c1] = 1;
            }
        }
    }
    if(c < 3 && r > 2 && r < 6)
    {
        for(c1 = 0 ; c1 < 9 ; c1++)
        {
            m[r][c1] = 1;
        }
        for(r1 = 0 ; r1 < 9 ; r1++)
        {
            m[r1][c] = 1;
        }
        for(r1 = 3 ; r1 < 6 ; r1++)
        {
            for(c1 = 0 ; c1 < 3 ; c1++)
            {
                m[r1][c1] = 1;
            }
        }
    }
    if(c < 3 && r > 5 && r < 9)
    {
        for(c1 = 0 ; c1 < 9 ; c1++)
        {
            m[r][c1] = 1;
        }
        for(r1 = 0 ; r1 < 9 ; r1++)
        {
            m[r1][c] = 1;
        }
        for(r1 = 6 ; r1 < 9 ; r1++)
        {
            for(c1 = 0 ; c1 < 3 ; c1++)
            {
                m[r1][c1] = 1;
            }
        }
    }
    if(c > 2 && c < 6 && r < 3)
    {
        for(c1 = 0 ; c1 < 9 ; c1++)
        {
            m[r][c1] = 1;
        }
        for(r1 = 0 ; r1 < 9 ; r1++)
        {
            m[r1][c] = 1;
        }
        for(r1 = 0 ; r1 < 3 ; r1++)
        {
            for(c1 = 3 ; c1 < 6 ; c1++)
            {
                m[r1][c1] = 1;
            }
        }
    }
    if(c > 2 && c < 6 && r > 2 && r < 6)
    {
        for(c1 = 0 ; c1 < 9 ; c1++)
        {
            m[r][c1] = 1;
        }
        for(r1 = 0 ; r1 < 9 ; r1++)
        {
            m[r1][c] = 1;
        }
        for(r1 = 3 ; r1 < 6 ; r1++)
        {
            for(c1 = 3 ; c1 < 6 ; c1++)
            {
                m[r1][c1] = 1;
            }
        }
    }
    if(c > 2 && c < 6 && r > 5 && r < 9)
    {
        for(c1 = 0 ; c1 < 9 ; c1++)
        {
            m[r][c1] = 1;
        }
        for(r1 = 0 ; r1 < 9 ; r1++)
        {
            m[r1][c] = 1;
        }
        for(r1 = 6 ; r1 < 9 ; r1++)
        {
            for(c1 = 3 ; c1 < 6 ; c1++)
            {
                m[r1][c1] = 1;
            }
        }
    }


    if(c > 5 && c < 9 && r < 3)
    {
        for(c1 = 0 ; c1 < 9 ; c1++)
        {
            m[r][c1] = 1;
        }
        for(r1 = 0 ; r1 < 9 ; r1++)
        {
            m[r1][c] = 1;
        }
        for(r1 = 0 ; r1 < 3 ; r1++)
        {
            for(c1 = 6 ; c1 < 9 ; c1++)
            {
                m[r1][c1] = 1;
            }
        }
    }
    if(c > 5 && c < 9 && r > 2 && r < 6)
    {
        for(c1 = 0 ; c1 < 9 ; c1++)
        {
            m[r][c1] = 1;
        }
        for(r1 = 0 ; r1 < 9 ; r1++)
        {
            m[r1][c] = 1;
        }
        for(r1 = 3 ; r1 < 6 ; r1++)
        {
            for(c1 = 6 ; c1 < 9 ; c1++)
            {
                m[r1][c1] = 1;
            }
        }
    }
    if(c > 5 && c < 9 && r > 5 && r < 9)
    {
        for(c1 = 0 ; c1 < 9 ; c1++)
        {
            m[r][c1] = 1;
        }
        for(r1 = 0 ; r1 < 9 ; r1++)
        {
            m[r1][c] = 1;
        }
        for(r1 = 6 ; r1 < 9 ; r1++)
        {
            for(c1 = 6 ; c1 < 9 ; c1++)
            {
                m[r1][c1] = 1;
            }
        }
    }
}
void initialize(vector<vector<int> >& m)
{
    int i = 0, j = 0, k = 0;
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(m[i][j]!=0)
            {
                update(one_nine[m[i][j]-1],i,j);
                for(k=0; k<9; k++)
                {
                    one_nine[k][i][j]=1;
                }
            }
        }
    }
}
int rowscheck(int index)
{
    int i,j,k,count;
    for(i=0; i<9; i++)
    {
        count=0;
        for(j=0; j<9; j++)
        {
            if(one_nine[index][i][j]==0)
            {
                count++;
                ri=i;cj=j;
                //cout << "ri : " << ri << " " << cj << endl ;
            }
        }
        if(count==1)
        {
            return 1;
        }
    }
    return 0;
}
int columnscheck(int index)
{
    int i,j,k,count;
    for(i=0; i<9; i++)
    {
        count = 0;
        for(j=0; j<9; j++)
        {
            if(one_nine[index][j][i]==0)
            {
                count++;
                ri=j;cj=i;
            }
        }
        if(count==1)
        {
            return 1;
        }
    }
    return 0;
}
int blockcheck(int index)
{
    int i,j,k,count=0;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(one_nine[index][i][j]==0)
            {
                count++;
                ri=i;cj=j;
            }
        }
    }
    if(count==1)
    {
        return 1;
    }
    count=0;
    for(i=0; i<3; i++)
    {
        for(j=3; j<5; j++)
        {
            if(one_nine[index][i][j]==0)
            {
                count++;
                ri=i;cj=j;
            }
        }
    }
    if(count==1)
    {
        return 1;
    }
    count=0;
    for(i=0; i<3; i++)
    {
        for(j=6; j<9; j++)
        {
            if(one_nine[index][i][j]==0)
            {
                count++;
                ri=i;cj=j;
            }
        }
    }
    if(count==1)
    {
        return 1;
    }
    count = 0;
    for(i=3; i<5; i++)
    {
        for(j=0; j<3; j++)
        {
            if(one_nine[index][i][j]==0)
            {
                count++;
                ri=i;cj=j;
            }
        }
    }
    if(count==1)
    {
        return 1;
    }
    count = 0;
    for(i=3; i<5; i++)
    {
        for(j=3; j<5; j++)
        {
            if(one_nine[index][i][j]==0)
            {
                count++;
                ri=i;cj=j;
            }
        }
    }
    if(count==1)
    {
        return 1;
    }
    count=0;
    for(i=3; i<5; i++)
    {
        for(j=6; j<9; j++)
        {
            if(one_nine[index][i][j]==0)
            {
                count++;
                ri=i;cj=j;
            }
        }
    }
    if(count==1)
    {
        return 1;
    }
    count = 0;
    for(i=6; i<9; i++)
    {
        for(j=0; j<3; j++)
        {
            if(one_nine[index][i][j]==0)
            {
                count++;
                ri=i;cj=j;
            }
        }
    }
    if(count==1)
    {
        return 1;
    }
    count = 0;
    for(i=6; i<9; i++)
    {
        for(j=3; j<6; j++)
        {
            if(one_nine[index][i][j]==0)
            {
                count++;
                ri=i;cj=j;
            }
        }
    }
    if(count==1)
    {
        return 1;
    }
    count = 0;
    for(i=6; i<9; i++)
    {
        for(j=6; j<9; j++)
        {
            if(one_nine[index][i][j]==0)
            {
                count++;
                ri=i;cj=j;
            }
        }
    }
    if(count==1)
    {
        return 1;
    }
    return 0;
}

int check(int i)
{
    if(rowscheck(i))
        return 1;
    else if(columnscheck(i))
        return 1;
    else if(blockcheck(i))
        return 1;
    else
        return 0;

}
void sudoku_logic(vector<vector<int> >& m)
{
    int i = 0, j = 0;
    for(;initial_no!=81;)
    {
        for(i=0;i<9;i++)
        {
            for(;check(i);)
            {
                //cout << "Test : " << i << " " << endl;
                update(one_nine[i],ri,cj);
                for(j=0;j<9;j++)
                {
                    one_nine[j][ri][cj]=1;
                }
                m[ri][cj]=i+1;
                initial_no++;
            }
        }

    }
}

void resize(vector<vector<int> >& m)
{
    int i = 0;
    for(i = 0 ; i < 9 ; i++)
    {
        one_nine[i].resize(9,{0,0,0,0,0,0,0,0,0});
    }
    one_nine[0]=m;
}
int no_of_entries(vector<vector<int> >& m)
{
    int i = 0, j = 0;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(m[i][j]==0)
                initial_no++;
        }
    }
    return 81-initial_no;
}
int main()
{
    vector<vector<int> > m {
                      {3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 0, 9, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}
                      };
    initial_no = no_of_entries(m);
    int i = 0, j = 0;
    resize(m);
    initialize(m);
    sudoku_logic(m);
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            cout << m[i][j] << " " ;
        }
        cout << endl ;
    }
    return 0;
}
