#include <bits/stdc++.h>
using namespace std;

int minways(int n, unordered_map<int,int>& m, vector<int>& a)
{
    int ans = 1000;
    if(m.find(n) != m.end() )
        return m[n];
    else
    {
        for(int i=0; i<3; i++)
        {
            if(n-a[i]<0)
                continue;
            else if(m.find(n-a[i]) != m.end())
                ans = min(ans, m[n-a[i]]);
            else
            {
                m.insert(make_pair( n-a[i], minways(n-a[i],m,a) ));
                ans = min(ans,m[n-a[i]]);
            }
        }
        m[n] = ans+1;
        return m[n];
    }
}
int main()
{

    return 0;
}
