#include <bits/stdc++.h>
using namespace std;

int min_jumps(vector<int>& v)
{
    multimap<int,int> m;
    m.insert(make_pair(0,v[0]));
    auto itr = m.begin();
    for(int i=1; i<v.size(); i++)
    {
        if(m.empty())
            return -1;
        itr = m.begin();
        if(itr->second >= i)
        {
            if(v[i]+i >= v.size()-1)
                return itr->first+2;
            m.insert(make_pair(itr->first+1,v[i]+i));
        }
        else
        {
            m.erase(itr);
            i--;
        }
    }
}

int main()
{
    vector<int> v = {1,3,5,8,9,2,6,7,0,0,0,0,0,0,0,0};
    cout << min_jumps(v);
    return 0;
}
