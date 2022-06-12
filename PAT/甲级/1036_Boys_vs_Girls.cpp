#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct student{
    string name;
    string id;
    char gender;
    int grade;
};

bool cmp1(student a,student b){
    if(a.grade != b.grade)  return a.grade < b.grade;
}

bool cmp2(student a,student b){
    if(a.grade != b.grade)  return a.grade > b.grade;
}

int main()
{
    int N;  cin>>N;
    student stu[N];
    vector<student> male;
    vector<student> female;
    for(int i = 0; i < N; i++){
        cin>>stu[i].name>>stu[i].gender>>stu[i].id>>stu[i].grade;
        if(stu[i].gender == 'M'){
            male.push_back(stu[i]);
        }
        else if(stu[i].gender == 'F'){
            female.push_back(stu[i]);
        }
    }

    sort(male.begin(),male.end(),cmp1);

    sort(female.begin(),female.end(),cmp2);

    if(female.size() == 0)    cout<<"Absent"<<endl;
    else    cout<<female[0].name<<" "<<female[0].id<<endl;

    if(male.size() == 0)    cout<<"Absent"<<endl;
    else cout<<male[0].name<<" "<<male[0].id<<endl;
    
    if(male.size() == 0 || female.size() == 0)  cout<<"NA";
    else    cout<<abs(female[0].grade-male[0].grade);


    return 0;
}

