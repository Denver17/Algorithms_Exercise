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

const int MAXN = 5000 + 10;
const int INF = INT_MAX;

typedef pair<int, int> P;   //first代表最短距离，second代表顶点编号

struct edge{
    int to, cost;
};

vector<edge> G[MAXN];
vector<int> dist(MAXN);
vector<int> dist2(MAXN);

void dijkstra(int N, int s){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(dist.begin(), dist.end(), INF);
    fill(dist2.begin(), dist2.end(), INF);
    dist[1] = 0;
    que.push(P(0, 1));
    while(!que.empty()){
        P p = que.top();    que.pop();
        int v = p.second, d = p.first;
        if(dist2[v] < d)    continue;
        for(int i = 0; i < G[v].size(); i++){
            edge &e = G[v][i];
            int d2 = d + e.cost;
            if(dist[e.to] > d2){
                swap(dist[e.to], d2);
                que.push(P(dist[e.to], e.to));
            }
            if(dist2[e.to] > d2 && dist[e.to] < d2){
                dist2[e.to] = d2;
                que.push(P(dist2[e.to], e.to));
            }
        }
    }
    return ;
}

int main()
{
    int N, R;   cin>>N>>R;
    for(int i = 0; i < R; i++){
        int x, y, D;    cin>>x>>y>>D;
        edge e1, e2;
        e1.to = y;  e1.cost = D;
        e2.to = x;  e2.cost = D;
        G[x].push_back(e1);
        G[y].push_back(e2);
    }
    
    dijkstra(N, 1);

    cout<<dist2[N]<<endl;

    return 0;
}
