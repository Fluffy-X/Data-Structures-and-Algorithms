// Smallest window in a string containing all the characters of another string
#include <bits/stdc++.h>
using namespace std;

int bear(string s, string pat)
{
    if(pat.size()==0)
        return 0;
	vector<int> pattern(256,0);
	bool valid=true;
	std::vector<int> temp(256,0);
	int start=0,stop=0,l=INT_MAX,j=0,c=0,count=0;
	for (int i = 0; i < pat.size(); ++i)
	{
		pattern[(int)pat[i]]++;
		count++;
	}
	for (int i = 0; i < s.size(); ++i)
	{
		if(pattern[(int)s[i]] != 0)
		{
			if(pattern[(int)s[i]] > temp[(int)s[i]])
				c++;
			temp[(int)s[i]]++;
			if(c == count)
			{
				valid = false;
				if(l > i-j+1)
                {
                    l = i-j+1;
                    start = j;stop = i;
                }
				//cout << j << " " << i << endl;
				while(pattern[(int)s[j]] == 0 || pattern[(int)s[j]] < temp[(int)s[j]])
				{
					if(pattern[(int)s[j]] == 0)
						j++;
					else if(pattern[(int)s[j]] < temp[(int)s[j]])
					{
						temp[(int)s[j]]--;
						j++;
					}
					if(l > i-j+1)
					{
						l = i-j+1;
						start = j;stop = i;
					}
				}
			}
		}
	}
	/*if(valid)
    {
        string ans = "-1";
        return ans;
    }*/
	/*string ans;
	for (int i = start; i <= stop; ++i)
	{
		ans.push_back((int)s[i]);
	}
	return ans;*/
	return stop-start+1;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(4,0); // A T G C
    for (int i = 0; i < s.size(); ++i)
    {
    	if(s[i]=='A')
    		v[0]++;
    	else if(s[i]=='T')
    		v[1]++;
    	else if(s[i]=='G')
    		v[2]++;
    	else if(s[i]=='C')
    		v[3]++;
    }
    for (int i = 0; i < 4; ++i)
    {
    	if(v[i] > n/4)
    		v[i] = v[i]-n/4;
    	else
    		v[i] = 0;
    }
    string pat;
    for (int i = 0; i < 4; ++i)
    {
    	if(v[i] != 0)
    	{
    		while(v[i] != 0)
    		{
    			if(i==0)
	    			pat.push_back('A');
				else if(i==1)
					pat.push_back('T');
				else if(i==2)
					pat.push_back('G');
				else if(i==3)
					pat.push_back('C');
                v[i]--;
    		}
    	}
    }
    cout << bear(s,pat);
    return 0;
}
