#include <bits/stdc++.h>
using namespace std;
const int N = 100 , INF = (int)2e9;
int n,not_bal[N+2];
int nodes, F[N+2][N+2], C[N+2][N+2], x_like[N+2], ht[N+2], nxt[N+2];
 void push(int u,int v) {
  int df = min(x_like[u] , C[u][v] - F[u][v]);
  F[u][v] += df , F[v][u] -= df;
  x_like[u] -= df, x_like[v] += df;
}
 void boo(int u){
  int min_ht = 2*nodes;
  for(int v=0;v<nodes;v++)
    if( C[u][v] > F[u][v] ) min_ht = min(min_ht,ht[v]);
  ht[u] = min_ht+1;
}
void disc(int u) {
  while( x_like[u] > 0 ) {
    int v = nxt[u];
    if( v < nodes ) {
      if( C[u][v] > F[u][v] and ht[u] > ht[v] ) push(u,v);
      else ++nxt[u];
    } else {
      boo(u); nxt[u] = 0;
    }
  }
}
int driver(int src=0,int sink=n+1) {
  fill(x_like,x_like+nodes,0);
  fill(ht,ht+nodes,0);
  fill(nxt,nxt+nodes,0);

  int list[nodes-2];
  for(int i=0,j=0;i<nodes;i++) {
    if( i==src or i==sink ) continue;
    list[j++] = i;
  }
  ht[src] = nodes; x_like[src] = INF;
  for(int i=0;i<nodes;i++)
    if(i != src) push(src,i);

  int index = 0;
  while( index < nodes-2 ) {
    int u = list[index];
    int prev_ht = ht[u];
    disc(u);
    if( ht[u] > prev_ht ) {
      for(int j=index-1;index>0;index--,j--)
	list[index] = list[j];
      list[0] = u;
    } else {
      index++;
    }
  }
  int max_likelow = 0;
  for(int v=0;v<nodes;v++)
    max_likelow += F[src][v];
  return max_likelow;
}
void constructGraph(int guess) {
  nodes = n+2;
  memset(F,0,sizeof F);
  memset(C,0,sizeof C);
  int src = 0, sink = n+1;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) {
      C[i][j] = C[j][i] = guess;
    }
  for(int i=1;i<=n;i++)
    if( not_bal[i] > 0 ) C[src][i] = not_bal[i];
    else if( not_bal[i] < 0 ) C[i][sink] = -not_bal[i];
}
int main(){
  cin >> n;
  int tf = 0 , checkFeasible = 0;
  for(int i=1;i<=n;i++) {
    cin >> not_bal[i];
    if( not_bal[i] > 0 ) tf += not_bal[i];
    if( not_bal[i] < 0 ) checkFeasible -= not_bal[i];
  }
  assert(tf == checkFeasible);
  not_bal[0] = not_bal[n+1] = 0;
  int answer = 0 ,
    hi = max( *max_element(not_bal+1,not_bal+n+1) ,
	      -*min_element(not_bal+1,not_bal+n+1) );
  while( answer < hi ) {
    int guess = (answer + hi)/2;
    constructGraph(guess);
    int flow = driver();
    if( tf == flow ) hi = guess;
    else answer = guess+1;
  }
  cout << answer << '\n';
  return 0;
}
