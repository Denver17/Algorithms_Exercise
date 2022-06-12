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

const ll MAXN = 4 * 100000 + 100;
ll n, m;
vector<ll> number;

ll tree[MAXN], mark[MAXN];

void build(ll l = 1, ll r = n, ll p = 1){
    //到达叶子结点
    if(l == r)  tree[p] = number[l];
    else{
        ll mid = (l + r) / 2;
        build(l, mid, p * 2);
        build(mid + 1, r, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }
}

inline void push_down(ll p, ll len){
    mark[p * 2] += mark[p];
    mark[p * 2 + 1] += mark[p];
    tree[p * 2] += mark[p] * (len - len / 2);
    tree[p * 2 + 1] += mark[p] * (len / 2);
    mark[p] = 0;    //清除lazy标记
}

//[l, r]表示目标区间,[cl, cr]表示当前结点区间,d表示需要添加的值
void update(ll l, ll r, ll d, ll p = 1, ll cl = 1, ll cr = n){
    //两个区间无交集
    if(cl > r || cr < l)    return ;
    //当前区间被目标区间包含
    else if(cl >= l && cr <= r){
        tree[p] += (cr - cl + 1) * d;
        //非叶子结点需要lazy标记
        if(cr > cl)     mark[p] += d;
    }    
    else{
        ll mid = (cl + cr) / 2;
        push_down(p, cr - cl + 1);
        update(l, r, d, p * 2, cl, mid);
        update(l, r, d, p * 2 + 1, mid + 1, cr);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }
}

ll query(ll l, ll r, ll p = 1, ll cl = 1, ll cr = n){
    if(cl > r || cr < l)    return 0;
    else if(cl >= l && cr <= r)     return tree[p];
    else{
        ll mid = (cl + cr) / 2;
        push_down(p, cr - cl + 1);
        return query(l, r, p * 2, cl, mid) + query(l, r, p * 2 + 1, mid + 1, cr);
    }
}

int main()
{
    cin>>n>>m;
    number.resize(n + 1);
    for(int i = 1; i <= n; i++)  cin>>number[i];
    build(1, n, 1);
    for(int k = 0; k < m; k++){
        int num;    cin>>num;
        if(num == 1){
            ll x, y, d;    cin>>x>>y>>d;
            update(x, y, d, 1, 1, n);
        }
        else{
            ll x, y;   cin>>x>>y;
            cout<<query(x, y, 1, 1, n)<<endl;
        }
    }

    return 0;
}