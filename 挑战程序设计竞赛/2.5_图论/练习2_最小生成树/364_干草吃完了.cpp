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

const int MAXE = 10000 + 10;

struct edge{
    int u, v, cost;
};

vector<edge> es;

bool cmp(edge& e1, edge& e2){
    return e1.cost < e2.cost;
}

int N, M;

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
    if(x == par[x])     return x;
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
    int res = 0;
    init_union_find(N);
    for(int i = 0; i < es.size(); i++){
        edge e = es[i];
        if(same(e.u, e.v) == false){
            unite(e.u, e.v);
            if(e.cost > res)    res = e.cost;
        }
    }
    return res;
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        int A, B, L;    scanf("%d %d %d", &A, &B, &L);
        edge e1, e2;
        e1.u = A;   e1.v = B;   e1.cost = L;
        e2.u = B;   e2.v = A;   e2.cost = L;
        es.push_back(e1);
        es.push_back(e2);
    }
    int asw = Kruskal();
    printf("%d\n", asw);
    return 0;
}
