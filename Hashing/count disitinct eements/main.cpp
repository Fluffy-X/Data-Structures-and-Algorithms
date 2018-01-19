#include <bits/stdc++.h>
using namespace std;

int main()
{
    multimap<int,int> m;
    m.insert(make_pair(1,1));
    m.insert(make_pair(1,2));
    m.insert(make_pair(1,1));
    m.insert(make_pair(1,3));
    for(auto itr=m.begin(); itr!=m.end(); itr++)
    {
        cout << itr->first << " " << itr->second <<endl;
    }


    return 0;
}
