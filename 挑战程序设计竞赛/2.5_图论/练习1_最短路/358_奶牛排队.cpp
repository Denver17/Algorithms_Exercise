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

typedef pair<int, int> P;   //first代表最短距离,second代表编号

struct edge{
    int to, cost;
};

vector<edge> G[MAXN];
vector<int> dist(MAXN);

void dijkstra(int s){
    fill(dist.begin(), dist.end(), INF);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0, s));
    while(!que.empty()){
        P temp = que.top();     que.pop();
        int d = temp.first, u = temp.second;
        if(d != dist[u])    continue;
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
    int N, M, X;    scanf("%d %d %d", &N, &M, &X);
    for(int i = 0; i < M; i++){
        int A, B, T;    scanf("%d %d %d", &A, &B, &T);
        edge e;     e.to = B;   e.cost = T;
        G[A].push_back(e);
    }

    //每头牛回家的用时
    vector<int> party2home(N + 1);
    //每头牛从家到派对农场的用时
    vector<int> home2party(N + 1);

    dijkstra(X);

    for(int i = 1; i <= N; i++){
        party2home[i] = dist[i];
    }

    for(int i = 1; i <= N; i++){
        if(i != X){
            dijkstra(i);
            home2party[i] = dist[X];
        }
    }

    int asw, res = 0;
    for(int i = 1; i <= N; i++){
        if(i != X && party2home[i] + home2party[i] > res){
            res = party2home[i] + home2party[i];
            asw = i;
        }
    }
    
    cout<<res<<endl;

    return 0;
}
