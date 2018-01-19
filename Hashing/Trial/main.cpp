#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v={92, 75, 65, 48, 45, 35};
    int k = 10;
    unordered_multiset<int> s;
    int i = 0;
    for(auto itr=v.begin(); itr!=v.end(); itr++, i++)
    {
        v[i] = v[i]%k;
        s.insert(v[i]);
    }
    for(auto itr=s.begin(); itr!=s.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
    auto itr=s.begin();
    s.erase(itr);
    itr=s.begin();
    s.erase(itr);
    for(auto itr=s.begin(); itr!=s.end(); itr++)
    {
        cout << *itr << " ";
    }
    return 0;
}
