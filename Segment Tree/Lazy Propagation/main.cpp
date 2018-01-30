#include <bits/stdc++.h>
using namespace std;

class Segment_Tree{
public:
    vector<int> seg;
    vector<int> lazyarray;
    vector<int> arr;
    int proper_size;
    void form_segment_tree(int start, int stop, int index);
    void update_value(int index);
    void pre_update_value(int i, int value);
    Segment_Tree(vector<int> a);
    void print();
    int pre_range_query(int start, int stop);
    int range_query(int start, int stop, int a, int b, int index);
    int lazy(int i, int j, int value, int start, int stop, int index);
};
int Segment_Tree::pre_range_query(int start, int stop)
{
    return range_query(start,stop,0,proper_size-1,0);
}
int Segment_Tree::range_query(int start, int stop, int a, int b, int index)
{
    if(stop < a || b<start)
        return INT_MAX;
    else if(start<=a && stop>=b)
        return seg[index];
    else
        return min(range_query(start,stop,a,(a+b)/2,2*index+1), range_query(start,stop,(a+b)/2+1,b,2*index+2));
}
void Segment_Tree::print()
{
    for(int i=0; i<seg.size(); i++)
        cout << seg[i] << " ";
    cout << endl;
    for(int i=0; i<lazyarray.size(); i++)
        cout << lazyarray[i] << " ";
    cout << endl;
}
Segment_Tree::Segment_Tree(vector<int> a)
{
    arr = a;
    int x = a.size();
    if((x&(x-1))==0) // Braces are important
        x = a.size();
    else
    {
        int i = 1;
        for(int j=0; j<=3; j++)
        {
            x = x|x>>i;
            i*=2;
        }
        x++;
        arr.resize(x,INT_MAX);//
    }
    proper_size = x;
    seg.resize(2*x-1,0);
    lazyarray.resize(2*x-1,0);
    form_segment_tree(0,x-1,0);
}
void Segment_Tree::form_segment_tree(int start, int stop, int index)
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
void Segment_Tree::pre_update_value(int i, int value)
{
    int index = proper_size-1+i;
    seg[index] = value;
    update_value(index);
}
void Segment_Tree::update_value(int index)
{
    if(index==0)
        return ;
    seg[(index-1)/2] = min(seg[index], seg[index+1]);
    update_value((index-1)/2);
}

int Segment_Tree::lazy(int i, int j, int value, int start, int stop, int index)// [i,j] is given range and start=0, stop is proper_size-1
{
    if(i<=start && stop<=j)
    {
        if(start==stop)
        {
            seg[index] += value + lazyarray[index];
            lazyarray[index] = 0;
            return seg[index];
        }
        else
        {
            lazyarray[2*index+1] += value + lazyarray[index];
            lazyarray[2*index+2] += value + lazyarray[index];
            seg[index] += value + lazyarray[index];
            lazyarray[index] = 0;
            return seg[index];
        }
    }
    else if( i>stop || start>j)
        return INT_MAX;
    else
    {
        seg[index] = min(lazy(i,j,value,start,(start+stop)/2,2*index+1), lazy(i,j,value,(start+stop)/2+1,stop,2*index+2));
        return seg[index];
    }
}

int main()
{
    vector<int> v = {1, 3, 5, 7, 9, 11};
    Segment_Tree s(v);
    cout << s.pre_range_query(1,3) << endl;
    cout << s.lazy(1,5,10,0,7,0) << endl;
    s.print();

    return 0;
}
