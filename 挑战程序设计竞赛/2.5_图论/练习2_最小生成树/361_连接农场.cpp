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

int N;

vector<vector<int> > G;
vector<int> dist;
vector<bool> visited;

int Prim(){
    dist[0] = 0;
    int v = -1;
    
    int asw = 0;
    while(true){
        int v = -1;
        for(int u = 0; u < N; u++){
            if(!visited[u] && (v == -1 || dist[u] < dist[v]))   v = u;
        }

        if(v == -1)     break;
        visited[v] = true;
        asw += dist[v];
        for(int u = 0; u < N; u++){
            dist[u] = min(dist[u], G[v][u]);
        }
    }
    return asw;
}

int main()
{
    while(scanf("%d", &N) != EOF){
        G.resize(N, vector<int>(N, INF));
        dist.resize(N, INF);
        visited.resize(N, false);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d", &G[i][j]);
            }
        }
        printf("%d\n", Prim());
        G.clear();
        dist.clear();
        visited.clear();
    }

    return 0;
}
