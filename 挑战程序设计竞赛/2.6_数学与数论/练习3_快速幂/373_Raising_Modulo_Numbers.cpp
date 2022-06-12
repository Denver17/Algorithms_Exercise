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
typedef pair<ll, ll> P;

int M, H;

ll quickmod(ll a, ll b, ll mod){
    if(b == 0)  return 1;
    else if(b % 2 == 1) return (quickmod(a, b - 1, mod) * a) % mod;
    else{
        ll num = quickmod(a, b / 2, mod) % mod;
        return (num * num) % mod;
    }
}

void solve(vector<P>& vec){
    ll asw = 0;
    for(int i = 0; i < H; i++){
        asw = (asw + quickmod(vec[i].first, vec[i].second, M)) % M;
    }
    cout<<asw<<endl;
    return ;
}

int main()
{
    int Z;      cin>>Z;
    while(Z--){
        cin>>M>>H;
        vector<P> vec;
        for(int i = 0; i < H; i++){
            ll A, B;   cin>>A>>B;
            vec.push_back(P(A, B));
        }
        solve(vec);
    }
    

    return 0;
}