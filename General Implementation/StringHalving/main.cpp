#include<bits/stdc++.h>
using namespace std;

char string_halving(string s)
{
    unordered_set<char> st;
    char ans = 'z';
    for(auto itr=s.begin(); itr!=s.end(); itr++)
    {
        if(st.find(*itr) != st.end() )
            break;
        else
        {
            ans = min(ans,*itr);
            st.insert(*itr);
        }
    }
    return ans;

}

int main()
{
    string s ;
    while(1)
    {
        cin >> s;
        cout << string_halving(s) << endl ;
    }
    return 0;
}
