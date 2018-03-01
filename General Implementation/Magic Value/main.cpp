#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int findGCD(vector<int> arr, int n, int i, int j)
{
    int result = arr[i];
    for (int i=i; i<j; i++)
        result = __gcd(arr[i], result);

    return result;
}

int main() {
    int n;
    cin >>n ;
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    long ans=0;
    for(int i=0; i<n; i++)
    {
        int vmin = INT_MAX;
        int vmax = INT_MIN;
        for(int j=i+1; j<n; j++)
        {
            cout << findGCD(v,n,i,j) << endl;
            int temp = ((i+1)*findGCD(v,n,i,j))%MOD;
            vmax = max(vmax,temp);
            vmin = min(vmin,temp);
        }
        ans += ((vmax-vmin)*(i+1))%MOD;
    }
   cout << ans;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
