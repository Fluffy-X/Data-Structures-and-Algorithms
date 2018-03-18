#include <bits/stdc++.h>
using namespace std;
vector<int> fenwick(50,0);
vector<int> a(50,0);
void form(int n)
{
    int sum=0;
    int temp = ((n)&(-n));
    int count=0;
    while(temp !=1)
    {
        temp = (temp >> 1);
        count++;
    }
    int index = n;
    sum = a[n];
    n--;
    while(n!=0)
    {
        if(count <= 0)
            break;
        sum += fenwick[n];
        n -= ((n)&(-n));
        count--;
    }
    fenwick[index] = sum;
}
int cmlsum(int l)
{
    int temp=0;
    int sum=0;
    int index =l;
    while(l!=0)
    {
        sum += fenwick[l];
        temp = ((l)&(-l));
        l = l-temp;
    }
    return sum;
}
int rangesum(int l, int u)
{
    int up = cmlsum(u);
    int down = cmlsum(l);
    return up-down+a[l];
}
void update(int index1, int size, int val)
{
    int index = index1;
    while(index <= size)
    {
        fenwick[index] = fenwick[index] - a[index1] + val;
        index += ((index)&(-index));
    }
}
int main()
{
    vector<int> hard = {3,2,-1,6,5,4,-3,3,7,2};
    a[0] = 0;
    for(int i=1; i<=hard.size(); i++)
        a[i] = hard[i-1];
    for(int i=1; i<=hard.size(); i++)
        form(i);
    for(int i=1; i<=hard.size(); i++)
        cout << i << " " << fenwick[i] << endl;
    cout << endl ;
    cout << rangesum(3,8) << endl;
    update(1,hard.size(),-3);
    cout << rangesum(3,8) << endl;
    return 0;
}
