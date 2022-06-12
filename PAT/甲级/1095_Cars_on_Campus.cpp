#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<cstring>
using namespace std;

struct car{
    char ID[8];
    int time;
    char status[4];
};

vector<car> all;
vector<car> valid;
map<string, int> parkTime;

int get_time(int hh, int mm, int ss){
    return hh * 3600 + mm * 60 + ss;
}

bool cmp1(car a, car b){
    if(strcmp(a.ID, b.ID) != 0) return strcmp(a.ID, b.ID) < 0;
    else    return a.time < b.time;
}

bool cmp2(car a, car b){
    return a.time < b.time;
}

int main()
{
    int N, K;    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++){
        car temp;
        int hh, mm, ss;
        scanf("%s %d:%d:%d %s", &temp.ID, &hh, &mm, &ss, &temp.status);
        temp.time = get_time(hh, mm, ss);
        all.push_back(temp);
    }

    sort(all.begin(), all.end(), cmp1);
    int maxTime = -1;
    for(int i = 0; i < N - 1; i++){
        if( strcmp(all[i].ID, all[i + 1].ID) == 0 &&
            strcmp(all[i].status, "in") == 0 &&
            strcmp(all[i + 1].status, "out") == 0){
                valid.push_back(all[i]);
                valid.push_back(all[i + 1]);
                int inTime = all[i + 1].time - all[i].time;
                if(parkTime.count(all[i].ID) == 0)  parkTime[all[i].ID] = 0;
                parkTime[all[i].ID] += inTime;
                maxTime = max(maxTime, parkTime[all[i].ID]);
        }
    }
    sort(valid.begin(), valid.end(), cmp2);

    int now = 0, curNum = 0;
    for(int i = 0; i < K; i++){
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int time = get_time(hh, mm, ss);
        while(now < valid.size() && valid[now].time <= time){
            if(strcmp(valid[now].status, "in") == 0)    curNum++;
            else    curNum--;
            now++;
        }
        printf("%d\n", curNum);
    }

    map<string, int>::iterator it;
    for(it = parkTime.begin(); it != parkTime.end(); it++){
        if(it->second == maxTime){
            printf("%s ", it->first.c_str());
        }
    }

    printf("%02d:%02d:%02d\n", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);

    return 0;
}

