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

int N, M;

typedef pair<int, int> P;

const int MAXE = 2 * 100000 + 10;

struct edge{
    int u, v, cost;
};

vector<edge> es;

int par[MAXE];
int _rank[MAXE];

void inint_union_find(){
    for(int i = 0; i < MAXE; i++){
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

bool cmp(edge& a, edge& b){
    return a.cost < b.cost;
}

void Kruskal(){
    sort(es.begin(), es.end(), cmp);
    inint_union_find();
    int asw = 0;
    for(int i = 0; i < es.size(); i++){
        edge e = es[i];
        if(same(e.u, e.v) == false){
            unite(e.u, e.v);
            asw += e.cost;
        }
    }
    int v1 = es[0].u;
    for(int i = 1; i <= N; i++){
        if(same(i, v1) == false){
            cout<<"orz"<<endl;
            return ;
        }
    }
    cout<<asw<<endl;
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        int X, Y, Z;    scanf("%d %d %d", &X, &Y, &Z);
        es.push_back(edge{X, Y, Z});
        es.push_back(edge{Y, X, Z});
    }

    Kruskal();
    

    return 0;
}