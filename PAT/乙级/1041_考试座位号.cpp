#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

struct student{
    string id;
    int first_num;
    int second_num;
}stu[1000];

int N;

void get_num(int num){
    for(int i = 0; i < N; i++){
        if(num == stu[i].first_num){
            cout<<stu[i].id<<" "<<stu[i].second_num<<endl;
        }
    }
    return ;
}


int main()
{
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>stu[i].id>>stu[i].first_num>>stu[i].second_num;
    }
    int M;
    cin>>M;
    for(int i = 0; i < M; i++){
        int num;
        cin>>num;
        get_num(num);
    }

    return 0;
}
