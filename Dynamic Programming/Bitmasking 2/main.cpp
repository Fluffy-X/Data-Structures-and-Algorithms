#include <bits/stdc++.h>
using namespace std;
#define memsize 15
vector<vector<long long> > v = {
                        {9,2,7,8},
                        {6,4,3,7},
                        {5,8,1,8},
                        {7,6,9,4}
                        };
vector<long long> memo(pow(2,memsize),-1);
long long ways(long long mask) // isitially mask = 1111
{
    if(mask==pow(2,memsize)-1)
    {
        for(long long i=0; i<memsize; i++)
        {
            memo[1<<i] = 1;
        }
    }
    long long n=memsize;
    long long a=0;
    if(memo[mask] != -1)
        return memo[mask];
    for(long long j=0; j<n; j++)
    {
        if( ((mask)&(1<<j)) != 0)
            a+= ways(((mask)&(~(1UL << j))));
    }
    memo[mask] = a;
    return a;
}
long long mincost()
{
    long long n = v.size();
    long long m = pow(2,n);
    long long x=0;
    vector<long long> dp(m,1000);
    dp[0] = 0;

    for(long long j=0; j<m-1; j++)
    {
        x=0;
        for(long long i=0; i<n; i++)
        {
            if( ((j)&(1<<i)) != 0)
                x++;
        }//cout << x << endl;
        for(long long i=0; i<n; i++)
        {
            if( ((j)&(1<<i)) == 0)
            {
                dp[ (j)|(1<<i) ] = min(dp[(j)|(1<<i)], dp[j] + v[x][i] );
            }
        }
    }
    for(long long j=0; j<m; j++)
    {
        cout << j << " : " << dp[j] << endl;
    }

}
int main()
{
    cout << ways(pow(2,memsize)-1) << endl ;
   /* long long number = 7;
    number &= ~(1UL << 2);
    cout << number << endl;
    cout << endl;*/
    //mincost();
    return 0;
}
