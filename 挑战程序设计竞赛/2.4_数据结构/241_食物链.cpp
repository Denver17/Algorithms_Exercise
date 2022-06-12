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

const int MAX_N = 3 * 50000 + 10;

int par[MAX_N];
int myrank[MAX_N];    //树的高度

//初始化n个元素
void init(int n){
    for(int i = 0; i < n; i++){
        par[i] = i;
        myrank[i] = 0;
    }
}

//查询树的根
int find(int x){
    if(par[x] == x) return x;
    else    return par[x] = find(par[x]);
}

//合并x与y所属的集合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)  return ;

    if(myrank[x] < myrank[y])   par[x] = y;
    else{
        par[y] = x;
        if(myrank[x] == myrank[y])  myrank[x]++;
    }
}

//判断x和y是否属于同一个集合
bool same(int x, int y){
    return find(x) == find(y);
}

int main()
{
    int N, K;   cin>>N>>K;
    //元素x, x + N, x + 2 * N分别代表x-A、x-B、x-C, 即x属于种类A或B或C
    init(N * 3);
    int asw = 0;
    for(int i = 0; i < K; i++){
        int t, x, y;    cin>>t>>x>>y;
        if(x > N || x < 1 || y > N || y < 1){
            asw++;
            continue;
        }
        if(t == 1){
            if(same(x, y + N) || same(x, y + 2 * N))    asw++;
            else{
                unite(x, y);
                unite(x + N, y + N);
                unite(x + N * 2, y + N * 2);
            }
        }
        else{
            if(same(x, y) || same(x, y + N * 2))    asw++;
            else{
                unite(x, y + N);
                unite(x + N, y + N * 2);
                unite(x + 2 * N, y);
            }
        }
    }

    cout<<asw<<endl;

    return 0;
}
