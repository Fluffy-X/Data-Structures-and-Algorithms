#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v={9, 7, 5, 3};
    int k = 6;
    unordered_multiset<int> s;
    int i = 0;
    for(auto itr=v.begin(); itr!=v.end(); itr++, i++)
    {
        v[i] = v[i]%k;
        s.insert(v[i]);
    }
    for(auto itr=s.begin(); itr!=s.end();itr=s.begin())
    {
        if(s.find(k-(*s.begin()))==s.end())
        {
            cout << "False";
            return 0;
        }
        s.erase(itr);
        s.erase(s.find(k-(*itr)));
    }
    cout << "True" ;
    return 0;
}
