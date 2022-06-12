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

const int MAXN = 45;

int n;
ll W;
vector<ll> w(MAXN), v(MAXN);

vector<pair<ll, ll> > ps(1 << (MAXN / 2));

void solve(){
    int n2 = n / 2;
    for(int i = 0; i < (1 << n2); i++){
        ll sw = 0, sv = 0;
        for(int j = 0; j < n2; j++){
            if((i >> j) & 1){
                sw += w[j];
                sv += v[j];
            }
        }
        ps[i] = make_pair(sw, sv);
    }

    //去除多余元素
    sort(ps.begin(), ps.begin() + (1 << n2));
    int m = 1;
    for(int i = 1; i < (1 << n2); i++){
        if(ps[m - 1].second < ps[i].second){
            ps[m++] = ps[i];
        }
    }

    //枚举后半部分并求解
    ll asw = 0;
    for(int i = 0; i < (1 << (n - n2)); i++){
        ll sw = 0, sv = 0;
        for(int j = 0; j < n - n2; j++){
            if((i >> j) & 1){
                sw += w[n2 + j];
                sv += v[n2 + j];
            }
        }
        if(sw <= W){
            int left = -1, right = m;
            while(left < right - 1){
                int mid = left + (right - left) / 2;
                if(ps[mid].first <= W - sw) left = mid;
                else    right = mid;
            }
            if(left == -1)  continue;
            asw = max(asw, sv + ps[left].second);
        }
    }
    cout<<asw<<endl;
}

int main()
{
    cin>>n>>W;
    for(int i = 0; i < n; i++)  cin>>w[i];
    for(int i = 0; i < n; i++)  cin>>v[i];
    solve();

    return 0;
}
