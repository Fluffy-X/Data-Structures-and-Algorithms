// Length of the longest substring without repeating characters
#include <bits/stdc++.h>
using namespace std;

int LSRC(string a)
{
	pair<char,int> p;
	int start = 0;
	int run = 0;
	int ans = INT_MIN;
	int index;
	std::unordered_map<char, int> m;
	for (int i = 0; i < a.size(); ++i)
	{
		if(m.find(a[i]) == m.end())
		{
			p.first = a[i];
			p.second = i;
			m.insert(p);
			run++;
			ans = max(ans,run);
		}
		else
		{
			auto itr = m.find(a[i]);
			if(start > itr->second)
			{
				m.erase(itr);
				p.first = a[i];
				p.second = i;
				m.insert(p);
				run++;
				ans = max(ans, run);
			}
			else
			{
				index = itr->second;
				run = i - index;
				start = index + 1;
				m.erase(itr);
				p.first = a[i];
				p.second = i;
				m.insert(p);
			}
		}
	}
	return ans;
}

int main()
{
    int t;
    cin >> t;
    string a;
    while(t--)
	{
        cin >> a;
        cout << LSRC(a) << endl;
	}
}
