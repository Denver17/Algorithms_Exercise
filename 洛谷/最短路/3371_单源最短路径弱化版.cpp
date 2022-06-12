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

const int MAXN = 100000 + 10;
const int INF = 0x3f3f3f3f;

typedef pair<int, int> P;   //first代表最短距离,second代表顶点编号

struct edge{
    int v, w;
};

vector<edge> G[MAXN];
vector<int> dist(MAXN);

void dijkstra(int n, int s){
    fill(dist.begin(), dist.end(), INF);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0, s));
    while(!que.empty()){
        P temp = que.top();     que.pop();
        int d = temp.first, u = temp.second;
        //懒惰删除
        //if(d != dist[u]) continue;
        for(int i = 0; i < G[u].size(); i++){
            edge e = G[u][i];
            if(d + e.w < dist[e.v]){
                dist[e.v] = d + e.w;
                que.push(P(dist[e.v], e.v));
            }
        }
    }
    return ;
}

int main()
{
    int n, m, s;    scanf("%d %d %d", &n, &m, &s);
    for(int i = 0; i < m; i++){
        int u, v, w;    scanf("%d %d %d", &u, &v, &w);
        edge e;     e.v = v;    e.w = w;
        G[u].push_back(e);
    }

    dijkstra(n, s);

    cout<<dist[1];
    for(int i = 2; i <= n; i++){
        if(dist[i] != INF)  cout<<" "<<dist[i];
        else    cout<<" "<<INT32_MAX;
    }

    return 0;
}
