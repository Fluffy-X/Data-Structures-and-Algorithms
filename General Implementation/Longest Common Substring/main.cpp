//Auxiliayy Space : O(1)
//Time Complexity : O(mn)
#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b)
{
    int ans=0;
    for(int i=a.size()-1; i>=0; i--)
    {
        for(int j=b.size()-1; j>=0; j--)
        {
            if(a[i]==b[j])
            {
                int count =0;
                while(a[i]==b[j])
                {
                    count++;
                    if(i==0 || j==0)
                        break;
                    i--;j--;
                }
                ans = max(ans,count);
            }
        }
    }
    return ans;
}

int main()
{
    string a= "OldSite:GeeksforGeeks.org";
    string b= "NewSite:GeeksQuiz.com";
    cout << lcs(a,b);
    return 0;
}
