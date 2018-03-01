#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <bits/stdc++.h>
using namespace std;

void disjoint(vector<int>& s1, vector<int>& s2)
{
    unordered_set<int> sm;
    auto it=s1.begin();
    for(it=s1.begin(); it!=s1.end(); it++)
        sm.insert(*it);
    for(it=s2.begin(); it!=s2.end(); it++)
    {
        if(sm.find(*it)!=sm.end())
            {
                cout << "Not Disjoint ";
                return;
            }
    }
    cout << "Disjoint" ;
}
void pair_product(vector<float>& v, float x)
{
    unordered_set<float> s;
    for(auto it=v.begin(); it!=v.end(); it++)
        {
            if(*it==0)
            {
                cout << "Yes" ;
                return;
            }
            s.insert(*it);
        }
    for(auto it=v.begin(); it!=v.end(); it++)
    {
        s.erase(*it);
        if(s.find(x/(*it))!=s.end())
        {
            cout << "Yes";
            return;
        }
    }
    cout << "No" ;
}
vector<int> reduced_array_form(vector<int>& v)
{
    vector<int> answer;
    vector<int> original = v;
    unordered_map<int, int> m;
    unordered_map<int, int>::iterator itr;
    sort(v.begin(),v.end());
    int i=0;
    for(auto it=v.begin(); it!=v.end(); it++, i++)
        m.insert(make_pair(*it,i));
    for(auto it=original.begin(); it!=original.end(); it++)
    {
        itr = m.find(*it);
        answer.push_back(itr->second);
    }
    return answer;
}
void print_vector(vector<int> v)
{
    for(auto it=v.begin(); it!=v.end(); it++)
        cout << *it << " ";

}
int main()
{
    vector<int> s1={12, 34, 11, 9, 3};
    vector<int> s2={2, 1, 4, 5};
    vector<float> v1={0, 20, 9, 40};
    vector<int> v={10, 20, 15, 12, 11, 50};
    print_vector(reduced_array_form(v));
    return 0;
}
