#include <bits/stdc++.h>
using namespace std;

class Segment_Tree{
public:
    vector<long> seg;
    vector<long> arr;
    long proper_size;
    void form_segment_tree(long start, long stop, long index);
    void update_value(long index);
    void pre_update_value(long i, long value);
    Segment_Tree(vector<long> a);
    void prlong();
    long pre_range_query(long start, long stop);
    long range_query(long start, long stop, long a, long b, long index);
};
long Segment_Tree::pre_range_query(long start, long stop)
{
    return range_query(start,stop,0,proper_size-1,0);
}
long Segment_Tree::range_query(long start, long stop, long a, long b, long index)
{
    if(stop < a || b<start)
        return LONG_MAX;
    else if(start<=a && stop>=b)
        return seg[index];
    else
        return min(range_query(start,stop,a,(a+b)/2,2*index+1), range_query(start,stop,(a+b)/2+1,b,2*index+2));
}
void Segment_Tree::prlong()
{
    for(long i=0; i<seg.size(); i++)
        cout << seg[i] << " ";
    cout << endl;
}
Segment_Tree::Segment_Tree(vector<long> a)
{
    arr = a;
    long x = a.size();
    if((x&(x-1))==0) // Braces are important
        x = a.size();
    else
    {
        long i = 1;
        for(long j=0; j<=3; j++)
        {
            x = x|x>>i;
            i*=2;
        }
        x++;
        arr.resize(x,LONG_MAX);//
    }
    proper_size = x;
    seg.resize(2*x-1,0);
    form_segment_tree(0,x-1,0);
}
void Segment_Tree::form_segment_tree(long start, long stop, long index)
{
    if(start==stop)
    {
        seg[index] = arr[start];
        return;
    }
    form_segment_tree(start,(start+stop)/2,2*index+1);
    form_segment_tree(((start+stop)/2)+1,stop,2*index+2);
    seg[index] = min( seg[2*index+1], seg[2*index+2]);
}
void Segment_Tree::pre_update_value(long i, long value)
{
    long index = proper_size-1+i;
    seg[index] = value;
    update_value(index);
}
void Segment_Tree::update_value(long index)
{
    if(index==0)
        return ;
    seg[(index-1)/2] = min(seg[index], seg[index+1]);
    update_value((index-1)/2);
}
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
        if(a[s.top()] < a[i])
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

long raceAgainstTime(long n, long mason_height, vector <long> heights, vector <long> prices)
{
    long zero = 0;
    vector<long> padded_prices;
    vector<long> padded_heights;



    padded_heights.push_back(mason_height);
    padded_heights.insert(padded_heights.end(),heights.begin(),heights.end());
    padded_prices.push_back(0);
    padded_prices.insert(padded_prices.end(),prices.begin(),prices.end());

    vector<long> e = range(padded_heights);
    vector<long> seg(n,LONG_MAX);
    Segment_Tree s(seg);
    vector<long> dp(n);
    dp[n-1] = padded_prices[n-1]-padded_heights[n-1];
    s.pre_update_value(n-1,dp[n-1]-padded_heights[n-1]);
    for(long i=n-2; i>=0; i--)
    {
        if(e[i]==n-1)
            dp[i] = padded_prices[i]+min(zero, padded_heights[i] + s.pre_range_query(i+1,e[i] ) );
        else
        {
            if(i==e[i])
                dp[i] = padded_prices[i] + dp[i+1];
            else
            {
                dp[i] = padded_prices[i] + padded_heights[i] + s.pre_range_query(i+1,e[i]);
                dp[i] = min(dp[i], padded_prices[i]+dp[i+1]+padded_heights[i+1] + abs(padded_heights[i]-padded_heights[i+1]));
                //dp[i] = min(dp[i] , )
                //dp[i] = min(dp[i], abs(padded_heights[i]-padded_heights[e[i]+1]+dp[e[i]+1]));
            }
        }
        s.pre_update_value(i,dp[i]-padded_heights[i]);
    }
    for(auto i: dp)
        cout << i << endl;
    return dp[0]+padded_heights[0]+n;
}
int main()
{
    long n;
    cin >> n;
    long mason_height;
    cin >> mason_height;
    vector<long> heights(n-1);
    for(long heights_i = 0; heights_i < n-1; heights_i++){
       cin >> heights[heights_i];
    }
    vector<long> prices(n-1);
    for(long prices_i = 0; prices_i < n-1; prices_i++){
       cin >> prices[prices_i];
    }
    long result = raceAgainstTime(n, mason_height, heights, prices);
    cout << endl <<  result << endl;
    return 0;
}
