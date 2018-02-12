#include <bits/stdc++.h>
using namespace std;

void driver(vector<long long> &v)
{
    vector<long long> m;
    long n = v.size();
    long start=1;
    long stop=1;
    for(long long i=0; i<v.size()-1; i++)
        m.push_back(v[i]-v[i+1]);
    long long c=0;
    for(long i=0; i<v.size(); i++)
    {
        if(v[i] > v[i+1])
            c++;
    }
    if(c==v.size()-1)
    {
        cout << "yes" << endl << 1 << " " << v.size();
        return;
    }
    for(long long i=0; i<m.size(); i++)
    {
        if(m[i] > 0)
        {
            start = i;
            for(long long j=i+1; j<m.size(); j++, i++)
            {
                if(m[j] < 0)
                {
                    stop = j;
                    for(long long k=j+1; k<m.size(); k++,j++,i++)
                    {
                        if(m[k] > 0)
                        {
                            cout << "no";
                            return ;
                        }
                    }
                }
            }
        }
    }
    vector<long long> ans;
    ans = v;
    reverse(ans.begin()+start,ans.begin()+stop+1);
    sort(v.begin(),v.end());
    for(long i=0; i<ans.size(); i++)
    {
        if(v[i] != ans[i])
        {
            cout << "no";
            return;
        }

    }
    cout << "yes" << endl;
    cout << start+1 << " " << stop+1;
}
int main()
{
    long n;
    cin >> n;
    vector<long long> v(n);
    for(long long i=0; i<n; i++)
    {
        cin >> v[i];
    }
    driver(v);
    return 0;
}
