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

int N;
vector<pair<ll, ll> > vec;

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    return a.first * b.second < a.second * b.first;
}

int main()
{
    cin>>N;
    vec.resize(N);
    for(int i = 0; i < N; i++)  cin>>vec[i].first>>vec[i].second;
    sort(vec.begin(), vec.end(), cmp);
    ll asw = 0;
    vector<ll> sum(N, 0);
    sum[N - 1] = vec[N - 1].second;
    for(int i = N - 2; i >= 0; i--){
        sum[i] = sum[i + 1] + vec[i].second;
    }
    for(int i = 0; i < N - 1; i++){
        asw += 2 * vec[i].first * sum[i + 1];
    }
    cout<<asw<<endl;

    return 0;
}