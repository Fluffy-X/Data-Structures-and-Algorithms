#include <bits/stdc++.h>
using namespace std;

bool subsetSum(std::vector<int> v)
{
	int sum=0;
	for (int i = 0; i < v.size(); ++i)
	{
		sum += v[i];
	}
	if(sum % 2 == 1)
		return false;
	else
	{
		sum /= 2;
		vector<vector<int> > memo(v.size(),vector<int>(sum+1));
		for (int i = 0; i < v.size(); ++i)
		{
			memo[i][0] = 1;
		}
		for (int i = 0; i < sum+1; ++i)
		{
			if(v[0] == i)
                memo[0][i] = 1;
		}
		for (int i = 1; i < v.size(); ++i)
		{
			for (int j = 1; j < sum+1; ++j)
			{
			    if(j-v[i] < 0)
                    memo[i][j] = memo[i-1][j];
                else
                    memo[i][j] = memo[i-1][j] || memo[i-1][j-v[i]];
			}
		}
		return memo[v.size()-1][sum];

	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >>n;
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		if(subsetSum(v))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
    return 0;
}
