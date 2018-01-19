#include <bits/stdc++.h>
using namespace std;

void maximum_sub_matrix(vector<vector<int> >& m)
{
    vector<vector<int>> s(m.size(), vector<int>(m[0].size(),-1));
    int nor=m.size();
    int noc=m[0].size();
    s[0][0]=m[0][0];
    for(int i=1; i<noc; i++)
        s[0][i]=s[0][i-1] + m[0][i];
    for(int i=1; i<nor; i++)
        s[i][0]=s[i-1][0] + m[i][0];
    for(int i=1; i<min(nor,noc); i++)
    {
        if(i<noc)
        {
            for(int k=i; k<noc; k++)
                s[i][k]=m[i][k] + min(min(s[i-1][k],s[i][k-1]),s[i-1][k-1]);
        }
        if(i<nor)
        {
            for(int k=i; k<nor; k++)
            {
                s[k][i]=m[k][i] + min( min( s[i-1][k], s[i][k-1] ), s[i-1][k-1] );
            }
        }
    }
    for(int i=0; i<nor; i++)
    {
        for(int j=0; j<noc; j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int> > v={
                           {1,2,3},
                           {4,8,2},
                           {1,5,3},
                           };
    maximum_sub_matrix(v);
    return 0;
}
