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

int main()
{
    ll a, b;
    while(scanf("%lld %lld", &a, &b) != EOF){
        cout<<gcd(a, b)<<" "<<a * b / gcd(a, b)<<endl;
    }

    return 0;
}