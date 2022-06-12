#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct question{
    int score;
    int answer;
};

int main()
{
    int N, M;  cin>>N>>M;
    vector<question> qes(M);
    for(int i = 0; i < M; i++)  cin>>qes[i].score;
    for(int i = 0; i < M; i++)  cin>>qes[i].answer;
    for(int i = 0; i < N; i++){
        int asw = 0;
        for(int j = 0; j < M; j++){
            int res;    cin>>res;
            if(qes[j].answer == res) asw += qes[j].score;
        }
        cout<<asw<<endl;
    }

    return 0;
}

