#include <bits/stdc++.h>
using namespace std;


int minimum_jumps(std::vector<int> v)
{
	std::vector<int> dist(v.size());
	dist[0] = 0;
	for (int i = 1; i < v.size(); ++i)
	{
		int m=INT_MAX;
		for (int j = i-1; j >= 0; --j)
		{
			if(v[j] >= i-j && dist[j]!=-1)
				m = min(m,dist[j]);
		}
		if(m==INT_MAX)
			dist[i] = -1;
		else
			dist[i] = m+1;
	}
	return dist[v.size()-1];
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
		cout << minimum_jumps(v) << endl;
	}
    return 0;
}
