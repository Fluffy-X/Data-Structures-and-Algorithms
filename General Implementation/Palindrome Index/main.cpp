#include <bits/stdc++.h>
using namespace std;

int index(int i, std::vector<int>& x)
{
	for (int j = 1; j <= x.size(); ++j)
	{
		if(x[j] != 0)
			return j;
	}
}

int hackerlandRadioTransmitters(vector <int>& x, int k) {
    // Complete this function
    int i=index(1,x);
    int count = 0;
    int j = i+k;
    for (; j != i; --j)
    {
    	if(j > x.size())
    		continue;
    	if(x[j] >= 1)
    	{
    	    cout << j << endl;
    		count++;
    		i = index(j+k+1,x);
    		if(i == x.size()+1)
    			return count;
    		if(i+k >= x.size())
    			return count+1;
    	}
    	j = i+k;
    }
    return count;

}

int main() {
    int n;
    int k;
    cin >> n >> k;
    int temp;
    std::vector<int> x(100001,0);
    for(int x_i = 0; x_i < n; x_i++)
    {
       cin >> temp;
       x[temp]++;
    }
    int result = hackerlandRadioTransmitters(x, k);
    cout << result << endl;
    return 0;
}
