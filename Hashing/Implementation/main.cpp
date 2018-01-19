#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_multiset<int> sm;
    vector<int> v={10, 5, 3, 10, 10, 4, 1, 3};
    vector<int> without_duplicate;
    auto it = v.begin();
    for(it=v.begin(); it!=v.end(); it++)
    {
        if(sm.find(*it)==sm.end())
            without_duplicate.push_back(*it);
        sm.insert(*it);
    }
    it = without_duplicate.begin();
    auto temp = sm.begin();
    for(it=without_duplicate.begin(); it!=without_duplicate.end(); it++)
    {
        while(sm.find(*it)!=sm.end())
        {
            cout << *it << " ";
            temp = sm.find(*itr);
            sm.erase(temp);
        }
    }
    return 0;
}
