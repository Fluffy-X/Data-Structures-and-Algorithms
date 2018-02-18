#include <bits/stdc++.h>
using namespace std;

bool left(int i, int range, vector<int> height, vector<int> position, int n)
{
    if(range >= position[i+1])
    {
        if(i==n-1)
            return 1;
        return left(i+1, max(range,position[i+1]+height[i+1]), height, position, n);
    }
    else
        return 0;
}
bool right(int i, int range, vector<int> height, vector<int> position, int n)
{
    if(range <= position[i-1])
    {
        if(i==1)
            return 1;
        return right(i-1, min(range,position[i-1]-height[i-1]), height, position, n);
    }
    else
        return 0;
}
string checkAll(int n, vector <int> height, vector <int> position) {
    // Complete this function
    //string ans;
    bool a = left(0, position[0]+height[0], height, position, n);
    bool b = right(n-1, position[n-1]-height[n-1], height, position, n);
    if( a==1 && b==1)
        return "BOTH";
    else if( a!=1 && b!=1)
        return "NONE";
    else if( a==1 && b!=1)
        return "LEFT";
    else if( a!=1 && b==1)
        return "RIGHT";
    else
        return "What the heck";
}

int main() {
    int n;
    cin >> n;
    vector<int> position(n);
    for(int position_i = 0; position_i < n; position_i++){
       cin >> position[position_i];
    }
    vector<int> height(n);
    for(int height_i = 0; height_i < n; height_i++){
       cin >> height[height_i];
    }
    string ret = checkAll(n, height, position);
    cout << ret << endl;
    return 0;
}
