#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

void swap(int& a, int& b)
{
    int temp ;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    map <int, int> m;
    vector<pair<int,int> > v={{11, 20}, {30, 40}, {5, 10}, {40, 30}, {10, 5}};
    int i=0;

    for(i=0; i<v.size(); i++)
    {
        if(v[i].first > v[i].second)
            swap(v[i].first,v[i].second);
    }

    for(i=0; i<v.size(); i++)
    {
        if(m.find(v[i].first)!=m.end())
        {
            cout << v[i].first << " " << v[i].second << endl;
        }
        else
            m.insert(v[i]);
    }
    return 0;
}
