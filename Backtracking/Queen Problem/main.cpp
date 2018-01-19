#include <iostream>
#include <vector>
#define n 10
using namespace std;
vector<int> visited[n];
vector<int> answer[n];

// visited = = traced

bool range(int r, int c)
{
    if(r<0 || r>=n || c<0 || c>=n)
        return false;
    else
        return true;
}
void demodify(int r, int c)
{
    int r1=r, c1=c,i=0;
    for(i=0;i<n;i++)
    {
        if(i!=c)
            visited[r][i]--;
    }
    for(i=0;i<n;i++)
    {
        visited[i][c]--;
    }

    for(r--,c--;;r--,c--)
    {
        if(range(r,c))
        {
            visited[r][c]--;
        }
        else
            break;
    }r = r1; c = c1;
    for(r++,c++;;r++,c++)
    {
        if(range(r,c))
        {
            visited[r][c]--;
        }
        else
            break;
    }r = r1; c = c1;
    for(r++,c--;;r++,c--)
    {
        if(range(r,c))
        {
            visited[r][c]--;
        }
        else
            break;
    }r = r1; c = c1;
    for(r--,c++;;r--,c++)
    {
        if(range(r,c))
        {
            visited[r][c]--;
        }
        else
            break;
    }r = r1; c = c1;
}
void modify(int r, int c)
{
    int r1=r, c1=c,i=0;
    for(i=0;i<n;i++)
    {
        if(i!=c)
            visited[r][i]++;
    }
    for(i=0;i<n;i++)
    {
        visited[i][c]++;
    }

    for(r--,c--;;r--,c--)
    {
        if(range(r,c))
        {
            visited[r][c]++;
        }
        else
            break;
    }r = r1; c = c1;
    for(r++,c++;;r++,c++)
    {
        if(range(r,c))
        {
            visited[r][c]++;
        }
        else
            break;
    }r = r1; c = c1;
    for(r++,c--;;r++,c--)
    {
        if(range(r,c))
        {
            visited[r][c]++;
        }
        else
            break;
    }r = r1; c = c1;
    for(r--,c++;;r--,c++)
    {
        if(range(r,c))
        {
            visited[r][c]++;
        }
        else
            break;
    }r = r1; c = c1;
}
int backtrack(int r, int c, int count)
{
    int i=0,k=0,j=0;
    for(i=r;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(visited[i][j]==0)
            {
                //cout << i << " " << j << " " << count << endl ;
                modify(i,j);
                k=backtrack(i,j,count+1);
                if(k==n)
                {
                    answer[i][j] = 1;
                    return n;
                }

            }
        }
    }
    if(count==n)
    {
        answer[r][c] = 1;
        return n;
    }
    else
    {
        demodify(r,c);
        return -50;
    }
}
int main()
{
    int i = 0, j = 0;
    for(j=0;j<n;j++)
    {
        visited[j].resize(n);
    }
    for(j=0;j<n;j++)
    {
        answer[j].resize(n);
    }
    backtrack(0,0,0);
    i=0;j=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout << answer[i][j] << " " ;
        }
        cout << endl ;
    }
    return 0;
}
