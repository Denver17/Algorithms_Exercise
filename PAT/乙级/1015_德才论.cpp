#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

struct student{
    int id;
    int moral_score;
    int talent_score;
    int rank;
}stu[100010];

int N,L,H;

bool cmp1(student a,student b){
    int sum1 = a.moral_score + a.talent_score;
    int sum2 = b.moral_score + b.talent_score;
    if( a.rank != b.rank )  return a.rank < b.rank;
    else if( sum1 != sum2 )   return sum1 > sum2;
    else if( a.moral_score != b.moral_score )   return a.moral_score > b.moral_score;
    else    return a.id < b.id;
}

int main()
{

    cin>>N>>L>>H;
    int M = 0;
    for(int i = 0; i < N; i++){
        int sid,sms,sts;
        cin>>sid>>sms>>sts;
        if( sms >= L && sts >= L){    
            stu[M].id = sid;    stu[M].moral_score = sms;   stu[M].talent_score = sts;
            if( ( stu[M].moral_score >= H && stu[M].talent_score >= H) ){
                stu[M].rank = 1;
            }
            else if( ( stu[M].moral_score >= H && stu[M].talent_score < H) ){
                stu[M].rank = 2;
            }
            else if( ( stu[M].moral_score < H && stu[M].talent_score < H &&  stu[M].moral_score >= stu[M].talent_score ) ){
                stu[M].rank = 3;
            }
            else{
                stu[M].rank = 4;
            }
            M++;
        }
    }
    sort(stu,stu+M,cmp1);

    cout<<M<<endl;

    for(int i = 0; i < M; i++){
        cout<<stu[i].id<<" "<<stu[i].moral_score<<" "<<stu[i].talent_score<<endl;
    }

    return 0;
}
