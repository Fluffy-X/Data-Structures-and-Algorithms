#include <bits/stdc++.h>
using namespace std;

int minSum(vector<int> array, vector<int> prefix, int n, int m)
{
    if(m == 1)
    {
        return prefix[n];
    }
    if(n+1 < m)
    {
        return INT_MAX;
    }
    int a = INT_MIN;
    for(int i=1; i<=n; i++)
    {
        a = max(a,max(minSum(array,prefix,n-i,m-1),prefix[n]-prefix[n-i]));
    }
    return a;
}

int main()
{
    vector<int> array = {7,2,5,10,8};
    vector<int> prefix(array.size(),0);
    for(int i=1; i<array.size(); i++)
        prefix[i] = prefix[i-1] + array[i];
    cout << minSum(array, prefix, 4, 2);
    return 0;

}
