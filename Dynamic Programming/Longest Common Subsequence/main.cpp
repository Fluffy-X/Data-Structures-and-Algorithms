// Longest Common Subsequence
#include <bits/stdc++.h>
using namespace std;

int LCS(string a, string b, int i, int j)
{
	if(i == a.size() || j == b.size())
		return 0;
	if(a[i] == b[j])
		return 1+LCS(a,b,i+1,j+1);
	else
		return max(LCS(a,b,i,j+1), LCS(a,b,i+1,j));
}
int LCS_three(string a, string b, string c, int i, int j, int k)
{
	if(i == a.size() || j == b.size() || k == c.size())
		return 0;
	if(a[i] == b[j] && a[i] == c[k])
		return 1+LCS_three(a,b,c,i+1,j+1,k+1);
	else
		return max(LCS_three(a,b,c,i,j+1,k), max(LCS_three(a,b,c,i+1,j,k), max(LCS_three(a,b,c,i,j,k+1), max(LCS_three(a,b,c,i+1,j+1,k), max(LCS_three(a,b,c,i,j+1,k+1), LCS_three(a,b,c,i+1,j,k+1))))));
}
int LCS_three_fast(string a, string b, string c)
{
    vector<vector<vector<int> > > m(a.size()+1,vector<vector<int> >(b.size()+1, vector<int>(c.size()+1,0)));
    for(int i=1; i<=a.size(); i++)
    {
        for(int j=1; j<=b.size(); j++)
        {
            for(int k=1; k<=c.size(); k++)
            {
                if(a[i-1] == b[j-1] && a[i-1] == c[k-1])
                    m[i][j][k] = 1 + m[i-1][j-1][k-1];
                else
                    m[i][j][k] = max(max(max(max(m[i][j-1][k], m[i-1][j][k]), m[i][j][k-1]), m[i-1][j-1][k]), m[i][j-1][k-1]);
            }

        }
    }
    return m[a.size()][b.size()][c.size()];
}

string LCS_fast(string a, string b)
{
	vector<vector<int> > v(a.size()+1,vector<int>(b.size()+1,0));
	string ans;
	for(int i=1; i <=a.size(); i++)
	{
		for (int j = 1; j <= b.size(); ++j)
		{
			if(a[i-1]==b[j-1])
				v[i][j] = v[i-1][j-1]+1;
			else
			{
				v[i][j] = max(v[i-1][j],v[i][j-1]);
			}
		}
	}
/*	for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }*/
	int j = b.size();
	for(int i=a.size(); i != 0 && j != 0;)
	{
		if(a[i-1] == b[j-1])
        {
            ans.push_back(a[i-1]);
            i--;j--;
        }
		else
		{
			if(v[i-1][j] > v[i][j-1])
				i--;
			else
				j--;
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
    int t;
    cin >> t;
    string a;
    string b;
    string c;
    while(t--)
	{
        cin >> a >> b >> c;
        cout << LCS_three_fast(a,b,c);

        cout << endl;
	}
}
