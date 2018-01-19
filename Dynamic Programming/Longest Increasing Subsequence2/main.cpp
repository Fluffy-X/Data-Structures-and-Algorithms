#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i;
    multimap<int,int, greater<int> > m;
    multimap<int,int, greater<int> >::iterator itr;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> a[arr_i];
    }
    m.insert(make_pair(1,a[0]));
    for(i=1; i<n; i++)
    {
        itr=m.begin();
        while(1)
        {
            if((*itr).second < a[i])
            {
                m.insert(make_pair((*itr).first+1,a[i]));
                break;
            }
            else
            {
                itr++;
                if(itr==m.end())
                {
                    m.insert(make_pair(1,a[i]));
                    break;
                }
            }
        }
    }
    itr = m.begin();
    cout << (*itr).first ;


    return 0;
}
