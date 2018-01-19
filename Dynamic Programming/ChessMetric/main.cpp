#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int> > moves={
                             {0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1},
                             {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},
                             };

int recursion(int n, int i, int j, int a, int b, int k)
{
    int ans=0;
    if(i==a && j==b && k==0)
        return 1;
    if(k==0)
        return 0;
    for(int c=0; c<16; c++)
    {
        if( (moves[c].first+i>=0) && (moves[c].first+i<n) && (moves[c].second+j>=0) && (moves[c].second+j<n) )
            ans += recursion(n,moves[c].first+i,moves[c].second+j,a,b,k-1);
    }
    return ans;
}

int main()
{
    cout << recursion(8,2,3,7,7,9) << endl;
    return 0;
}
