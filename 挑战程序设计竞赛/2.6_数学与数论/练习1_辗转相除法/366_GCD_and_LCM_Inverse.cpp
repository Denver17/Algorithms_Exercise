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

ll gcd(ll a, ll b){
    if(b == 0)  return a;
    else    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

void solve(ll c, ll d){
    ll res = c * d;
    ll asw1 = c, asw2 = d;
    for(int i = 1; i <= sqrt(res / c); i++){
        ll a = c * i;
        ll b = res / a;
        if(gcd(a, b) == c && lcm(a, b) == d){
            if(a + b < asw1 + asw2){
                asw1 = a;
                asw2 = b;
            }
        }
    }
    cout<<asw1<<" "<<asw2<<endl;
    return ;
}

int main()
{
    ll c, d;
    while(scanf("%lld %lld", &c, &d) != EOF){
        solve(c, d);
    }
    

    return 0;
}
