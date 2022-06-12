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

int N, M;

vector<vector<int> > G;
vector<int> dist;
vector<bool> visited;

int Prim(){
    dist[1] = 0;
    int v = -1;
    
    int asw = 0;
    while(true){
        int v = -1;
        for(int u = 1; u <= N; u++){
            if(!visited[u] && (v == -1 || dist[u] < dist[v]))   v = u;
        }
        if(v == -1)     break;
        visited[v] = true;
        asw += dist[v];
        for(int u = 1; u <= N; u++){
            dist[u] = min(dist[u], G[v][u]);
        }
    }
    return asw;
}

int main()
{
    scanf("%d %d", &N, &M);
    G.resize(N + 1, vector<int>(N + 1, INF));
    dist.resize(N + 1, INF);
    visited.resize(N + 1, false);
    for(int i = 0; i < M; i++){
        int A, B, C;    scanf("%d %d %d", &A, &B, &C);
        G[A][B] = -C;   G[B][A] = -C;
    }
    printf("%d\n", -1 * Prim());

    return 0;
}
