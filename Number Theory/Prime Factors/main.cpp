#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i=0; i<t; i++)
	{
	    long long n;
	    cin >> n;
	    set<long long> ans;
	    for(long long j=2; j<=sqrt(n); j++)
	    {
	        if(n%j==0)
	        {
	            while(n%j==0)
	            {
	                ans.insert(j);
	                n /= j;
	            }
	        }
	    }
	    if(n!=1)
            ans.insert(n);
	    for(auto itr=ans.begin(); itr!=ans.end(); itr++)
	    {
	        cout << *itr << " ";
	    }
	    cout << endl;
	}
}

