#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
using namespace std;

const int MAXN = 20;
const int INF = 0x3f3f3f3f;
const int MAXV = 10;

typedef pair<int, int> P;   //first表示最短距离,second表示顶点编号

struct edge{
    int to, cost;           //to表示边指向的编号,cost表示距离
};

vector<edge> G[MAXN];

void dijkstra(vector<int> &dist, vector<bool> &visited, int s){
    fill(dist.begin(), dist.end(), INF);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top();    que.pop();
        int v = p.second;    int d = p.first;
        for(int i = 0; i < G[v].size(); i++){
            edge &e = G[v][i];
            if(dist[e.to] > d + e.cost){
                dist[e.to] = d + e.cost;
                que.push(P(dist[e.to], e.to));
            }
        }
    }
    return ;
}


int main()
{
    int n;  
    while(cin>>n){
        if(n == 0)  break;
        for(int i = 0; i < MAXN; i++)   G[i].clear();
        int maxnum = -1;
        for(int i = 0; i < n; i++){
            int u, v, w;    cin>>u>>v>>w;
            edge e1, e2;
            e1.to = u;  e1.cost = w;
            e2.to = v;  e2.cost = w;
            G[u].push_back(e2);
            G[v].push_back(e1);
            if(u > maxnum || v > maxnum)    maxnum = max(u, v);
        }
        int asw = 0, aswdist = INF;
        for(int i = 0; i <= maxnum; i++){
            vector<int> dist(MAXN);
            vector<bool> visited(MAXN, false);
            dijkstra(dist, visited, i);
            int temp = 0;
            for(int j = 0; j <= maxnum; j++)    temp += dist[j];
            if(temp < aswdist){
                aswdist = temp;
                asw = i;
            }
        }
        cout<<asw<<" "<<aswdist<<endl;
    }
    return 0;
}
