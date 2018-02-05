#include <bits/stdc++.h>
struct Node
{
    int first;
    int second;

};
using namespace std;

int cost(vector <int> b) {
    Node up,down;
    up.second=0;
    down.second=0;
    up.first=b[0];
    down.first=1;
    int s1=0,s2=0;
    for(int i=1; i<b.size(); i++)
    {
        s1=up.second;
        s2=down.second;
        if(b[i] <= b[i-1])
        {
            up.first=b[i];
            up.second=s2+b[i]-1;
            down.first=1;
            down.second=s1+b[i-1]-1;
        }
        else
        {
            up.first=b[i];
            up.second=max(b[i]-b[i-1]+s1,b[i]-1+s2);
            down.first = 1;
            down.second = max(b[i-1]-1+s1,s2);
        }
    }
    return max(up.second,down.second);
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
        int result = cost(arr);
        cout << result << endl;
    }
    return 0;
}
