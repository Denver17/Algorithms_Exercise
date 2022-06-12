#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int N, M;   cin>>N>>M;
    vector<vector<int> > vec(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>vec[i][j];
        }
    }
    vector<int> res;
    int asw = 0;
    for(int i = 0; i < N; i++){
        int num = 0;
        for(int j = 0; j < M; j++){
            if(vec[i][j] > num) num = vec[i][j];
            if(vec[i][j] > asw) asw = vec[i][j];     
        }
        res.push_back(num);
    }

    cout<<res[0];
    for(int i = 1; i < res.size(); i++) cout<<" "<<res[i];
    cout<<endl;
    cout<<asw<<endl;

    return 0;
}

