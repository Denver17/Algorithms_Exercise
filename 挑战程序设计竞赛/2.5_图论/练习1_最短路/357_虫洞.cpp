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

const int MAXN = 500 + 10;
const int INF = 0x3f3f3f3f;

typedef pair<int, int> P;

struct edge{
    int to, cost;
};

vector<edge> G[MAXN];
vector<int> dist(MAXN);

bool BellmanFord(int s, int N){
    fill(dist.begin(), dist.end(), INF);
    dist[s] = 0;
    for(int i = 1; i <= N - 1; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 0; k < G[j].size(); k++){
                int v = G[j][k].to;
                if(dist[j] != INF && dist[j] + G[j][k].cost < dist[v])     dist[v] = dist[j] + G[j][k].cost;
            }
        }
    }

    //判断负环是否存在
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < G[i].size(); j++){
            int v = G[i][j].to;
            if(dist[i] != INF && dist[i] + G[i][j].cost < dist[v])    return true;
        }
    }
    return false;
}

int main()
{
    int F;  scanf("%d", &F);
    while(F--){
        for(int i = 0; i < MAXN; i++)   G[i].clear();
        int N, M, W;    scanf("%d %d %d", &N, &M, &W);
        for(int i = 0; i < M; i++){
            int S, E, T;    scanf("%d %d %d", &S, &E, &T);
            edge e1, e2;    
            e1.to = E;  e1.cost = T;
            e2.to = S;  e2.cost = T;
            //if(S == E)  continue;
            G[S].push_back(e1);
            G[E].push_back(e2);
        }
        for(int i = 0; i < W; i++){
            int S, E, T;    scanf("%d %d %d", &S, &E, &T);
            edge e;     e.to = E;   e.cost = -1 * T;
            //if(S == E)  continue;
            G[S].push_back(e);
        }
        if(BellmanFord(1, N))   cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
    }
    
    return 0;
}
