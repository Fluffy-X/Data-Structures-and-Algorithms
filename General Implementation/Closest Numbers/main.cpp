#include <bits/stdc++.h>

using namespace std;

vector <int> closestNumbers(vector <int> arr) {
    // Complete this function
    sort(arr.begin(), arr.end());
    int ans=INT_MAX;
    for(int i=0; i<arr.size()-1; i++)
    {
        ans = min(ans,abs(arr[i]-arr[i+1]));
    }
    vector<int> f;
    for(int i=0; i<arr.size()-1; i++)
    {
        if(abs(arr[i]-arr[i+1])==ans)
        {
            f.push_back(arr[i]);
            f.push_back(arr[i+1]);
        }
    }
    return f;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    vector <int> result = closestNumbers(arr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
