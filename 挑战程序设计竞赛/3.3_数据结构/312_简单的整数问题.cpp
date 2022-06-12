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

typedef long long ll;

const int MAXN = 4 * 100000 + 100;

struct node{
    ll sum, lazy;
    int l, r;
}tree[MAXN];

int N, M;
int vec[MAXN];

void build(ll l = 1, ll r = N, ll p = 1){
    if(l == r)  tree[p].sum = vec[l];
    else{
        ll mid = (l + r) / 2;
        build(l, mid, p * 2);
        build(mid + 1, r, p * 2 + 1);
        tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
    }
}

inline void push_down(ll p, ll len){
    tree[p * 2].lazy += tree[p].lazy;
    tree[p * 2 + 1].lazy += tree[p].lazy;
    tree[p * 2].sum += tree[p].lazy * (len - len / 2);
    tree[p * 2 + 1].sum += tree[p].lazy * (len / 2);
    tree[p].lazy = 0;
}

void add(ll l, ll r, ll d, ll p = 1, ll cl = 1, ll cr = N){
    if(cl > r || cr < l)    return ;
    else if(cl >= l && cr <= r){
        tree[p].sum += (cr - cl + 1) * d;
        if(cr > cl)     tree[p].lazy += d;
    }
    else{
        ll mid = (cl + cr) / 2;
        push_down(p, cr - cl + 1);
        add(l, r, d, p * 2, cl, mid);
        add(l, r, d, p * 2 + 1, mid + 1, cr);
        tree[p].sum = tree[p * 2].sum + tree[p * 2 + 1].sum;
    }
}

ll query(ll l, ll r, ll p = 1, ll cl = 1, ll cr = N){
    if(cl > r || cr < l)    return 0;
    else if(cl >= l && cr <= r)     return tree[p].sum;
    else{
        ll mid = (cl + cr) / 2;
        push_down(p, cr - cl + 1);
        return query(l, r, p * 2, cl, mid) + query(l, r, p * 2 + 1, mid + 1, cr);
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)  scanf("%d", &vec[i]);
    build(1, N, 1);
    for(int i = 0; i < M; i++){
        char c;     cin>>c;
        if(c == 'C'){
            int l, r, x;    scanf("%d %d %d", &l, &r, &x);
            add(l, r, x, 1, 1, N);
        }
        else{
            int l, r;       scanf("%d %d", &l, &r);
            printf("%lld\n", query(l, r, 1, 1, N));
        }
    }  

    return 0;
}