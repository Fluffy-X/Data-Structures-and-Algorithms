#include <bits/stdc++.h>
using namespace std;

int lcsc(vector<int>& a)
{
    multiset<int, greater<int> > s;
    vector<int> ans(a.size());
    s.insert(a[0]);
    ans.push_back(a[0]);
    for(int i=1; i<a.size(); i++)
    {
        if(ans[i-1]<0)
        {
            ans[i]=a[i];
            s.insert(ans[i]);
        }
        else
        {
            ans[i]=a[i]+ans[i-1];
            s.insert(ans[i]);
        }
    }
    return *(s.begin());
}

int main()
{
    vector<int> v={-2, -3, 4, -1, -2, 1, 5, -3};
    cout << lcsc(v);
    return 0;
}
