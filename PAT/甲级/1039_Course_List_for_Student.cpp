#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct student{
    string name;
    vector<int> courses;
};

vector<student> stu;

void query(string str){
    int pos = (str[0] - 'A')*26*26*10 + (str[1] - 'A')*26*10 + 
            (str[2] - 'A')*10 + (str[3] - '0');
    printf("%s %d",str.c_str(),stu[pos].courses.size());
    sort(stu[pos].courses.begin(),stu[pos].courses.end());
    for(int i = 0; i < stu[pos].courses.size(); i++)    printf(" %d",stu[pos].courses[i]);
    printf("\n");
    return ;
}


int main()
{
    int N,K;    scanf("%d%d",&N,&K);
    int maxn = 26*26*26*10 + 10;
    stu.resize(maxn);
    for(int i = 0; i < K; i++){
        int id,num;     scanf("%d%d",&id,&num);
        for(int j = 0; j < num; j++){
            string str;  str.resize(10);    scanf("%s",str.c_str());
            int pos = (str[0] - 'A')*26*26*10 + (str[1] - 'A')*26*10 + 
            (str[2] - 'A')*10 + (str[3] - '0');
            stu[pos].courses.push_back(id);
        }
    }
    for(int i = 0; i < N; i++){
        string str;     str.resize(10);     scanf("%s",str.c_str());
        query(str);
    }
    
    return 0;
}

