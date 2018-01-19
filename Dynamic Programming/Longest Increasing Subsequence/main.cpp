#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> v[arr_i];
    }
    int current,i,j,c=1,ans=1;
    vector<int> mem(v.size(),-1);
    for(i=0; i<n; i++,c=1)
    {
        if(mem[i]!=-1)
            continue;
        current=v[i];
        for(j=i+1; j<n; j++)
        {
            if(current <v[j])
            {
                if(mem[j]!=-1)
                {
                    c+=mem[j];
                    break;
                }
                c++;
                current = v[j];
            }
        }
        mem[i]=c;
        ans = max(ans,c);
        for(j=i+1; j<n; j++)
        {
            if(current <v[j])
            {
                if(mem[j]!=-1)
                    break;
                mem[j]=c-1;
                c--;
                current = v[j];
            }
        }

    }
    cout << endl << ans ;
    return 0;
}
