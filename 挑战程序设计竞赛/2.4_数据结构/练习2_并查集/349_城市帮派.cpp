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

const int MAXN = 2 * 100000 + 10;

int par[MAXN];
int _rank[MAXN];

void init_union_find(){
    for(int i = 0; i < MAXN; i++){
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
}

bool same(int x, int y){
    return find(x) == find(y);
}

int main()
{
    int T;      cin>>T;
    while(T--){
        init_union_find();
        int N, M;   cin>>N>>M;
        for(int i = 0; i < M; i++){
            char c;
            int a, b;   cin>>c>>a>>b;
            if(c == 'D'){
                unite(a + N, b);
                unite(a, b + N);
            }
            else{
                if(same(a, b) || same(a + N, b + N))    cout<<"In the same gang."<<endl;
                else if(same(a, b + N) || same(a + N, b))   cout<<"In different gangs."<<endl;
                else    cout<<"Not sure yet."<<endl;
            }
        }
    }
    
    return 0;
}