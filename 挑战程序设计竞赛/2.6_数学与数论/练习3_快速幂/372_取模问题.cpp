//注意将mod作为单独参数，使用p直接模结果错了
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

ll quickmod(ll a, ll p, ll mod){
    if(p == 0)  return 1;
    else if(p % 2 == 1)     return (quickmod(a, p - 1, mod) * a) % mod;
    else{
        ll num = quickmod(a, p / 2, mod);
        return (num * num) % mod;
    }
}

bool isPrime(ll num){
    if(num < 2)    return false;
    for(ll i = 2; i <= sqrt(num); i++){
        if(num % i == 0)    return false;
    }
    return true;
}

void solve(ll a, ll p){
    if(isPrime(p)){
        cout<<"no"<<endl;
        return ;
    }
    if(quickmod(a, p, p) % p == a % p)     cout<<"yes"<<endl;
    else    cout<<"no"<<endl;
    return ;
}

int main()
{
    ll p, a;
    while(cin>>p>>a){
        if(p == 0 && a == 0)    break;
        solve(a, p);
    }
    

    return 0;
}