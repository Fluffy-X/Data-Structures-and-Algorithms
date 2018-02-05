#include <bits/stdc++.h>

using namespace std;

long N(long n0, long n1, string& s)
{
    long temp=0;
    long a=0;
    double r = 10.0;
    for(long i=n0; i<=n1; i++)
    {
        double b = (pow(r,n1-i))%(1e9+7);
        long a = s[i]-48;
        temp = (temp + (a*b))%1e9+7;
    }
    return temp;
}

long substrings(string st)
{
    vector<long> sum(st.size()); // "12"
    sum[0] = st[0]-48;
    for(long i=1; i<st.size(); i++)
    {
        for(long j=0; j<=i; j++)
            sum[i] = (sum[i] + N(j,i,st)%1e9+7;
        sum[i] = (sum[i] + sum[i-1])%1e9+7;
    }
    return sum[st.size()-1];
}

int main() {
    string balls;
    cin >> balls;
    int result = substrings(balls);
    cout << result << endl;
    return 0;
}
