#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int N,M,K;  //N是学生总数,M是学校总数,K是学生可选学校数

struct student{
    int id;
    int GE,GI;
    int sum;
    vector<int> choices;
    int rank;
}stu[40000];

struct school{
    int quota;
    int cur_num;
    vector<student> accept;
    school(){
        quota = 0;
        cur_num = 0;
    }
}sch[100];

bool cmp(student &a,student &b){
    if(a.sum != b.sum)  return a.sum > b.sum;
    else if(a.GE != b.GE)   return a.GE > b.GE;
}

bool cmp2(student &a,student &b){
    if(a.id != b.id)    return a.id < b.id;
}

int main()
{
    scanf("%d%d%d",&N,&M,&K);
    for(int i = 0; i < M; i++)  scanf("%d",&sch[i].quota);
    for(int i = 0; i < N; i++){
        scanf("%d%d",&stu[i].GE,&stu[i].GI);
        stu[i].sum = stu[i].GE + stu[i].GI;
        stu[i].choices.resize(K);
        stu[i].id = i;
        for(int j = 0; j < K; j++)  scanf("%d",&stu[i].choices[j]);
    }
    sort(stu,stu+N,cmp);
    int num = 1;
    stu[0].rank = num;
    for(int i = 1; i < N; i++){
        if(stu[i].sum == stu[i-1].sum && stu[i].GE == stu[i-1].GE){
            stu[i].rank = num; 
        }else{
            stu[i].rank = i + 1;
            num = i + 1;
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            int school_id = stu[i].choices[j];
            if(sch[school_id].cur_num < sch[school_id].quota || 
            sch[school_id].accept.back().rank == stu[i].rank){
                sch[school_id].accept.emplace_back(stu[i]);
                sch[school_id].cur_num++;
                break;
            }
        }
    }
    for(int i = 0; i < M; i++){
        if(sch[i].accept.size() == 0)   printf("\n");
        else{
            sort(sch[i].accept.begin(),sch[i].accept.end(),cmp2);
            printf("%d",sch[i].accept[0].id);
            for(int j = 1; j < sch[i].accept.size(); j++){
                printf(" %d",sch[i].accept[j].id);
            }
            printf("\n");
        }
    }

    return 0;
}

