#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int N, M;   scanf("%d %d", &N, &M);
    int asw = 0;
    vector<int> id;
    vector<vector<int> > vec(M, vector<int>(N));
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &vec[i][j]);
        }
    }
    for(int i = 0; i < N; i++){
        int sum = 0;
        for(int j = 0; j < M; j++){
            sum += vec[j][i];
        }
        if(sum > asw){
            asw = sum;
            id.clear();
            id.push_back(i + 1);
        }
        else if(sum == asw){
            id.push_back(i + 1);
        }
    }
    sort(id.begin(), id.end());
    cout<<asw<<endl;
    cout<<id[0];
    for(int i = 1; i < id.size(); i++)  cout<<" "<<id[i];

    return 0;
}

