#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <deque>
#include <stack>
using namespace std;
vector<pair<int,int> > DIJK;
void swap(pair<int,int>& x, pair<int,int>& y);
int minimum(int x, int y)
{
    if(x > y)
        return y;
    else x;
}
void swap_int(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

class MinHeap
{
    public:
    vector<pair<int,int> > harr; // pointer to array of elements in heap
    vector<int> ptr;
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
    // Constructor
    MinHeap(int capacity);

    // to heapify a subtree with root at given index
    void MinHeapify(int );

    int parent(int i) { return (i-1)/2; }

    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }

    // to extract the root which is the minimum element
    int extractMin();

    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);

    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0].first; }
    int getMinsecond() { return harr[0].second; }


    // Deletes a key stored at index i
    void deleteKey(int i);

    // Inserts a new key 'k'
    void insertKey(int v, int k);
};

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr.resize(cap);
    ptr.resize(cap);
}

// Inserts a new key 'k'
void MinHeap::insertKey(int v, int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i].second = k;
    harr[i].first = v;
    ptr[i+1] = i;
    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)].second > harr[i].second)
    {
        swap_int(ptr[i],ptr[parent(i)]);
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    int temp = ptr[i];
    //cout << "temp : " << temp ;
    harr[temp].second = new_val;
    //cout << "harr[temp].first : " << harr[temp].first ;
    while (temp != 0 && harr[parent(temp)].second > harr[temp].second)
    {
       //cout << "harr[i].first: " << harr[i].first <<  " harr[parent(i)].first : " << harr[parent(i)].first ;
       swap_int(ptr[harr[temp].first],ptr[harr[parent(temp)].first]);
       swap(harr[temp],harr[parent(temp)]);
       temp = parent(temp);
    }
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0].first;
    };
    // Store the minimum value, and remove it from heap
    int root = harr[0].first;
    harr[0] = harr[heap_size-1];
    ptr[heap_size] = 0;
    heap_size--;
    MinHeapify(0);

    return root;
}


// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{

    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].second < harr[i].second)
        smallest = l;
    if (r < heap_size && harr[r].second < harr[smallest].second)
        smallest = r;
    if (smallest != i)
    {

        swap_int(ptr[harr[i].first],ptr[harr[smallest].first]);
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}

// A utility function to swap two elements
void swap(pair<int,int>& x, pair<int,int>& y)
{
    pair<int,int> temp = x;
    x = y;
    y = temp;
}

class Graph
{
    public:
    int V;
    vector<pair<int, int> > *adj;
    Graph(int V);
    void addEdge(int v, int w, int weight);
    int length_of_MST_prim(int start);
};

Graph::Graph(int x)
{
    V = x;
    adj = new vector<pair<int,int> >[V];
}
void Graph::addEdge(int v, int w, int weight)
{
    adj[v].push_back(make_pair(w,weight));
    adj[w].push_back(make_pair(v,weight));
}
int Graph::length_of_MST_prim(int start)
{
    MinHeap h(V);
    DIJK.push_back(make_pair(start,0));
    int MST = 0;
    int i = 0;
    int second;
    int first;
    int heapdistance;
    int min;
    vector<int> visited(V,0);
    visited[start] = 1;
    for(i = 0; i < V ; i++)
    {
        if(start != i)
        h.insertKey(i,INT_MAX);
    }

    vector<pair<int,int> >::iterator it;
    for(it = adj[start].begin(); it!=adj[start].end(); it++)
    {
        h.decreaseKey((*it).first,(*it).second);
    }
    //cout << "h.getMin() : " << h.getMin() ;
    while(h.heap_size!=0)
    {
        second = h.getMinsecond();
        first = h.getMin();
        DIJK.push_back(make_pair(first,second));
        h.extractMin();
        visited[first] = 1;
        //cout << "first : " << first  << " " << "second : " << second << endl;
        for(it = adj[first].begin(); it!=adj[first].end(); it++)
        {
            if(visited[(*it).first]==0)
            {
                min = minimum(second+(*it).second,h.harr[h.ptr[(*it).first]].second);
                //cout << "first : " << first << "min : " << min << endl;
                h.decreaseKey((*it).first,min);

            }
        }

    }
    return 0;
}
int main()
{
    Graph g(9);
    g.addEdge( 0, 1, 4);
    g.addEdge( 0, 7, 8);
    g.addEdge( 1, 2, 8);
    g.addEdge( 1, 7, 11);
    g.addEdge( 2, 3, 7);
    g.addEdge( 2, 8, 2);
    g.addEdge( 2, 5, 4);
    g.addEdge( 3, 4, 9);
    g.addEdge( 3, 5, 14);
    g.addEdge( 4, 5, 10);
    g.addEdge( 5, 6, 2);
    g.addEdge( 6, 7, 1);
    g.addEdge( 6, 8, 6);
    g.addEdge( 7, 8, 7);
    g.length_of_MST_prim(0);

    sort(DIJK.begin(),DIJK.end());
    for(int i=0;i<9;i++)
    {
        cout << DIJK[i].first << " " << DIJK[i].second  << endl;
    }
    return 0;

}
