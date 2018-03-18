#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1000005;
int phi[Maxn];
int func(int x)
{
    int sum=0;
    for(int i=1; i<=x; i++)
    {
        sum = (sum + __gcd(i,x));
        //cout << __gcd(i,x) << endl;
    }
    return sum;

}

set<long long> get_divisors(int n)
{
    set<long long> result;
    for(int i=1; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            result.insert(i);
            result.insert(n/i);
        }
    }
    return result;
}

int totient(long long n)
{
    set<long long> ans;
    float orig = n;
    for(long long j=2; j<=sqrt(n); j++)
    {
        if(n%j==0)
        {
            while(n%j==0)
            {
                ans.insert(j);
                n /= j;
            }
        }
    }
    if(n!=1)
        ans.insert(n);
    float mult=1.0;
    for(auto itr=ans.begin(); itr!=ans.end(); itr++)
    {
        mult=mult*(1.0-1.0/(float)(*itr));
    }
    orig = orig*mult;
    return orig;
}
int gcd_sum(int n)
{
    set<long long> divisors = get_divisors(n);
    long long sum=0;
    for(auto itr=divisors.begin(); itr!=divisors.end(); itr++)
    {
        sum += (*itr)*totient(n/(*itr));
    }
    return sum;
}



int main()
{
   /* for(int i=1; i<=10; i++)
        cout << i << " " << totient(i) << endl;
    //cout << gcd_sum(12) << " " ;
    cout << gcd_sum(14) << " ";
    cout << func(14);*/
    for(int i = 1; i <= 12; i++) { // phi[1....n] in n*log(n)
      phi[i] += i;
      for(int j = 2 * i; j <= 12; j += i) {
         phi[j] -= phi[i];
      }
   }
    for(int i=1; i<=12; i++)
        cout << i << " " << phi[i] << endl;


}

