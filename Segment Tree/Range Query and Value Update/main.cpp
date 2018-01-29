#include <bits/stdc++.h>
using namespace std;

class Segment_Tree{
public:
    vector<int> seg;
    vector<int> arr;
    int proper_size;
    void form_segment_tree(int start, int stop, int index);
    void update_value(int index);
    void pre_update_value(int i, int value);
    Segment_Tree(vector<int> a);
    void print();
    int pre_range_query(int start, int stop);
    int range_query(int start, int stop, int a, int b, int index);
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


int main()
{
    //cout << "Boo" ;
    vector<int> v = {1,3,4,2,-1};
    Segment_Tree s(v);
    //s.print();
    cout << s.pre_range_query(2,4) << endl;
    s.pre_update_value(2,-2);
    //s.print();
    cout << s.pre_range_query(2,4);
    return 0;
}
