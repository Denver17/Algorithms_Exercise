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

const int MAXN = 10000 + 10;
const int INF = 0x3f3f3f3f;

typedef pair<int, int> P;   //first代表最短距离,second代表结点编号

struct edge{
    int to, cost, weight;
};

vector<edge> G[MAXN];
vector<int> dist(MAXN);
vector<int> dist2(MAXN);

void dijkstra(int s){
    fill(dist.begin(), dist.end(), INF);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0, s));
    while(!que.empty()){
        P temp = que.top();   que.pop();
        int d = temp.first, u = temp.second;
        if(dist[u] < d) continue;
        for(int i = 0; i < G[u].size(); i++){
            edge e = G[u][i];
            if(e.weight + d < dist[e.to]){
                dist[e.to] = e.weight + d;
                que.push(P(dist[e.to], e.to));
            }
        }
    }
    return ;
}

int main()
{
    int N, M;
    while(scanf("%d %d", &N, &M)){
        if(N == 0 && M == 0)    break;
        for(int i = 0; i < MAXN; i++)   G[i].clear();
        for(int i = 0; i < M; i++){
            int u, v, d, c;     scanf("%d %d %d %d", &u, &v, &d, &c);
            edge e1, e2;
            e1.to = v;  e1.weight = d;  e1.cost = c;
            e2.to = u;  e2.weight = d;  e2.cost = c;
            G[u].push_back(e1);
            G[v].push_back(e2);
        }
        dijkstra(1);
        int asw = 0;
        for(int i = 2; i <= N; i++){
            int res = 0x3f3f3f3f;
            for(int j = 0; j < G[i].size(); j++){
                edge e = G[i][j];
                int d = e.weight, v = e.to;
                if(dist[i] == d + dist[v] && e.cost < res){
                    res = e.cost;
                }
            }
            asw += res;
        }
        cout<<asw<<endl;
    }

    return 0;
}
