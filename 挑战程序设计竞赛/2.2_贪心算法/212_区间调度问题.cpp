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
    if(a.second != b.second)    return a.second < b.second;
    else    return a.first < b.first;
}


int main()
{
    int n;
    while(cin>>n){
        vector<pair<int, int> > work_time;
        for(int i = 0; i < n; i++){
            int t_start, t_end;
            cin>>t_start>>t_end;
            pair<int, int> temp;
            temp.first = t_start;
            temp.second = t_end;
            work_time.push_back(temp);
        }
        sort(work_time.begin(), work_time.end(), cmp);
        int asw = 0;
        int last_time = 0;
        for(int i = 0; i < n; i++){
            if(work_time[i].first > last_time){
                asw++;
                last_time = work_time[i].second;
            }
        }
        cout<<asw<<endl;
    }
    

    return 0;
}
