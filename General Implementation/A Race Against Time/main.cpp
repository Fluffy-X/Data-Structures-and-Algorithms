#include <bits/stdc++.h>
using namespace std;

long DP(long current_height, vector <long> heights, vector <long> prices, long current_sum)
{


}

long raceAgainstTime(long n, long mason_height, vector <long> heights, vector <long> prices)
{
    long mc=0;
    long h=mason_height;
    long index=0;
    for(int i=1; i<n; i++)
    {
        if(h < heights[i-1] || prices[i-1] + abs(h-heights[i-1]) < 0 )
        {
            mc += prices[i-1] + abs(h-heights[i-1]) + 1;
            h = heights[i-1];
            cout << " Boo " << i << " : " << mc << endl;
        }
        else
            mc += 1;
    }
    return mc+1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
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
