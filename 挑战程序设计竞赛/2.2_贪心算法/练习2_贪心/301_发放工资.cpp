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

typedef pair<int, int> P;

bool cmp(P a, P b){
    return a.first > b.first;
}

int main()
{
    int N, C;   cin>>N>>C;
    vector<P> vec(N);
    for(int i = 0; i < N; i++){
        int v, b;   cin>>v>>b;
        vec[i].first = v;
        vec[i].second = b;
    }
    int asw = 0;
    sort(vec.begin(), vec.end(), cmp);
    int ptr = 0;
    while(ptr < vec.size()){
        if(vec[ptr].first >= C)     asw += vec[ptr].second;
        else    break;
    }
    while(ptr < vec.size()){
        int cur = ptr, sum = 0;
        while(cur < vec.size() && sum + vec[cur])
    }

    return 0;
}