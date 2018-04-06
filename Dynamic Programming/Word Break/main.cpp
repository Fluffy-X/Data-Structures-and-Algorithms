#include <bits/stdc++.h>
using namespace std;

bool wordBreak(vector<string>& dict, string s)
{
	int n = s.size()-1;
	vector<int> memo(s.size(),0);
	for (int i = n; i >= 0; i--)
	{
		for (int j = 0; j < dict.size(); ++j)
		{
			if (n-i+1 < dict[j].size())
			{
			    if(i==0)
                    cout << "goo";
				continue;
			}
			if(s.substr(i,dict[j].size()) == dict[j])
			{
				if(i+dict[j].size() > n)
					memo[i] = 1;
				else if(memo[dict[j].size()+i] == 1)
				{
						memo[i]=1;
				}
			}
		}
	}
	for(int i=0; i<memo.size(); i++)
        cout << memo[i] << " ";
    cout << endl;
	return memo[0];
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<string> dict;
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;
			dict.push_back(s);
		}
		string s;
		cin >> s;
		cout << wordBreak(dict,s) << endl;
	}
}
