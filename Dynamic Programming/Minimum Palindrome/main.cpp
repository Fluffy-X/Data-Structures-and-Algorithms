#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > memo(50,vector<int>(50,-1));

int form_palindrome(string s, int i, int j)
{
	if(j==i)
		return 0;
	if(j-i==1)
	{
		if(s[i]==s[j])
			return 0;
		else
			return 1;
	}
	if(s[i] == s[j]){
		if(memo[i+1][j-1] != -1)
			return memo[i+1][j-1];
		else
			memo[i+1][j-1] = form_palindrome(s, i+1, j-1);
		return memo[i+1][j-1];
	}
	else{
		int a,b;
		if(memo[i+1][j] != -1)
			a = memo[i+1][j];
		else
			memo[i+1][j] = form_palindrome(s, i+1, j);
		a = memo[i+1][j];

		if(memo[i][j-1] != -1)
			a = memo[i][j-1];
		else
			memo[i][j-1] = form_palindrome(s, i, j-1);
		b = memo[i][j-1];

		return (1 + min(a,b));
	}
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		for(int i=0; i<memo.size(); i++)
        {
            fill(memo[i].begin(), memo[i].end(),0);
        }
		string s;
		cin >> s;
		cout << form_palindrome(s,0,s.size()-1) << endl;
	}
    return 0;
}
