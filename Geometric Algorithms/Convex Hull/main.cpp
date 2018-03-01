#include <bits/stdc++.h>
using namespace std;

struct node{
    int a;
    int b;

};
int main()
{
    vector<node> v;
    node temp;
    temp.a=1;
    temp.b=2;
    for(int i=1; i<10; i++)
    {
        temp.a = i;
        temp.b = 100-i;
        v.push_back(temp);
    }
    for(auto i : v)
        cout << i.a << " " <<  i.b << endl;
    sort(v.begin( ),v.end( ), [ ](const node& lhs, const node& rhs)
    {
      return lhs.b < rhs.b;
    });
    return 0;
}
