#include <bits/stdc++.h>
using namespace std;

int ways(int n)
{
    vector<int> v = {3,5,10};
    vector<vector<int> > ways(n+1,vector<int>(4,0));
    //ways[0][0] = 1;
    ways[0][1] = 1;
    ways[0][2] = 1;
    ways[0][3] = 1;

    for(int j=1; j<4; j++)
    {
        for(int i=1; i<n+1; i++)
        {
            if(i-v[j-1] >=0)
                ways[i][j] = ways[i][j-1] + ways[i-v[j-1]][j];
            else
                ways[i][j] = ways[i][j-1];

        }
    }
    return ways[n][3];
}

int main()
{
    cout << ways(20);
    return 0;
}
