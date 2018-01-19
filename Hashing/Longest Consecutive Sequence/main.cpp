#include <bits/stdc++.h>
using namespace std;
unordered_set<int> s;

int rec_minus(int start)
{

    if(s.find(start-1)==s.end())
        return 1;
    else
    {
        s.erase(start);
        return rec_minus(start-1)+1;
    }
}
int rec_plus(int start)
{

    if(s.find(start+1)==s.end())
        return 1;
    else
    {
        s.erase(start);
        return rec_plus(start+1)+1;
    }
}
int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    vector<int> v={36, 41, 40, 35, 44, 33, 34, 45, 43, 32, 42};
    sort(v.begin(),v.end());
    int ansplus=1,ansminus=1,ans=1;
    unordered_set<int>::iterator itr;
    for(int i=0; i<v.size(); i++)
        s.insert(v[i]);
    for(auto itr=s.begin(); itr!=s.end();itr++)
    {
        cout << *itr << " ";
    }
    while(!s.empty())
    {
        itr=s.begin();
        if(s.find(*itr+1)==s.end() && s.find(*itr-1)==s.end())
        {
            s.erase(*itr);
            continue;
        }
        if(s.find(*itr+1)!=s.end())
            ansplus=rec_plus(*itr+1)+1;
        if(s.find(*itr-1)!=s.end())
            ansminus=rec_minus(*itr-1)+1;
        ans=max(ans,ansplus+ansminus-1);
        s.erase(*itr);
    ansplus=1;ansminus=1;
    }
    cout << endl << ans ;
    return 0;
}
