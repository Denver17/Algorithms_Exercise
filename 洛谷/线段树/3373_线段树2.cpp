#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<stdlib.h>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const ll MAXN = 4 * 100000 + 100;

ll n, m, mod;

vector<ll> number;

ll tree[MAXN], markadd[MAXN], markmul[MAXN];

void build(ll l = 1, ll r = n, ll p = 1){
    if(l == r)  tree[p] = number[l];
    else{
        ll mid = (l + r) / 2;
        build(l, mid, p * 2);
        build(mid + 1, r, p * 2 + 1);
        tree[p] = (tree[p * 2] + tree[p * 2 + 1]) % mod;
    }
}

inline void push_down(ll p, ll len){
    tree[p * 2] = (tree[p * 2] * markmul[p] + ((len - len / 2) * markadd[p]) % mod) % mod;
    tree[p * 2 + 1] = (tree[p * 2 + 1] * markmul[p] + ((len / 2) * markadd[p]) % mod) % mod;

    markmul[p * 2] = (markmul[p * 2] * markmul[p]) % mod;
    markmul[p * 2 + 1] = (markmul[p * 2 + 1] * markmul[p]) % mod;

    markadd[p * 2] = (markadd[p * 2] * markmul[p] + markadd[p]) % mod;
    markadd[p * 2 + 1] = (markadd[p * 2 + 1] * markmul[p] + markadd[p]) % mod;

    markadd[p] = 0;
    markmul[p] = 1;
}

void add(ll l, ll r, ll d, ll p = 1, ll cl = 1, ll cr = n){
    if(cl > r || cr < l)    return ;
    else if(cl >= l && cr <= r){
        tree[p] = (tree[p] + (cr - cl + 1) * d) % mod;
        markadd[p] = (markadd[p] + d) % mod;
    }
    else{
        ll mid = (cl + cr) / 2;
        push_down(p, cr - cl + 1);
        add(l, r, d, p * 2, cl, mid);
        add(l, r, d, p * 2 + 1, mid + 1, cr);
        tree[p] = (tree[p * 2] + tree[p * 2 + 1]) % mod;
    }
}

void mul(ll l, ll r, ll x, ll p = 1, ll cl = 1, ll cr = n){
    if(cl > r || cr < l)    return ;
    else if(cl >= l && cr <= r){
        markadd[p] = (markadd[p] * x) % mod;    //重要步骤
        markmul[p] = (markmul[p] * x) % mod;
        tree[p] = (tree[p] * x) % mod;
    }
    else{
        ll mid = (cl + cr) / 2;
        push_down(p, cr - cl + 1);
        mul(l, r, x, p * 2, cl, mid);
        mul(l, r, x, p * 2 + 1, mid + 1, cr);
        tree[p] = (tree[p * 2] + tree[p * 2 + 1]) % mod;
    }
}

ll query(ll l, ll r, ll p = 1, ll cl = 1, ll cr = n){
    if(cl > r || cr < l)    return 0;
    else if(cl >= l && cr <= r)     return tree[p] % mod;
    else{
        ll mid = (cl + cr) / 2;
        push_down(p, cr - cl + 1);
        return (query(l, r, p * 2, cl, mid) + query(l, r, p * 2 + 1, mid + 1, cr)) % mod;
    }
}

int main()
{
    for(int i = 0; i < MAXN; i++)   markmul[i] = 1;
    cin>>n>>m>>mod;
    number.resize(n + 1);
    for(int i = 1; i <= n; i++)  cin>>number[i];
    build(1, n, 1);
    for(int k = 0; k < m; k++){
        int num;    cin>>num;
        if(num == 1){
            int x, y, k;    cin>>x>>y>>k;
            mul(x, y, k, 1, 1, n);
        }
        else if(num == 2){
            int x, y, k;    cin>>x>>y>>k;
            add(x, y, k, 1, 1, n);
        }
        else{
            int x, y;   cin>>x>>y;
            cout<<query(x, y, 1, 1, n) % mod<<endl;
        }
    }

    return 0;
}