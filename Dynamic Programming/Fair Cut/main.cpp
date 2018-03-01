#include <bits/stdc++.h>
using namespace std;
long long calculate(vector<long long> &v, long long i, long long n)
{
    long long left=0;
    long long right = 0;
    long long left_index=n/2-i-1;
    long long right_index=n/2+i;

    for(long long j=0; j<n; j++)
    {
        if(j < n/2-i-1 || j > n/2+i)
        {
            left += abs(v[j]-v[left_index]);
            right += abs(v[j]-v[right_index]);
        }
    }
    if(right > left)
        return v[left_index];
    else
        return v[right_index];
}

using namespace std;
int main() {
    long long n;
    cin >> n;
    long long k;
    cin >> k;
    vector<long long> v(n);
    for(long long i=0; i<n; i++)
        cin >> v[i];
    sort(v.begin(),v.end());
    unordered_set<long long> one;
    long long i=0;
    while(k!=0)
    {
        if(n%2==0)
        {
            while(k>=2)
            {
                one.insert(v[n/2+i]);
                one.insert(v[n/2-1-i]);
                i++;k--;k--;
            }
            if(k==0)
                break;
            else
            {
                one.insert(calculate(v,i,n));
                k--;
            }
        }
        else
        {
            one.insert(v[n/2]);
            k--;
            i=1;
            while(k>=2)
            {
                one.insert(v[n/2+i]);
                one.insert(v[n/2-i-1]);
                i++;k--;k--;
            }
            if(k==0)
                break;
            else
            {
                one.insert(calculate(v,i,n));
                k--;
            }
        }
    }
    unordered_set<long long> two;
    for(long long i=0; i<n; i++)
    {
        if(one.find(v[i])==one.end())
            two.insert(v[i]);
    }
    long long ans = 0;
    for(auto itr=one.begin(); itr!= one.end(); itr++)
    {
        for(auto it=two.begin(); it!= two.end(); it++)
        {
            ans += abs(*itr-(*it));
        }
    }
    int c=1;long long sum=0;
    for(auto i : v)
    {
        cout << c << " " << i << endl;
        if(c >=5 && c <= 14 )
            sum+=v[c-1];
        c++;
    }
    cout << ans;
    return 0;
}
