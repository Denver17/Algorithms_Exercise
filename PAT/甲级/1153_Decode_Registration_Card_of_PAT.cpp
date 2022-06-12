#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;

struct student{
    string ID;
    char rank;
    int room;
    int date;
    int number;
    int score;
    int room_stu_num;
    student(){
        ID.resize(15);
    }
};

bool cmp1(student &a, student &b){
    if(a.score != b.score)  return a.score > b.score;
    return a.ID < b.ID;
}

bool cmp3(student &a, student &b){
    if(a.room_stu_num != b.room_stu_num)    return a.room_stu_num > b.room_stu_num;
    return a.room < b.room;
}

int main()
{
    int N, M;   scanf("%d %d", &N, &M);
    vector<student> stu(N);
    vector<student> asw1T;
    vector<student> asw1A;
    vector<student> asw1B;
    map<int, vector<student> > mp2;
    map<int, vector<student> > mp3;
    for(int i = 0; i < N; i++){
        scanf("%s %d", stu[i].ID.c_str(), &stu[i].score);
        stu[i].rank = stu[i].ID[0];
        stu[i].room = atoi(stu[i].ID.substr(1,3).c_str());
        stu[i].date = atoi(stu[i].ID.substr(4,6).c_str());
        stu[i].number = atoi(stu[i].ID.substr(10,3).c_str());
        
        if(stu[i].rank == 'T')  asw1T.push_back(stu[i]);
        else if(stu[i].rank == 'A') asw1A.push_back(stu[i]);
        else if(stu[i].rank == 'B') asw1B.push_back(stu[i]);
        mp2[stu[i].room].push_back(stu[i]);
        mp3[stu[i].date].push_back(stu[i]);
    }

    sort(asw1T.begin(), asw1T.end(), cmp1);
    sort(asw1A.begin(), asw1A.end(), cmp1);
    sort(asw1B.begin(), asw1B.end(), cmp1);

    for(int i = 0; i < M; i++){
        int num;    string c;   //c.resize(20);
        scanf("%d ", &num);
        cin>>c;
        if(num == 1){
            printf("Case %d: 1 %s\n", i + 1, c.c_str());
            if(c.compare("T") == 0){
                if(asw1T.size() == 0)   printf("NA\n");
                for(int j = 0; j < asw1T.size(); j++){
                    printf("%s %d\n", asw1T[j].ID.c_str(), asw1T[j].score);
                }
            }
            else if(c.compare("A") == 0){
                if(asw1A.size() == 0)   printf("NA\n");
                for(int j = 0; j < asw1A.size(); j++){
                    printf("%s %d\n", asw1A[j].ID.c_str(), asw1A[j].score);
                }
            }
            else if(c.compare("B") == 0){
                if(asw1B.size() == 0)   printf("NA\n");
                for(int j = 0; j < asw1B.size(); j++){
                    printf("%s %d\n", asw1B[j].ID.c_str(), asw1B[j].score);
                }
            }
            else    printf("NA\n");
        }
        else if(num == 2){
            printf("Case %d: 2 %s\n", i + 1, c.c_str());
            int sum = 0;
            int temp = atoi(c.c_str());
            if(mp2.count(temp) == 0){
                printf("NA\n");
                continue;
            }
            for(int j = 0; j < mp2[temp].size(); j++){
                sum += mp2[temp][j].score;
            }
            printf("%d %d\n", mp2[temp].size(), sum);
        }
        else if(num == 3){
            printf("Case %d: 3 %s\n", i + 1, c.c_str());
            int temp = atoi(c.c_str());
            if(mp3.count(temp) == 0){
                printf("NA\n");
                continue;
            }
            vector<student> vec = mp3[temp];
            unordered_map<int, vector<student> > mptmp;
            for(int j = 0; j < vec.size(); j++){
                mptmp[vec[j].room].push_back(vec[j]);
            }
            for(int j = 0; j < vec.size(); j++){
                vec[j].room_stu_num = mptmp[vec[j].room].size();
            }

            sort(vec.begin(), vec.end(), cmp3);
            printf("%d %d\n", vec[0].room, vec[0].room_stu_num);
            for(int j = 1; j < vec.size(); j++){
                if(vec[j].room == vec[j - 1].room)  continue;
                else{
                    printf("%d %d\n", vec[j].room, vec[j].room_stu_num);
                }
            }
        }
        else printf("NA\n");
    }

    return 0;
}

