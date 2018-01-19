#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string,string> m;
    m.insert(make_pair("Bangalore","Chennai"));
    m.insert(make_pair("Delhi","Bombay"));
    m.insert(make_pair("Chennai","Goa"));
    m.insert(make_pair("Goa","Delhi"));
    unordered_set<string> s1;
    unordered_set<string> s2;
    stack<string> ans;
    string destination;
    s1.insert("Chennai");s1.insert("Bombay");s1.insert("Goa");s1.insert("Delhi");
    s2.insert("Bangalore");s2.insert("Delhi");s2.insert("Chennai");s2.insert("Goa");
    for(auto itr=s2.begin(); itr!=s2.end(); itr++)
    {
        if(s1.find(*itr)==s1.end())
        {
            destination=*itr;
            break;
        }
    }
    auto it = m.begin();
    ans.push(destination);
    while(m.find(destination)!=m.end())
    {
        it = m.find(destination);
        destination = (*it).second;
        ans.push(destination);
    }
    while(!ans.empty())
    {
        cout << ans.top() ;
        ans.pop();
        if(!ans.empty())
        cout << "->" << ans.top() << ", ";
    }
    return 0;
}
