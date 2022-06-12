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

const int MAXE = 50000 + 10;

struct edge{
    int u, v, cost;
};

bool cmp(edge& e1, edge& e2){
    return e1.cost < e2.cost;
}

vector<edge> es;
int V, E;

int par[MAXE];
int _rank[MAXE];

void init_union_find(int n){
    for(int i = 0; i < n; i++){
        par[i] = i;
        _rank[i] = 0;
    }
    return ;
}

int find(int x){
    if(par[x] == x)     return x;
    else    return par[x] = find(par[x]);
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)  return ;

    if(_rank[x] < _rank[y])   par[x] = y;
    else{
        par[y] = x;
        if(_rank[x] == _rank[y])  _rank[x]++;
    }
    return ;
}

bool same(int x, int y){
    return find(x) == find(y);
}

int Kruskal(){
    sort(es.begin(), es.end(), cmp);
    init_union_find(V);
    int res = 0;
    for(int i = 0; i < E; i++){
        edge e = es[i];
        if(!same(e.u, e.v)){
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int main()
{
    int T;  scanf("%d", &T);
    while(T--){
        int N, M, R;    scanf("%d %d %d", &N, &M, &R);
        V = N + M;
        E = R;
        for(int i = 0; i < E; i++){
            int x, y, d;    scanf("%d %d %d", &x, &y, &d);
            edge e1; 
            e1.u = x;   e1.v = y + N;   e1.cost = -1 * d;
            es.push_back(e1);
        }
        int asw = Kruskal();
        printf("%d\n", 10000 * V + asw);
        es.clear();
    }
    

    return 0;
}
