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

const int INF = 0x3f3f3f3f;

typedef long long ll;

int N, S;

vector<ll> c;
vector<ll> y;

ll _min(ll a, ll b){
    return a > b ? b : a;
}

void solve(){
    ll asw = 0;
    asw += c[0] * y[0];
    for(int i = 1; i < N; i++){
        ll res = c[i] * y[i];
        for(int j = 0; j < i; j++){
            res = _min(res, c[j] * y[i] + (i - j) * S * y[i]);
        }
        asw += res;
    }
    printf("%lld\n", asw);
    return ;
}

int main()
{
    while(scanf("%d %d", &N, &S) != EOF){
        c.resize(N);
        y.resize(N);
        for(int i = 0; i < N; i++){
            scanf("%lld %lld", &c[i], &y[i]);
        }
        solve();
        c.clear();
        y.clear();
    }

    return 0;
}
