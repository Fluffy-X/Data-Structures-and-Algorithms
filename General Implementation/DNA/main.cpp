#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int arr[536870912/2];
LL comb(LL n, LL k)
{
    if(k==0)
        return 1;
    return n*comb(n-1,k-1)/k;
}
LL power(LL a, LL b)
{
    LL pow = 1;
    while ( b )
    {
        if ( b & 1 )
        {
            pow = pow * a;
            --b;
        }
        a = a*a;
        b = b/2;
    }
    return pow;
}
long long func(long long k, long long n)
{
    LL w = k;
    if(k==0)
        return 0;
    long long ans=power(2.0,n)-1;
    long long i=1;
    for(; k>=1; k)
    {
        ans += power(-1.0,i)*comb(w,k)*power(2.0,n-i);
        k--;
        i++;
    }
    return ans;
}
long long winningHands(long long m, long long x, vector <long long> a) {
    // Complete this function
    long long ans=0;
    long long n = a.size();
    LL perfect=0;
    vector<int> gg;
    vector<int> mod;

    for(int i=0; i<n; i++)
    {
        if(a[i]%m==0)
            perfect++;
        else
            mod.push_back(a[i]);
    }
    int temp=0;
    for(int i=0; i<n; i++)
    {
        if(mod[i]%m==1)
            temp++;
    }
    //vector<int> tester(power(2,mod.size()-temp));
    long long pre = func(perfect,a.size());
    for(long long i=0; i<power(2,mod.size()); i++)
    {
        long long temp=1;
        for(long long j=0; j<mod.size(); j++)
        {
            if( ((i)&(1<<j)) != 0 )
                temp = (temp*mod[j])%m;
        }
        if(temp%m == x)
            ans++;
    }
    return ans+pre;
}

int main() {
    long long n;
    long long m;
    long long x;
    cin >> n >> m >> x;
    vector<long long> a(n);
    for(long long a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    long long result = winningHands(m, x, a);
    cout << result << endl;
    return 0;
}
