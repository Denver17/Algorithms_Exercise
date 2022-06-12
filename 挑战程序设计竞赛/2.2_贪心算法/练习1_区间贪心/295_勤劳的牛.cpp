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

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first)  return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    int asw = 0;
    int n, T;   cin>>n>>T;
    vector<pair<int, int> > vec(n);
    for(int i = 0; i < n; i++){
        cin>>vec[i].first>>vec[i].second;
    }
    sort(vec.begin(), vec.end(), cmp);

    int left = 0, ptr = 0;
    while(left < T && ptr < vec.size()){
        asw++;
        int right = left;
        if(vec[ptr].first > left + 1)   break;
        while(ptr < vec.size() && vec[ptr].first <= left + 1){
            right = max(right, vec[ptr].second);
            ptr++;
        }
        left = right;
    }
    
    if(left >= T)  cout<<asw<<endl;
    else    cout<<-1<<endl;

    return 0;
}
