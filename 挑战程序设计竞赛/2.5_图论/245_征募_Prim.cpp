//Prim算法，内存会爆
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

const int INF = 0x3f3f3f3f;

vector<vector<int> > G;
vector<int> dist;
vector<bool> visited;

int Prim(int V){
    int asw = 0;
    dist[0] = 0;

    while(true){
        int v = -1;
        for(int u = 0; u < V; u++){
            if(!visited[u] && (v == -1 || dist[u] < dist[v]))   v = u;
        }
        if(v == -1)     break;
        visited[v] = true;
        asw += min(dist[v], 0);
        for(int u = 0; u < V; u++){
            dist[u] = min(dist[u], G[v][u]);
        }
    }
    return asw;
}

int main()
{
    int T;  scanf("%d", &T);
    while(T--){
        getchar();
        int N, M, R;    scanf("%d %d %d", &N, &M, &R);
        G.resize(N + M, vector<int>(N + M, INF));
        dist.resize(N + M, INF);
        visited.resize(N + M, false);
        for(int i = 0; i < R; i++){
            int x, y, d;    scanf("%d %d %d", &x, &y, &d);
            G[x][y + N] = min(G[x][y + N], -1 * d);
            G[y + N][x] = min(G[y + N][x], -1 * d);
        }
        int asw = Prim(N + M);
        printf("%d\n", 10000 * (N + M) + asw);
        G.clear();
        dist.clear();
        visited.clear();
    }

    return 0;
}
