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

const int MAXN = 1000 + 10;
const int INF = 0x3f3f3f3f;

typedef pair<int, int> P;   //first代表最短距离,second代表顶点编号

struct edge{
    int to, cost;
};

vector<edge> G[MAXN];
vector<int> dist(MAXN);

void dijkstra(int s){
    fill(dist.begin(), dist.end(), INF);
    priority_queue<P, vector<P>, greater<P> > que;
    dist[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        P temp = que.top();     que.pop();
        int d = temp.first, u = temp.second;
        if(dist[u] < d)     continue;
        for(int i = 0; i < G[u].size(); i++){
            edge e = G[u][i];
            if(e.cost + d < dist[e.to]){
                dist[e.to] = e.cost + d;
                que.push(P(dist[e.to], e.to));
            }
        }
    }
    return ;
}

int main()
{
    int n, m;   scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int u, v, w;    scanf("%d %d %d", &u, &v, &w);
        edge e;     e.to = v;   e.cost = w;
        G[u].push_back(e);
    }

    int asw = 0;
    dijkstra(1);
    for(int i = 2; i <= n; i++) asw += dist[i];

    for(int i = 2; i <= n; i++){
        dijkstra(i);
        asw += dist[1];
    }

    cout<<asw<<endl;

    return 0;
}
