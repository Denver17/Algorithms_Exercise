#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;

struct question{
    int id;
    int score;
    int number;
    int right_number;
    vector<char> right;
    int wrong;
};

bool cmp(question a, question b){
    if(a.wrong != b.wrong)  return a.wrong > b.wrong;
    return a.id < b.id;
}

int main()
{
    int N, M;  cin>>N>>M;
    vector<question> qes(M);
    for(int i = 0; i < M; i++){
        cin>>qes[i].score>>qes[i].number>>qes[i].right_number;
        qes[i].right.resize(qes[i].right_number);
        for(int j = 0; j < qes[i].right_number; j++){
            cin>>qes[i].right[j];
        }
        sort(qes[i].right.begin(), qes[i].right.end());
        qes[i].id = i + 1;
        qes[i].wrong = 0;
    }   

    for(int i = 0; i < N; i++){
        int stu_score = 0;
        scanf("\n");
        for(int j = 0; j < M; j++){
            if(j != 0)  scanf(" ");
            int num;    scanf("(%d",&num);
            vector<char> vec(num);
            for(int k = 0; k < num; k++){
                scanf(" %c",&vec[k]);
            }
            scanf(")");
            
            sort(vec.begin(), vec.end());
            if(vec == qes[j].right)   stu_score += qes[j].score;
            else qes[j].wrong++;

        }
        cout<<stu_score<<endl;
    } 
    sort(qes.begin(), qes.end(), cmp);

    if(qes[0].wrong == 0)   cout<<"Too simple";
    else{
        cout<<qes[0].id<<" "<<qes[0].wrong;
        for(int i = 1; i < qes.size(); i++){
            if(qes[i].wrong == qes[0].wrong)    cout<<" "<<qes[i].id;
            else break;
        }
    }
    cout<<endl;

    return 0;
}

