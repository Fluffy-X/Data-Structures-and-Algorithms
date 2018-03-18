#include <bits/stdc++.h>

using namespace std;

string isValid(string s)
{
    // Complete this function
    string y = "YES";
    string n = "NO";
    std::vector<int> v(26,0);
    unordered_map<int,int> us;
    int m = INT_MAX;
    for(int i=0; i < s.size(); i++)
    {
    	v[(s[i]-97)]++;
    }
    /*for(int i=0; i < v.size(); i++)
    {
    	cout << (char)(97+i) << " " << v[i] << endl;
    }*/
    for(int i=0; i<v.size(); i++)
    {
        if(v[i] != 0)
        {
            if(us.find(i) != us.end())
            {
                auto itr = us.find(i);
                itr->second++;
            }
            us.insert(make_pair(i,1));
        }
    }
    cout << us.size() << endl;
    if(us.size() > 2 )
        return n;
    else
        return y;
}

int main() {
    string s;
    cin >> s;
    string result = isValid(s);
    cout << result << endl;
    return 0;
}
