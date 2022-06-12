//cmp函数格外注意其返回值，不然可能越界
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct student{
    string id;
    int C,M,E;
    int ranka,rankc,rankm,ranke;
    double A;
};

bool cmp1(student a,student b){
    if( a.A != b.A ) return a.A > b.A; 
    return a.id < b.id;
}

bool cmp2(student a,student b){
    if( a.C != b.C ) return a.C > b.C;  
    return a.id < b.id;
}

bool cmp3(student a,student b){
    if( a.M != b.M ) return a.M > b.M;
    return a.id < b.id;
}

bool cmp4(student a,student b){
    if( a.E != b.E ) return a.E > b.E;
    return a.id < b.id;
}

void my_sort(student stu[],int N){
    //平均分
    
    sort(stu,stu+N,cmp1);
    int rank1 = 1;
    stu[0].ranka = 1;
    for(int i = 1; i < N; i++){
        if(stu[i].A != stu[i-1].A){
            rank1 = i + 1;
            stu[i].ranka = rank1;
        }
        else{
            stu[i].ranka = rank1;
        }
    }
   
    //C语言
    sort(stu,stu+N,cmp2);
    int rank2 = 1;
    stu[0].rankc = 1;
    for(int i = 1; i < N; i++){
        if(stu[i].C != stu[i-1].C){
            rank2 = i + 1;
            stu[i].rankc = rank2;
        }
        else{
            stu[i].rankc = rank2;
        }
    }

    //数学
    sort(stu,stu+N,cmp3);
    int rank3 = 1;
    stu[0].rankm = 1;
    for(int i = 1; i < N; i++){
        if(stu[i].M != stu[i-1].M){
            rank3 = i + 1;
            stu[i].rankm = rank3;
        }
        else{
            stu[i].rankm = rank3;
        }
    }

    //英语
    sort(stu,stu+N,cmp4);
    int rank4 = 1;
    stu[0].ranke = 1;
    for(int i = 1; i < N; i++){
        if(stu[i].E != stu[i-1].E){
            rank4 = i + 1;
            stu[i].ranke = rank4;
        }
        else{
            stu[i].ranke = rank4;
        }
    }

    return ;
}


void query(student stu[],string num,int N){
    int temp = -1;
    for(int i = 0; i < N; i++){
        if(stu[i].id == num)   temp = i;
    }
    if( temp == -1){
        cout<<"N/A"<<endl;
        return ;
    }
    
    int _min = min({stu[temp].ranka,stu[temp].rankc,stu[temp].rankm,stu[temp].ranke});
    if( _min == stu[temp].ranka ){
        cout<<stu[temp].ranka<<" A"<<endl;
        return ;
    }
    if( _min == stu[temp].rankc ){
        cout<<stu[temp].rankc<<" C"<<endl;
        return ;
    }
    if( _min == stu[temp].rankm ){
        cout<<stu[temp].rankm<<" M"<<endl;
        return ;
    }
    if( _min == stu[temp].ranke ){
        cout<<stu[temp].ranke<<" E"<<endl;
        return ;
    }
    return ;
}



int main()
{
    int N,M;
    cin>>N>>M;
    student stu[N];
    for(int i = 0; i < N; i++){
        cin>>stu[i].id>>stu[i].C>>stu[i].M>>stu[i].E;
        stu[i].A = (stu[i].C + stu[i].M + stu[i].E) / 3.0;
    }

    my_sort(stu,N);

    for(int i = 0; i < M; i++){
        string num;    cin>>num;
        query(stu,num,N);
    }

    return 0;
}

