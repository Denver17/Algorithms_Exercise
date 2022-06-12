#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct student{
    int id;
    string name;
    int grade;
}stu[100000];

bool cmp1(student a,student b){
    if( a.id != b.id )  return a.id < b.id; 
}

bool cmp2(student a,student b){
    if(a.name != b.name )   return a.name < b.name;
    else if( a.id != b.id ) return a.id < b.id;
}

bool cmp3(student a,student b){
    if(a.grade != b.grade)  return a.grade < b.grade;
    else if(a.id != b.id)   return a.id < b.id;
}

int main()
{
    int N,C;
    cin>>N>>C;
    for(int i = 0; i < N; i++){
        cin>>stu[i].id>>stu[i].name>>stu[i].grade;
    }
    if(C == 1){
        sort(stu,stu+N,cmp1);
    }
    else if(C == 2){
        sort(stu,stu+N,cmp2);
    }
    else if(C == 3){
        sort(stu,stu+N,cmp3);
    }

    for(int i = 0; i < N; i++){
        printf("%06d %s %d\n",stu[i].id,stu[i].name.c_str(),stu[i].grade);
    }

    return 0;
}


