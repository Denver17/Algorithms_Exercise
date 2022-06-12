#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct student{
    string name;
    string id;
    int grade;
};

vector<student> stu;

bool cmp(student a,student b){
    if(a.grade != b.grade)  return a.grade > b.grade;
}

int main()
{
    int N;
    cin>>N;
    stu.resize(N);
    for(int i = 0; i < N; i++){
        cin>>stu[i].name>>stu[i].id>>stu[i].grade;
    }

    int grade1,grade2;
    cin>>grade1>>grade2;

    vector<student> asw;
    for(int i = 0; i < stu.size(); i++){
        if(stu[i].grade <= grade2 && stu[i].grade >= grade1)
            asw.push_back(stu[i]);
    }
    
    if(asw.size() == 0) { printf("NONE");   return 0;}
    
    sort(asw.begin(),asw.end(),cmp);

    for(int i = 0; i < asw.size(); i++){
        printf("%s %s\n",asw[i].name.c_str(),asw[i].id.c_str());
    }

    return 0;
}

