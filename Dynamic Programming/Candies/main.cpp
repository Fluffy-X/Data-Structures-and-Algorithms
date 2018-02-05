#include <bits/stdc++.h>

using namespace std;

int candies(int n, vector <int> arr) {
    // Complete this function
    vector<int> difference(n);
    difference[0]=1;
    for(int i=1; i<n; i++)
    {
        if(difference[i-1] > 1)
        {
            if(arr[i] > arr[i-1])
                difference[i] = difference[i-1]+1;
            else
                difference[i]=1;
        }
        else
        {
            if(arr[i] == arr[i-1])
                difference[n]=1;
            else if(arr[i] > arr[i-1])
                difference[i] = difference[i-1] +1;
            else
            {
                difference[i] = 1;
                for(int j=i-1; j>=0; j--)
                {
                    if(j==0 && arr[j] > arr[j+1])
                    {
                        difference[j]++;
                        break;
                    }
                    if(arr[j-1] > arr[j] && arr[j] > arr[j+1])
                        difference[j]++;
                    else
                        break;
                }
            }
        }
    }
    int sum=0;
    for(int i=0; i<n; i++)
        sum += difference[i];
    return sum;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = candies(n, arr);
    cout << result << endl;
    return 0;
}
