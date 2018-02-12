#include <bits/stdc++.h>
using namespace std;

long raceAgainstTime(long n, long mason_height, vector <long> heights, vector <long> prices) {
    // Complete this function
    vector<long> mp(n+1,LONG_MAX);
    mp[0] = 0;
    for(long j=1; j<n+1; j++)
    {
        if(mason_height < heights[j-1])
        {
            if(j==n)
                mp[j] = min( mp[j],mp[0]+j-0 );
            else
                mp[j] = min( mp[j],mp[0] + prices[j-1]+j+abs(heights[j-1] - mason_height) );
            break;
        }
        if(j==n)
            mp[j] = min( mp[j],mp[0]+j );
        else
            mp[j] = min( mp[j],mp[0] + prices[j-1]+j+abs(heights[j-1] - mason_height) );
    }
    for(long i=1; i<n; i++)
    {
        for(long j=i+1; j<n+1; j++)
        {
            if(heights[i-1] < heights[j-1])
            {
                if(j==n)
                    mp[j] = min( mp[j],mp[i]+j-i );
                else
                    mp[j] = min( mp[j],mp[i] + prices[j-1]+j-i+abs(heights[j-1] - heights[i-1]) );
                break;
            }
            if(j==n)
                mp[j] = min( mp[j],mp[i]+j-i );
            else if( prices[j-1]+j-i+abs(heights[j-1] - heights[i-1]) > 0)
                continue;
            else
                mp[j] = min( mp[j],mp[i] + prices[j-1]+j-i+abs(heights[j-1] - heights[i-1]) );
        }
    }
    return mp[n];
}

int main() {
    long n;
    cin >> n;
    long mason_height;
    cin >> mason_height;
    vector<long> heights(n-1);
    for(long heights_i = 0; heights_i < n-1; heights_i++){
       cin >> heights[heights_i];
    }
    vector<long> prices(n-1);
    for(long prices_i = 0; prices_i < n-1; prices_i++){
       cin >> prices[prices_i];
    }
    long result = raceAgainstTime(n, mason_height, heights, prices);
    cout << result << endl;
    return 0;
}
