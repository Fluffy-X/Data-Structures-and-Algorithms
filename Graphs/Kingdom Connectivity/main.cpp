#include <bits/stdc++.h>

using namespace std;

int equal(vector <int> &arr) {
    // Complete this function
    int sum = arr[arr.size()-1] - arr[0];
    vector<int> a={0,1,2,5};
    vector<vector<int> > memo(sum+1,vector<int>(4,0));
    memo[0][0]=memo[0][1]=memo[0][2]=memo[0][3]=1;
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(j-a[i] > 0)
                memo[j][i] = memo[j][i-1] + memo[j-a[i]][i];
            else
                memo[j][i] = memo[j][i-1];
        }
    }
    int ans=INT_MAX;
    /*for(int i=1; i<arr.size(); i++)
    {
        ans = min(ans,memo[arr[arr[i]-arr[0]]][3]);
    }*/
    for(int i=0; i<=3; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            cout << memo[j][i] << " ";
        }
        cout << endl;
    }
    return ans;

}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        sort(arr.begin(),arr.end());
        int result = equal(arr);
        cout << result << endl;
    }
    return 0;
}
