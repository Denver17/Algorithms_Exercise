//做得我有点恶啊我去，不算难但做得不好
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> problem;

struct user{
    int id;     int total_score;
    vector<int> partial_score;
    bool flag;          //标记是否能够上榜
    int perfect_num = 0;
}users[10000];

bool cmp(user a,user b){
    if( a.total_score != b.total_score )    return a.total_score > b.total_score;
    else if( a.perfect_num != b.perfect_num )   return a.perfect_num > b.perfect_num;
    return a.id < b.id;  
}


int main()
{
    int N,K,M;  
    scanf("%d%d%d",&N,&K,&M);
    problem.resize(K);
    for(int i = 0; i < K; i++)  scanf("%d",&problem[i]);
    for(int i = 0; i < N; i++)  { 
        users[i].partial_score.resize(K);
        fill(users[i].partial_score.begin(),users[i].partial_score.end(),-2);
        users[i].flag = false;
    }
    for(int i = 0; i < M; i++){
        int u_id,p_id,p_score;
        scanf("%d%d%d",&u_id,&p_id,&p_score);

        u_id--; p_id--;
        if( p_score > users[u_id].partial_score[p_id] ){
            users[u_id].id = u_id + 1;
            users[u_id].partial_score[p_id] = p_score;
            if( p_score == problem[p_id] ) users[u_id].perfect_num++;
            if( p_score >= 0)   users[u_id].flag = true;
        }
    }

    vector<user> asw;
    for(int i = 0; i < N; i++){
        if(users[i].flag == false)  continue;
        int total = 0;
        for(int j = 0; j < users[i].partial_score.size(); j++){
            if(users[i].partial_score[j] == -2) continue;
            else if(users[i].partial_score[j] == -1){
                users[i].partial_score[j] = 0;
                continue;
            }
            else total += users[i].partial_score[j];
        }
        users[i].total_score = total;
        asw.push_back(users[i]);
    }

    sort(asw.begin(),asw.end(),cmp);

    int rank = 1;
    printf("%d %05d %d",rank,asw[0].id,asw[0].total_score);
    for(int i = 0; i < K; i++)  {
        if(asw[0].partial_score[i] == -2)
            printf(" -");
        else if(asw[0].partial_score[i] == -1)
            printf(" %d",0);
        else 
            printf(" %d",asw[0].partial_score[i]);
    }
    printf("\n");
    for(int i = 1; i < asw.size(); i++){
        if(asw[i].total_score == asw[i-1].total_score)
            printf("%d",rank);
        else{
            rank = i + 1;
            printf("%d",rank);
        }
        printf(" %05d %d",asw[i].id,asw[i].total_score);
        for(int j = 0; j < K; j++)  {
            if(asw[i].partial_score[j] == -2)
                printf(" -");
            else 
                printf(" %d",asw[i].partial_score[j]);
        }
        printf("\n");
    }


    return 0;
}


