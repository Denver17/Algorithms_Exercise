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

struct cow{
    int minSPF, maxSPF;
};

struct sunscreen{
    int cnt, SPF;
};

bool cmp1(sunscreen a, sunscreen b){
    return a.SPF < b.SPF;
}

bool cmp2(cow a, cow b){
    return a.minSPF < b.minSPF;
}

int main()
{
    int C, L;   cin>>C>>L;
    int asw = 0;
    vector<cow> vec(C);
    vector<sunscreen> S(L);
    for(int i = 0; i < C; i++){
        cin>>vec[i].minSPF>>vec[i].maxSPF;
    }
    for(int i = 0; i < L; i++){
        cin>>S[i].SPF>>S[i].cnt;
    }
    sort(S.begin(), S.end(), cmp1);
    sort(vec.begin(), vec.end(), cmp2);
    priority_queue<int, vector<int>, greater<int> >   que;
    int ptr = 0;
    for(int i = 0; i < L; i++){
        while(ptr < C && vec[ptr].minSPF <= S[i].SPF){
            que.push(vec[ptr].maxSPF);
            ptr++;
        }
        while(!que.empty() && S[i].cnt != 0){
            int x = que.top();  que.pop();
            if(x < S[i].SPF)     continue;
            asw++;
            S[i].cnt--;
        }
    }
    cout<<asw<<endl;

    return 0;
}