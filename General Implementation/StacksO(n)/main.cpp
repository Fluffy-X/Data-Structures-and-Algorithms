#include <bits/stdc++.h>
using namespace std;

vector<long> range(vector<long> a)
{
    vector<long> e(a.size(),0);
    stack<long> s;
    s.push(a.size()-1);
    long i = a.size()-2;
    e[a.size()-1] = a.size()-1;
    while(i!=-1)
    {
        if(s.empty())
        {

            e[i] = a.size()-1;
            s.push(i);i--;
        }
        if(a[s.top()] <= a[i])
        {
            s.pop();
        }
        else
        {
            e[i] = s.top()-1;
            s.push(i);
            i--;
        }
    }
    return e;

}
int main()
{
    //vector<long> a = {2,3,6,5,4,3,1,6,7,1,4,3,2};
    vector<long> a = {5,2,6,2};
    vector<long> e = range(a);
    for(long i=0; i<a.size(); i++)
        cout << a[i] << " " << i << " " << e[i] << endl;
    return 0;
}
