#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_multimap<char,char> m;
map<char,int> ans;

int recursion(char start)
{
    if(m.find(start)==m.end())
    {
        cout << start << " " << ans[start] << endl;
        return 0;
    }
    auto it = m.find(start);
    for(;it!=m.end();)
    {
        it = m.find(start);
        m.erase(it);
        ans[start] += recursion((*it).second)+1;
        it = m.find(start);
    }
    cout << start << " " << ans[start] << endl;
    return ans[start];
}

int main()
{
    char start;
    m.insert(make_pair('C','A'));
    m.insert(make_pair('C','B'));
    m.insert(make_pair('F','C'));
    m.insert(make_pair('E','D'));
    m.insert(make_pair('F','E'));
    m.insert(make_pair('F','F'));

    ans.insert(make_pair('A',0));
    ans.insert(make_pair('B',0));
    ans.insert(make_pair('C',0));
    ans.insert(make_pair('D',0));
    ans.insert(make_pair('E',0));
    ans.insert(make_pair('F',0));
    for(auto itr=m.begin(); itr!=m.end(); itr++)
    {
        if((*itr).first==(*itr).second)
        {
            start = (*itr).first;
            m.erase(itr);
            break;
        }
    }
    recursion(start);
    /*for(auto itr=ans.begin(); itr!=ans.end(); itr++)
    {
        cout << (*itr).first << " " << (*itr).second << endl;
    }*/
    return 0;
}
