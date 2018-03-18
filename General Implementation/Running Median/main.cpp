#include <bits/stdc++.h>

using namespace std;

std::vector<float> running_median(std::vector<int>& v)
{
	priority_queue<int> max;
	std::vector<float> ans(2);
	ans[0] = v[0];
	ans[1] = (v[0]+v[1])/2.0;
	priority_queue<int, vector<int>, greater<int> > min;
	if(v[0] > v[1])
	{
		min.push(v[0]);
		max.push(v[1]);
	}
	else
	{
		min.push(v[1]);
		max.push(v[0]);
	}
	for (int i = 2; i < v.size(); ++i)
	{
		if(max.size() == min.size())
		{
			if (min.top() < v[i])
			{
				min.push(v[i]);
                cout << " foo " << min.top() << "foo" << endl;
				ans.push_back(min.top());
			}
			else
			{
				max.push(v[i]);
				cout << " foo " << max.top() << "foo" << endl;
				ans.push_back(max.top());
			}
		}
		else if(min.size() > max.size())
		{
			if(min.top() < v[i])
			{
				min.push(v[i]);
				int temp = min.top();
				min.pop();
				max.push(temp);
				cout << " foo " << (max.top() + min.top())/2.0 << "foo" << endl;
				ans.push_back((max.top() + min.top())/2.0);
			}
			else
			{
				max.push(v[i]);
				cout << " foo " << (max.top() + min.top())/2.0 << "foo" << endl;
				ans.push_back((max.top() + min.top())/2.0);
			}
		}
		else
		{
			if(min.top() < v[i])
			{
				min.push(v[i]);
				cout << " foo " << (max.top() + min.top())/2.0 << "foo" << endl;
				ans.push_back((max.top() + min.top())/2.0);
			}
			else
			{
				max.push(v[i]);
				int temp = max.top();
				max.pop();
				min.push(temp);
				cout << " foo " << (max.top() + min.top())/2.0 << "foo" << endl;
				ans.push_back((max.top() + min.top())/2.0);
			}
		}
	}
    return ans;
}

int main() {
    int n;
    cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
    	cin >> v[i];
    }
    std::vector<float> ans = running_median(v);
    for (int i = 0; i < ans.size(); ++i)
    {
    	cout << ans[i] << endl;
    }
}
