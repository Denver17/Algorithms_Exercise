#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

struct people{
    string name;
    int age;
    int worth;
}p[100000];

int N,K;

bool cmp1(people a,people b){
    if( a.worth != b.worth )    return a.worth > b.worth;
    else if( a.age != b.age )   return a.age < b.age;
    else if( a.name != b.name ) return a.name < b.name;
}

void query(int M,int Amin,int Amax){
    int ptr = 0;
    for(int i = 0; i < N; i++){
        if(p[i].age >= Amin && p[i].age <= Amax){
            ptr++;
            printf("%s %d %d\n",p[i].name.c_str(),p[i].age,p[i].worth);
        }
        if(ptr == M)    break;
    }
    if(ptr == 0)    printf("None\n");

    return ;
}


int main()
{
    scanf("%d%d",&N,&K);
    for(int i = 0; i < N; i++){
        p[i].name.resize(10);
        scanf("%s%d%d",&p[i].name[0],&p[i].age,&p[i].worth);
    }
    sort(p,p+N,cmp1);
    for(int i = 0; i < K; i++){
        int M,Amin,Amax;
        scanf("%d%d%d",&M,&Amin,&Amax);
        printf("Case #%d:\n",i + 1);
        query(M,Amin,Amax);
    }

    return 0;
}


