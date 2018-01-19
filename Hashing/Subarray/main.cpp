#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a={15, -2, 2, -8, 1, 7, 10, 23};
    vector<int> v={15, -2, 2, -8, 1, 7, 10, 23};
    unordered_multimap<int,int> m;
    unordered_multimap<int,int>::iterator itr;
    m.insert(make_pair(v[0],0));
    int i=1,c=0;
    pair<int,int> ans;
    for(; i<v.size(); i++)
    {
        v[i]+=v[i-1];
        //m.insert(v[i]);
    }

    for(i=0 ; i<v.size(); i++)
    {
        itr = m.find(v[i]);
        if(m.find(v[i])!=m.end() && i-(*itr).second > c)
        {
            ans = make_pair((*itr).second, i);
            c = i-(*itr).second;
        }
        m.insert(make_pair(a[i],i));
    }
    cout << c;
    return 0;
}
