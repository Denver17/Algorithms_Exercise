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

const int MAXE = 2 * 100000 + 10;

struct edge{
    int u, v;
    double cost;
};

typedef pair<int, int> P;

int N, M;
vector<P> vec(1);   //从1开始编号
vector<edge> es;

bool cmp(edge& e1, edge& e2){
    return e1.cost < e2.cost;
}

int par[MAXE];
int _rank[MAXE];

void init_union_find(int N){
    for(int i = 0; i < N; i++){
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

double Kruskal(){
    sort(es.begin(), es.end(), cmp);
    init_union_find(N);
    double res = 0;
    for(int i = 0; i < es.size(); i++){
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
    double sum = 0;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        int x, y;   scanf("%d %d", &x, &y);
        vec.push_back(P(x, y));
    }
    for(int i = 0; i < M; i++){
        int p, q;   scanf("%d %d", &p, &q);
        double dis = sqrt((vec[p].first - vec[q].first) * (vec[p].first - vec[q].first)+ 
        (vec[p].second - vec[q].second) * (vec[p].second - vec[q].second));
        edge e1, e2;
        e1.u = p;   e1.v = q;   e1.cost = -1 * dis;
        e1.u = q;   e1.v = p;   e1.cost = -1 * dis;
        es.push_back(e1);
        es.push_back(e2);
        sum += dis;
    }
    double asw = Kruskal();
    printf("%f\n", sum + asw);
    return 0;
}
