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

const int MAXN = 1000 + 10;

typedef pair<double, double> P;

int N;
double d;

int par[MAXN];
int _rank[MAXN];
vector<bool> isNormal(MAXN, false);

void init(){
    for(int i = 0; i < MAXN; i++){
        par[i] = i;
        _rank[i] = 0;
    }
}

int find(int x){
    if(par[x] == x)     return x;
    else    return par[x] = find(par[x]);
}

void union_set(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)  return ;
    else{
        if(_rank[x] < _rank[y]){
            par[x] = y;
        }
        else{
            par[y] = x;
            if(_rank[x] == _rank[y])  _rank[x]++;
        }
    }
    return ;
}

bool same(int x, int y){
    return  find(x) == find(y);
}

int main()
{
    cin>>N>>d;
    vector<P> vec(N + 1);
    for(int i = 1; i <= N; i++){
        cin>>vec[i].first>>vec[i].second;
    }
    
    init();
    char c;
    while(cin>>c){
        int p, q;
        if(c == 'O'){
            cin>>p;
            isNormal[p] = true;
            for(int i = 1; i <= N; i++){
                double dist = sqrt((vec[i].first - vec[p].first) * (vec[i].first - vec[p].first)
                + (vec[i].second - vec[p].second) * (vec[i].second - vec[p].second));
                if(dist <= d && isNormal[i] == true)   union_set(p, i);
            }
        }
        else{
            cin>>p>>q;
            if(same(p, q))  cout<<"SUCCESS"<<endl;
            else    cout<<"FAIL"<<endl;
        }
    }

    return 0;
}