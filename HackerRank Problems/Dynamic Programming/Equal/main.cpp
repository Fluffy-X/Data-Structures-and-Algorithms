#include <bits/stdc++.h>
using namespace std;
long long minways(long long n, unordered_map<long long,long long>& m, vector<long long>& a)
{
    long long ans = 1000;
    if(m.find(n) != m.end() )
        return m[n];
    else
    {
        for(long long i=0; i<3; i++)
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
int main() {
    long long t;
    vector<long long> a = {1,2,5};
    cin >> t;
    unordered_map<long long,long long> m;
    m[0]=0;
    for(long long i=0; i<a.size(); i++)
        m[a[i]]=1;
    for(long long a0 = 0; a0 < t; a0++){
        long long n;
        cin >> n;
        vector<long long> v(n);
        long long mini=100000000;
        for(long long arr_i = 0; arr_i < n; arr_i++)
        {
           cin >> v[arr_i];
           mini = min(mini, v[arr_i]);
        }
        int count=0;
        for(long long arr_i = 0; arr_i < n; arr_i++)
        {
            if(v[arr_i]==mini)
                count++;
        }
        int limit=0;
        if(mini == 4 )
            limit=5;
        else if(mini == 3 )
            limit=4;
        else if(mini == 2 )
            limit=3;
        else if(mini ==1)
            limit =2;
        else
            limit=1;
        for(int arr_i = 0; arr_i < n; arr_i++)
            v[arr_i] -= mini;
        long long ans=0;
        long long final=100000000;
        for(long long arr_j = 0; arr_j < limit; arr_j++) //
        {
            for(long long arr_i = 0; arr_i < n; arr_i++)
               ans += minways(v[arr_i],m,a);
            for(int arr_i = 0; arr_i < n; arr_i++)
            {
                if(v[arr_i] != 0)
                    v[arr_i] += 1;
            }
            final = min(final,ans);
            ans = count;
        }
        cout << final << endl;
    }
    return 0;
}
