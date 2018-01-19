#include <bits/stdc++.h>
using namespace std;
//BOTTOM UP
void lcs(string& sa, string& sb, vector<vector<int> >& mem)
{
    int n = sa.size();
    int m = sb.size();
    int k = 0;
    int x = 0;
    for(int i=1; i<=min(n,m); i++)
    {

        for(k=i; k<=n; k++)
        {
            if(sa[k-1]==sb[i-1])
            {
                mem[i][k]=max(mem[i-1][k],max(mem[i][k-1],1+mem[i-1][k-1]));
            }
            else
                mem[i][k]=max(mem[i-1][k],mem[i][k-1]);
        }
        for(k=i; k<=m; k++)
        {
            if(sa[i-1]==sb[k-1])
            {
                mem[k][i]=max(mem[k][i-1],max(mem[k-1][i],1+mem[i-1][k-1]));

            }
            else
                mem[k][i]=max(mem[k][i-1],(mem[k-1][i]));
        }
    }
    for (int i = 0; i < mem.size(); i++)
    {
        for (int j = 0; j < mem[i].size(); j++)
        {
            cout << mem[i][j] << " ";
        }
        cout << endl;
    }
    cout << mem[m][n];
}
int main()
{
    string sa="bdshssasabdshssasabdshssasa";
    string sb="bdshs";
    int n=sa.size()+1;
    int m=sb.size()+1;
    vector<vector<int> > mem(m,vector<int>(n));
    lcs(sa,sb,mem);
}
