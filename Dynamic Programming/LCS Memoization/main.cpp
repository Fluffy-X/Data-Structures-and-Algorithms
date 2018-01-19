#include <bits/stdc++.h>
using namespace std;

int lcs(int i, int j, string& sa, string& sb,  vector<vector<int> >& mem)
{
    if(i<0 || j<0)
        return 0;
    if(sa[i]==sb[j])
    {

        if(mem[i-1][j-1]==-1)
        {
            mem[i][j]=lcs(i-1,j-1,sa,sb,mem)+1;
            return mem[i][j];
        }
        else
            mem[i-1][j-1]+1;
    }
    else
    {
        if(mem[i-1][j]!=-1)
        {
            if(mem[i][j-1]!=-1)
                return max(mem[i-1][j],mem[i][j-1]);
            else
                mem[i][j-1]=lcs(i,j-1,sa,sb,mem);
                return max(mem[i-1][j],mem[i][j-1]);
        }
        else
        {
            mem[i-1][j]=lcs(i-1,j,sa,sb,mem);
            if(mem[i][j-1]!=-1)
                return max(mem[i-1][j],mem[i][j-1]);
            else
            {
                mem[i][j-1]=lcs(i,j-1,sa,sb,mem);
                return max(mem[i-1][j],mem[i][j-1]);
            }
        }
    }
}

int main()
{
    string sa="ABCA";
    string sb="BA";
    int r=sb.size()+1;
    int c=sa.size()+1;
    int s = max(r,c);
    vector<vector<int> > mem(s+1,vector<int>(s+1,-1));
    for (int j = 0; j < mem[0].size(); j++)
    {
        mem[0][j] =0;
        mem[j][0] =0;
    }
    for (int i = 0; i < mem.size(); i++)
    {
        for (int j = 0; j < mem[i].size(); j++)
        {
            cout << mem[i][j] << " ";
        }
        cout << endl;
    }
    cout << lcs(3,1,sa,sb,mem);
    //cout << "Hello world!" << endl;
    return 0;
}
