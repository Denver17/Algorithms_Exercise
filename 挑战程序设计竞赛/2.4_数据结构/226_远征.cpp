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
    return a.first > b.first;
}

int main()
{
    int asw = 0;
    int N;  cin>>N;
    vector<pair<int, int> > station(N);
    priority_queue<int> que;
    for(int i = 0; i < N; i++){
        cin>>station[i].first>>station[i].second;
    }
    int L, P;   cin>>L>>P;

    pair<int, int> temp;    temp.first = 0;     temp.second = 0;
    station.push_back(temp);
    N++;

    sort(station.begin(), station.end(), cmp);
    
    int pos = 0;
    for(int i = 0; i < N; i++){
        int d = L - station[i].first - pos;
        while(P - d < 0){
            if(que.empty()){
                cout<<-1<<endl;
                return 0;
            }
            P += que.top();
            que.pop();
            asw++;
        }

        P -= d;
        pos = L - station[i].first;
        que.push(station[i].second);
    }

    cout<<asw<<endl;
    
    return 0;
}
