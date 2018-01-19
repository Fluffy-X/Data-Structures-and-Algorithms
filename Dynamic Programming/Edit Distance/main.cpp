#include <bits/stdc++.h>
using namespace std;

int edit_distance(string x, string y)
{
    vector<vector<int> > memo(x.size(),vector<int>(y.size(),0));
    int r = x.size();
    int c = y.size();
    int a=1;
    int j;
    for(int i=0; i<c; i++)
    {
        if(x[0]==y[i])
        {
            memo[0][i]=i;
            a=0;
        }
        else if(a)
            memo[0][i]=i+1;
        else
            memo[0][i]=i;
    }
    a=1;
    for(int i=0; i<r; i++)
    {
        if(y[0]==x[i])
        {
            memo[i][0]=i;
            a=0;
        }
        else if(a)
            memo[i][0]=i+1;
        else
            memo[i][0]=i;
    }
    for(int i=1; i<min(r,c); i++)
    {
        for(j=i; j<c; j++)
        {
            if(x[i]==y[j])
                memo[i][j]=min(memo[i-1][j-1],1+min(memo[i-1][j],memo[i][j-1]));
            else
                memo[i][j]=1 + min(memo[i-1][j],min(memo[i][j-1],memo[i-1][j-1]));
        }
        for(j=i+1; j<r; j++)
        {
            if(x[j]==y[i])
                memo[j][i]=min(memo[j-1][i-1],1+min(memo[j-1][i],memo[j][i-1]));
            else
                memo[j][i]=1 + min(memo[j-1][i],min(memo[j][i-1],memo[j-1][i-1]));
        }
    }
    for(int i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }
    return memo[r-1][c-1];
}


int main()
{
    string a="mart";
    string b="karma";
    //cout << edit_distance(b,a);
    for(int i=1,int j=5; i<8; i++){
        cout << "1" ;
    }
    return 0;
}
