// Count Inversions
#include <bits/stdc++.h>
using namespace std;
vector<int> b(10000,0);
vector<int> a(10000,0);

void update(int index, int val)
{
	for(; index <= b.size();)
	{
		b[index] = b[index] + val;
		index = index + ((index)&(-index));
	}
}
int sum_query(int n)
{
	int sum=0;
	for(; n!= 0 ;)
	{
		sum += b[n];
		n = n - ((n)&(-n));
	}
	return sum;
}


int count_inversions(vector<int> v)
{
	int num=0;
	for (int i = 1; i < v.size(); i++)
	{
		num += sum_query(v[i]-1);
		update(v[i],1);
	}
	return num;
}
int main()
{
	int n;
	cin >> n;
	std::vector<int> v(n+1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	reverse(v.begin()+1, v.end());
	cout << count_inversions(v);
	return 0;
}
