#include <bits/stdc++.h>
using namespace std;
int minimum_cut(string s, vector<int> *memo);
void all_palindromic_substring(string s)
{
    vector<int> memo[s.size()];
    for(int i=0; i<s.size(); i++)
        memo[i].push_back(i);
    for(int i=1; i<s.size(); i++)
    {
        for(auto itr=memo[i-1].begin(); itr!=memo[i-1].end(); itr++)
        {
            if(*itr-1 >= 0)
            {
                if(s[i] == s[*itr-1])
                    memo[i].push_back(*itr-1);
            }
        }
        if(s[i] == s[i-1])
            memo[i].push_back(i-1);
    }
    /*for(int i=0; i<s.size(); i++)
    {
        for(auto itr=memo[i].begin(); itr!=memo[i].end(); itr++)
            cout << *itr << " ... " << i << endl;
        cout << endl ;
    }*/
    cout << minimum_cut(s,memo);
}
int minimum_cut(string s, vector<int> *memo)
{
    vector<int> cut(s.size(),0);
    for(int i=1; i<s.size(); i++)
    {
        int a = INT_MAX;
        a = min(a,1+cut[i-1]);
        for(auto itr=memo[i].begin(); itr!=memo[i].end(); itr++)
            a = min(a,1+cut[*itr-1]);
        cut[i] = a;
    }
    return cut[s.size()-1];
}
int main()
{
    string s = "aaabba";
    all_palindromic_substring(s);
    return 0;
}
