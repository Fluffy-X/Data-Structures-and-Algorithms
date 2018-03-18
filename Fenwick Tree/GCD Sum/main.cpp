#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int func(int x)
{
    int sum=0;
    for(int i=1; i<=x; i++)
    {
        sum = (sum + __gcd(i,x))%MOD;
        //cout << __gcd(i,x) << endl;
    }
    return sum;

}

int main()
{
    //cout << func(1) << endl <<endl;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    int q,x,y;

    char t;
    cin >> q;
    for(int i=0; i<q; i++)
    {
        cin >> t >> x >> y;
        x--;y--;
        if(t =='C')
        {
            int temp=x;
            int sum=0;
            while(x!=y+1)
            {
                sum = (sum + func(a[x]))%MOD;
                x++;
            }
            cout << sum << endl;
        }
        else
            a[x] = y+1;
    }
    return 0;
}
