#include <bits/stdc++.h>
using namespace std;

int maximum_sub_matrix(vector<vector<int> >& m)
{
    vector<vector<int>> s(m.size(), vector<int>(m[0].size(),-1));
    int nor=m.size();
    int noc=m[0].size();
    int a=-1;
    for(int i=0; i<noc; i++)
        s[0][i]=m[0][i];
    for(int i=0; i<nor; i++)
        s[i][0]=m[i][0];
    for(int i=1; i<min(nor,noc); i++)
    {
        if(i<noc)
        {
            for(int k=i; k<noc; k++)
            {
                if(m[i][k]==0)
                    s[i][k]=0;
                else
                {

                    s[i][k]=min(min(s[i-1][k-1],s[i][k-1]),s[i-1][k])+1;
                    a=max(a,s[i][k]);
                }
            }
        }
        if(i<nor)
        {
            for(int k=i; k<nor; k++)
            {
                if(m[k][i]==0)
                    s[k][i]=0;
                else
                {
                    s[k][i]=min(min(s[k-1][i],s[k][i-1]),s[k-1][i-1])+1;
                    a=max(a,s[k][i]);
                }
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
    return a;
}

int main()
{
    vector<vector<int> > v={
                           /*{0,1,1,0,1},
                           {1,1,0,1,0},
                           {0,1,1,1,0},
                           {0,1,1,1,0},
                           {1,1,1,1,1},
                           {0,0,0,0,0}*/
                           {0,0,0,0,0,0,1,1},
                           {0,0,0,0,0,0,1,1},
                           {0,0,0,0,0,0,1,1},
                           {0,0,0,0,0,0,1,1},
                           {0,0,0,0,0,0,1,1},
                           {0,0,0,0,0,1,1,1},
                           {0,0,0,0,0,1,1,1},
                           {0,0,0,0,0,1,1,1},
                           {0,0,1,1,1,1,1,1},
                           {0,0,1,1,1,1,1,1},
                           {0,0,1,1,1,1,1,1},
                           {0,0,1,1,1,1,1,1},
                           {0,0,0,0,0,0,1,1},
                           };
    cout << maximum_sub_matrix(v);
    return 0;
}
