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

const int INF = 1e7 + 10;

struct cow{
    int ID, room;
    int s, t;
};

struct node{
    int id, _time;
};

vector<cow> vec;

bool cmp1(cow a, cow b){
    return a.s < b.s;
}

bool cmp2(cow a, cow b){
    return a.ID < b.ID;
}

struct cmp{
    bool operator()(const node& a, const node& b){
        return a._time > b._time;
    }
};

int main()
{
    int asw = 0;
    int n;  cin>>n;
    vec.resize(n);
    for(int i = 0; i < n; i++){
        int s, t;   cin>>s>>t;
        vec[i].s = s;   vec[i].t = t;
        vec[i].ID = i;
    }
    sort(vec.begin(), vec.end(), cmp1);
    priority_queue<node, vector<node>, cmp > que;
    int ptr = 0;
    vec[0].room = ++asw;
    que.push(node{asw, vec[ptr++].t});
    while(!que.empty()){
        while(ptr < vec.size() && vec[ptr].s <= que.top()._time){
            node temp;
            temp.id = ++asw;
            temp._time = vec[ptr].t;
            vec[ptr].room = asw;
            que.push(temp);
            ptr++;
        }
        if(ptr == vec.size())   break;
        while(ptr < vec.size() && !que.empty() && que.top()._time < vec[ptr].s){
            node temp = que.top();      que.pop();
            temp._time = vec[ptr].t;
            vec[ptr].room = temp.id;
            que.push(temp);
            ptr++;
        }
    }

    sort(vec.begin(), vec.end(), cmp2);
    cout<<asw<<endl;
    for(int i = 0; i < n; i++)  cout<<vec[i].room<<endl;
    return 0;
}
