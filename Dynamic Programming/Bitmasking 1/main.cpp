#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > a= {
                        {2,3,4,5},
                        {2,3,5},
                        {1,2,3},
                        {1,2},
                        {1,2,3,4,5,6,20},
                        {1,3,4,5}
                        };


// given a set, count how many subsets have sum of elements greater than or equal to a given value.
void subsets(map<int,int> &m, int val)
{
    int c=0;
    for(int i=0; i<((1 << m.size())); i++)
    {
        int sum = 0;
        for(int k=0; k<m.size(); k++)
        {
            if( (i&(1<<k)) !=0)
                sum += m[k+1];
        }
        //cout << sum << endl;
        if(sum >= val)
            c++;
    }
    cout << c;
}

int Ways(int start, unordered_set<int> &s)
{
    int temp=0;
    if(start==a.size())
    {
        return 1;
    }
    for(auto itr=a[start].begin(); itr!=a[start].end(); itr++)
    {
        if(s.find(*itr) != s.end())
            continue;
        s.insert(*itr);
        temp += Ways(start+1,s);
        s.erase(*itr);
    }
    return temp;
}

int main()
{
    unordered_set<int> s;
    map<int,int> m ={ {1,1},{2,2},{3,3},{4,4},{5,5},{6,6} };
    cout << Ways(0,s);
    //cout << (1 << m.size()) << endl;
    //subsets(m,14);
    return 0;
}
