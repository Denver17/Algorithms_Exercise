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

const int MAXN = 1000000 + 10;
const int INF = 0x3f3f3f3f;

typedef pair<int, int> P;   //first代表最短距离,second代表顶点编号
typedef long long ll;

struct edge{
    int to, cost;
};

vector<edge> G[MAXN];
vector<int> dist(MAXN);
vector<int> pre[MAXN];
vector<ll> pathNum(MAXN, -1);
ll asw = 0;

void dijkstra(int s){
    fill(dist.begin(), dist.end(), INF);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0, s));
    while(!que.empty()){
        P temp = que.top();     que.pop();
        int d = temp.first, u = temp.second;
        if(dist[u] < d)     continue;
        for(int i = 0; i < G[u].size(); i++){
            edge e = G[u][i];
            if(d + e.cost < dist[e.to]){
                dist[e.to] = d + e.cost;
                que.push(P(dist[e.to], e.to));
                pre[e.to].clear();
                pre[e.to].push_back(u);
            }
            else if(d + e.cost == dist[e.to]){
                pre[e.to].push_back(u);
            }
        }
    }
    return ;
}

void DFS(int cur){
    if(cur == 1){   //当前结点到达起点
        asw++;
        return ;
    }
    for(int i = 0; i < pre[cur].size(); i++){
        if(pathNum[pre[cur][i]] != -1){
            asw = (asw + pathNum[pre[cur][i]]) % 100003;
            continue;
        }
        DFS(pre[cur][i]);
    }
}

int main()
{
    int N, M;   scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        int x, y;   scanf("%d %d", &x, &y);
        edge e1, e2;
        e1.to = y;  e1.cost = 1;
        e2.to = x;  e2.cost = 1;
        G[x].push_back(e1);
        G[y].push_back(e2);
    }
    
    dijkstra(1);

    for(int i = 1; i <= N; i++){
        if(dist[i] == INF){
            cout<<0<<endl;
            continue;
        }
        asw = 0;
        DFS(i);
        pathNum[i] = asw;
        cout<<(asw % 100003)<<endl;
    }

    return 0;
}
