#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <deque>
#include <stack>
using namespace std;

class Graph
{
    public:
    int V;
    vector<pair<int, int> > *adj;
    Graph(int V);
    void addEdge(int v, int w, int weight);
};
Graph::Graph(int x)
{
    V = x;
    adj = new vector<pair<int,int> >[V];
}

void Graph::addEdge(int v, int w, int weight)
{
    adj[v].push_back(make_pair(w,weight));
    adj[w].push_back(make_pair(v,weight)); // Add w to v’s list.
}
// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}



class MinHeap
{
    vector<pair<int, int> > harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
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
    // Returns the minimum key (key at root) from min heap
    int getMinfirst() { return harr[0].first; }
    int getMinsecond() { return harr[0].second; }

    // Inserts a new key 'k'
    void insertKey(int k, int distance);
};

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr.resize(cap);
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k, int distance)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i].first = k;
    harr[i].second = distance;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)].first > harr[i].first)
    {
       swap(&harr[i].first, &harr[parent(i)].first);
       swap(&harr[i].second, &harr[parent(i)].second);
       i = parent(i);
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
    }

    // Store the minimum value, and remove it from heap
    int root = harr[0].first;
    harr[0].first = harr[heap_size-1].first;
    harr[0].second = harr[heap_size-1].second;

    heap_size--;
    MinHeapify(0);

    return root;
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].first < harr[i].first)
        smallest = l;
    if (r < heap_size && harr[r].first < harr[smallest].first)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i].first, &harr[smallest].first);
        swap(&harr[i].second, &harr[smallest].second);

        MinHeapify(smallest);
    }
}













vector<int> constr;
int constraint(int x)
{
    vector<int>::iterator ite;
    for(ite = constr.begin(); ite!=constr.end(); ite++)
    {
        if(*ite==x)
            return 0;
    }
    return 1;
}
int main()
{
    MinHeap h(20);
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
    int j = 0,i=0, pmst = 0,k=0;
    vector<pair<int, int> >::iterator it;
    /*for(i=0; i<g.V; i++)
    {
        cout << i  << " " ;
        for(it = g.adj[i].begin(); it!=g.adj[i].end(); it++)
        {
            cout << (*it).first << " " ;
        }
        cout << endl;
    }*/
    for(i=0; k<6; i++)
    {
        for(it = g.adj[j].begin(); it!=g.adj[j].end(); it++)
        {
            if(constraint((*it).first))
            {
                //cout << "Test : " << (*it).first   ;
                h.insertKey((*it).second,(*it).first);
                if(k==6)
                    cout << "+" ;
            }
        }
        if(constraint(h.getMinsecond())==0)
           h.extractMin();
        else
        {
            pmst = pmst + h.getMinfirst();
            constr.push_back(j);
            k++;
            j = h.getMinsecond();
            if(k==5)
            {
                cout << "5 : " << h.getMinfirst() << endl;
                cout << h.getMinsecond() << endl;
                cout << pmst <<endl;
                cout << j <<endl << endl;
                h.extractMin();
                cout << "5 : " << h.getMinfirst() << endl;
                cout << h.getMinsecond() << endl;
                //h.extractMin();h.extractMin();//h.extractMin();
                //return 0;
            }
            if(k==6)
            {
                cout << "6 : " << h.getMinfirst() << endl;
                cout << h.getMinsecond() << endl;
                cout << pmst <<endl;
                cout << j << endl ;
                //return 0;
            }

            h.extractMin();
        }
    }
    cout << pmst;
    return 0;
}
