#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_multimap<int,pair<int,int> > m;
    unordered_multimap<int,pair<int,int> >::iterator itr;
    vector<int> a={3, 4, 7, 1, 2, 9, 8};
    int j=0,count=0;
    for(int i=0; i<a.size(); i++)
    {
        for(j=i+1; j<a.size(); j++)
        {
            if(!m.empty() && m.find(a[i]+a[j])!=m.end())
            {
                itr=m.find(a[i]+a[j]);
                cout << ((*itr).second).first << " " << ((*itr).second).second << endl;
                cout << a[i] << " " << a[j] << endl << endl;
                count++;
            }
            m.insert(make_pair(a[i]+a[j],make_pair(a[i],a[j])));
        }
    }
    if(!count)
        cout << "No pairs Found" ;
    return 0;
}
