#include <bits/stdc++.h>
using namespace std;
//9 5
//2 3 4 2 3 6 8 4 5

void counting_sort(std::vector<int>& v)
{
	vector<int> arr(1000,0); // al elements less than equalto 999
	for (int i = 0; i < v.size(); ++i)
	{
		arr[v[i]]++;
	}
	for (int i = 0; i < 1000; ++i)
	{
		if(arr[i] != 0)
        {
            while(arr[i] != 0)
            {
                cout << i << " ";
                arr[i]--;
            }
        }
	}
}


int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	counting_sort(v);

}
