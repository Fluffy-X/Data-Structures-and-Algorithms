#include <iostream>
#include <vector>
#include <stack>
#include <stack>
#define v 10
using namespace std;
int graph[v][v] = {
                  {0,1,0,0,1,1,0,0,0,0},
                  {1,0,1,0,0,0,1,0,0,0},
                  {0,1,0,1,0,0,0,1,0,0},
                  {0,0,1,0,1,0,0,0,1,0},
                  {1,0,0,1,0,0,0,0,0,1},
                  {1,0,0,0,0,0,0,1,1,0},
                  {0,1,0,0,0,0,0,0,1,1},
                  {0,0,1,0,0,1,0,0,0,1},
                  {0,0,0,1,0,1,1,0,0,0},
                  {0,0,0,0,1,0,1,1,0,0}
                 };
int visited[v] = {0};
int verticesvisited = 0;
stack<stack<int> > answer;
stack<int> s;

void backtrack(int i,int start)
{
    visited[i] = 1;
    verticesvisited++;
    s.push(i);
    int j = 0;
    for(j = 0; j < v ; j++)
    {
        if(graph[i][j]==1 && visited[j]==0)
        {
            backtrack(j,start);
        }
        if(verticesvisited==v && j==start && visited[j]==1)
        {
            answer.push(s);
            s.pop();
            visited[i]=0;
            verticesvisited--;
            return;
        }
    }
    s.pop();
    visited[i]=0;
    verticesvisited--;

}
int main()
{
    backtrack(1,0);
    stack<int> qprint;
    while(!answer.empty())
    {
        qprint = answer.top();
        answer.pop();
        while(!qprint.empty())
        {
            cout << qprint.top() << " " ;
            qprint.pop();
        }
        cout << endl ;
    }
    return 0;
}
