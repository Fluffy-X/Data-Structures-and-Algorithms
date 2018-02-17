#include <bits/stdc++.h>
using namespace std;
vector<int> graph[101];
vector<int> visited(101,0);
vector<int> distanc(101,-1);

void bfs()
{
    queue<int> q;
    q.push(1);
    int foo;
    while(!q.empty())
    {
        foo = q.front();
        for(auto itr=graph[foo].begin(); itr!= graph[foo].end(); itr++)
        {
            if(visited[*itr]==0)
            {
                distanc[*itr] = 1+ distanc[foo];
                q.push(*itr);
                visited[*itr]=1;
            }
        }
        q.pop();
    }
}


int quickestWayUp(vector < vector<int> > ladders, vector < vector<int> > snakes) {
    // Complete this function
    for (auto& v : graph) {
    v.clear();
    }
    unordered_set<int> lset;
    unordered_set<int> sset;

    fill(visited.begin(),visited.end(),0);
    fill(distanc.begin(),distanc.end(),-1);
    distanc[1] = 0;
    for(int i=0; i<ladders.size(); i++)
    {
        lset.insert(ladders[i][0]);
        int temp = ladders[i][0];
        int j=1;
        while(j<=6)
        {
            if(temp-j <= 0)
            {
                j++;
                continue;
            }
            graph[temp-j].push_back(ladders[i][1]);
            j++;
        }
    }
    for(int i=0; i<snakes.size(); i++)
    {
        sset.insert(snakes[i][0]);
        int temp = snakes[i][0];
        int j=1;
        while(j<=6)
        {
            if(temp-j <= 0)
            {
                j++;
                continue;
            }
            graph[temp-j].push_back(snakes[i][1]);
            j++;
        }
    }
    for(int i=1; i<=100; i++)
    {
        for(int j=1; j<=6; j++)
        {
            if(j+i > 100)
                continue;
            else
            {
                if(lset.find(i) != lset.end() || sset.find(i) != sset.end() )
                    continue;
                graph[i].push_back(j+i);
            }
        }
    }
    bfs();
    return distanc[100];
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector< vector<int> > ladders(n,vector<int>(2));
        for(int ladders_i = 0;ladders_i < n;ladders_i++){
           for(int ladders_j = 0;ladders_j < 2;ladders_j++){
              cin >> ladders[ladders_i][ladders_j];
           }
        }
        int m;
        cin >> m;
        vector< vector<int> > snakes(m,vector<int>(2));
        for(int snakes_i = 0;snakes_i < m;snakes_i++){
           for(int snakes_j = 0;snakes_j < 2;snakes_j++){
              cin >> snakes[snakes_i][snakes_j];
           }
        }
        int result = quickestWayUp(ladders, snakes);
        cout << result << endl;
    }
    return 0;
}
