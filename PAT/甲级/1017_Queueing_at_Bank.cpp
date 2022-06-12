//本题有大病，不做了
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int timetosec(int hh, int mm, int ss){
    return hh * 3600 + mm * 60 + ss;
}

struct student{
    int h, m, s;
    int arrive;
    int process;
    int waiting;
    student(){
        waiting = 0;
    }
};

bool cmp(student a, student b){
    if(a.arrive != b.arrive)    return a.arrive < b.arrive;
}

int main()
{
    int N, K;   scanf("%d %d", &N, &K);
    vector<student> vec(N);
    for(int i = 0; i < N; i++){
        int hh, mm, ss;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &vec[i].process);
        vec[i].arrive = timetosec(hh, mm, ss);
        vec[i].h = hh;  vec[i].m = mm;  vec[i].s = ss;
    }

    sort(vec.begin(), vec.end(), cmp);
    
    queue<student> stu;
    for(int i = 0; i < vec.size(); i++){
        int hh = 17, mm = 00, ss = 00;
        int late = timetosec(hh, mm ,ss);
        if(vec[i].arrive > late){
            vec.erase(vec.begin() + i, vec.end());
            break;
        }
        stu.push(vec[i]);
    }

    vector<student> asw;

    //queue<student> wait_stu;
    vector<student> wait_stu;
    int start = timetosec(vec[0].h, vec[0].m, vec[0].s);
    int end = timetosec(vec.back().h, vec.back().m, vec.back().s);
    int open = timetosec(8, 0, 0);
    int close = timetosec(17, 0, 0);
    int peak = timetosec(1, 0, 0);
    int _max = timetosec(15, 0, 0);
    vector<student> service;
    for(int i = start; i <= close; i++){
        if(!stu.empty() && i == stu.front().arrive){
            wait_stu.push_back(stu.front());
            stu.pop();
        }

        if(i >= open){
            while(service.size() < K && wait_stu.size() != 0){
                service.push_back(wait_stu[0]);
                wait_stu.erase(wait_stu.begin(), wait_stu.begin() + 1);
            }
        }
        for(int j = 0; j < wait_stu.size(); j++)    wait_stu[j].waiting++;

        for(int j = 0; j < service.size(); j++){
            if(i - service[j].arrive - service[j].waiting == peak){
                asw.push_back(service[j]);
                service.erase(service.begin() + j, service.begin() + j + 1);
            }
            else if(i - service[j].arrive - service[j].waiting == service[j].process * 60){
                asw.push_back(service[j]);
                service.erase(service.begin() + j, service.begin() + j + 1);
            }
        }
    }

    if(asw.size() == 0){
        printf("0.0\n");
        return 0;
    }
    double average = 0;
    for(int i = 0; i < asw.size(); i++) average += asw[i].waiting;
    average = average / 60;
    printf("%.1f", average / asw.size());


    return 0;
}

