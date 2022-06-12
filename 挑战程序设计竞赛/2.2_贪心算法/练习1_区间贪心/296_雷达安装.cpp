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

const int INF = -0x3f3f3f3f;

typedef pair<int, int> P;

int n, d;

vector<P> vec;

bool cmp(P a, P b){
    return a.second < b.second;
}

void solve(int id){
    vector<P> res(n);
    for(int i = 0; i < vec.size(); i++){
        int x = vec[i].first, y = vec[i].second;
        if(y > d){
            cout<<"Case "<<id<<": "<<-1<<endl;
            return ;
        }
        res[i].first = x - (int)(sqrt(d * d - y * y));
        res[i].second = x + (int)(sqrt(d * d - y * y));
    }
    sort(res.begin(), res.end(), cmp);
    int asw = 0, ptr = 0, right = INF;
    while(ptr < res.size()){
        if(res[ptr].first > right){
            right = res[ptr].second;
            asw++;
        }
        ptr++;
    }
    cout<<"Case "<<id<<": "<<asw<<endl;
    return ;
}

int main()
{
    int ptr = 0;
    while(cin>>n>>d){
        if(n == 0 && d == 0)    break;
        vec.resize(n);
        for(int i = 0; i < n; i++){
            int x, y;   cin>>x>>y;
            vec[i] = P(x, y);
        }
        solve(ptr + 1);
        vec.clear();
        ptr++;
    }
    

    return 0;
}
