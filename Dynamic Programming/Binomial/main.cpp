#include <bits/stdc++.h>
using namespace std;

int binomial(int n, int k)
{
    if(k==0)
        return 1;
    else
        return (n*binomial(n-1,k-1))/k;
}

int main()
{
    cout << binomial(5,2) << endl;
    cout << binomial(5,5) << endl;
    cout << binomial(100,4) << endl;





    return 0;
}
