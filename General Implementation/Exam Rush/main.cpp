#include <bits/stdc++.h>

using namespace std;

long long examRush(vector <long long> tm, long long t) {
    // Complete this function
  sort(tm.begin(),tm.end());
  long long ans=0;
  long long i;
  for(i=0; i<tm.size(); i++)
  {
    if(ans+tm[i] > t)
      break;
    ans += tm[i];
  }
  return i;
}

int main() {
    long long n;
    long long t;
    cin >> n >> t;
    vector<long long> tm(n);
    for(long long tm_i = 0; tm_i < n; tm_i++){
       cin >> tm[tm_i];
    }
    long long result = examRush(tm, t);
    cout << result << endl;
    return 0;
}
