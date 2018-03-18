#include <bits/stdc++.h>

using namespace std;

int commonChild(string s1, string s2)
{
    vector<vector<int> > v(s1.size()+1,vector<int>(s2.size()+1));
    for(int i=1; i<=s1.size(); i++)
    {
        for(int j=1; j<=s2.size(); j++)
        {
            if(s1[i-1] == s2[j-1])
                v[i][j] = 1 + v[i-1][j-1];
            else
                v[i][j] = max(v[i-1][j],v[i][j-1]);
        }
    }
    for(int i=0; i<=s1.size(); i++)
    {
        for(int j=0; j<=s2.size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return v[s1.size()][s2.size()];
}

int main() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int result = commonChild(s1, s2);
    cout << result << endl;
    return 0;
}
