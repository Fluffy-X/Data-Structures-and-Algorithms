#include <bits/stdc++.h>

using namespace std;


bool ans(int i0, int j0, int n, int m, string a, string b, vector<vector<int> >& memo)
{

    int j=j0;
    int i=i0;
    if(j0==m)
    {
        for(int k=i; k<n; k++)
        {
            if(a[k] < 'a')
                return 0;
        }
        return 1;
    }
    if(i0==n)
        return 0;
    if(a[i] < 'a' && a[i] != b[j]) // A C
        return 0;
    else if(a[i] < 'a' && a[i] == b[j]) // A A
    {
        if(memo[i][j]!=-1)
            return memo[i][j];
        else
            memo[i][j] = ans(i+1,j+1,n,m,a,b,memo);
        return memo[i][j];
    }
    else if(a[i]-32 == b[j]) //
    {
        if(memo[i][j]!=-1)
            return memo[i][j];
        else
            memo[i][j] = ans(i+1,j+1,n,m,a,b,memo) || ans(i+1,j,n,m,a,b,memo);
        return memo[i][j];
    }
    else
    {
        if(memo[i][j]!=-1)
            return memo[i][j];
        else
            memo[i][j] = ans(i+1,j,n,m,a,b,memo);
        return memo[i][j];
    }
}

string abbreviation(string a, string b, vector<vector<int> >& memo)
{
    string y="YES";
    string n="NO";
    bool val = ans(0,0,a.size(),b.size(),a,b,memo);
    if(val)
        return y;
    else
        return n;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string a;
        cin >> a;
        string b;
        cin >> b;
        vector<vector<int> > memo(a.size()+10,vector<int>(b.size()+10,-1));// If declared as MAX then it gets time out
        string result = abbreviation(a, b, memo);
        cout << result << endl;
    }
    return 0;
}
