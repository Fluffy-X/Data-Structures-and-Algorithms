#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    long long m;
    cin >> n >> m;
    vector<long long> v(n+2);
    for(long long a0 = 0; a0 < m; a0++)
    {
        long long a;
        long long b;
        long long k;
        cin >> a >> b >> k;
        v[a] += k;
        v[b+1] -= k;
    }
    long long ans=LONG_MIN;
    long long sum = 0;
    for(long long i=1; i<n+2; i++)
    {
        v[i] = v[i] + sum;
        sum = v[i];
    }
    for(long long i=1; i<n+2; i++)
        ans = max(ans,v[i]);
    cout << ans;
    return 0;
}
