// O(n^2lgn), Bad Solution
#include <bits/stdc++.h>
using namespace std;
int range_min(int i, int j, int a, int b, int index, vector<int> &seg);
int F(int i, vector<int> &seg)
{
    int a=0,b=0;
    if(seg[2*i+1]==10000 && seg[2*i+2]==10000)
    {
        a = F(2*i+1,seg);
        b = F(2*i+2,seg);
    }
    else if(seg[2*i+1]!=10000 && seg[2*i+2]==10000)
    {
        a = seg[2*i+1];
        b = F(2*i+2,seg);
    }
    else if(seg[2*i+1]==10000 && seg[2*i+2]!=10000)
    {
        b = seg[2*i+2];
        a = F(2*i+1,seg);
    }
    else
    {
        a = seg[2*i+1];
        b = seg[2*i+2];
    }
    seg[i] = min(a,b);
    return seg[i];
}

void create_segment_tree(vector<int> &arr, int start, int stop)
{
    int n = arr.size();
    int c=0;
    int flag=0;
    while(n!=1)
    {
        if(n%2!=0)
            flag++;
        n = n/2;
        c++;
    }
    n = arr.size();
    if(flag)
        n = pow(2,c+1);
    vector<int> seg(2*n-1,10000);
    for(int i=0; i<arr.size(); i++)
        seg[n-1+i] = arr[i];
    for(int i=arr.size(); i<n; i++)
        seg[n-1+i] = 20000;
    F(0,seg);
    for(int i=0; i<2*n-1; i++)
        cout << seg[i] << " ";
    cout << range_min(0,arr.size()-1,start,stop,0,seg);
}

int range_min(int i, int j, int a, int b, int index, vector<int> &seg)
{
    int left=10000,right=10000;
    if( a<=i && j<=b)
        return seg[index];
    else if(a > j || b < i)
        return 10000;
    else
    {
        left = range_min(i,(i+j)/2,a,b,2*index+1,seg);
        right = range_min((i+j)/2+1,j,a,b,2*index+2,seg);
    }
    return min(left,right);
}
int largestRectangle(vector<int> &arr)
{
    int n = arr.size();
    int c=0;
    int flag=0;
    while(n!=1)
    {
        if(n%2!=0)
            flag++;
        n = n/2;
        c++;
    }
    n = arr.size();
    if(flag)
        n = pow(2,c+1);
    //cout << "n is : " << n <<endl;
    vector<int> seg(2*n-1,10000);
    for(int i=0; i<arr.size(); i++)
        seg[n-1+i] = arr[i];
    for(int i=arr.size(); i<n; i++)
        seg[n-1+i] = 20000;
    F(0,seg);





    int ans = -10;

    for(int m=0; m<arr.size(); m++)
        ans = max(ans,arr[m]);
    for(int m=1; m<arr.size(); m++)
    {
        for(int i=0; i<arr.size()-m; i++)
        {
            //cout << m+1 << " : " << (m+1)*range_min(0,n-1,i,i+m,0,seg)<< endl;
            ans = max(ans, (m+1)*range_min(0,n-1,i,i+m,0,seg));

        }

    }
    //cout << range_min(0,arr.size()-1,n-1,4,0,seg) << endl;
    return ans;

}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int h_i = 0; h_i < n; h_i++){
       cin >> h[h_i];
    }
    int result = largestRectangle(h);
    cout << result << endl;
    return 0;
}
