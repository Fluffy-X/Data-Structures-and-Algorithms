// Square root decomposition
#include <bits/stdc++.h>
using namespace std;

vector<int> form_sqrt(vector<int> v)
{
	int n = sqrt(v.size());
	int b = v.size() - n*n;
	if(b != 0 && b%n != 0)
        b = (b/n)+1;
    else if(b != 0 && b%n == 0)
        b = (b/n);

	std::vector<int> decomp(b+n);
	for (int i = 0; i < v.size(); ++i)
	{
		decomp[i/n] += v[i];
	}
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return decomp;
	/*
	cout << endl;
	for (int i = 0; i < decomp.size(); ++i)
	{
		cout << decomp[i] << " " ;
	}*/
}

int range_sum(vector<int> decomp, vector<int> v, int a, int b)
{
    int a1 = a/sqrt(v.size());
    int b1 = a/sqrt(v.size());
    int sum = 0;
    for(int i=a1; i<b1; i++)
        sum += decomp[i];
    for(int i=a1*4; i<a ; i++)
        sum -= v[i];
    for(int i=a1*4; i<=b; i++)
        sum += v[i];
    return sum;
}

int main()
{
    int m;
    cin >> m;
	std::vector<int> v(m);
	for (int i = 0; i < v.size(); ++i)
	{
		v[i] = i;
	}
	vector<int> decomp = form_sqrt(v);
	int a,b;
	cin >> a >> b;
	cout << range_sum(decomp, v, a, b);
}
