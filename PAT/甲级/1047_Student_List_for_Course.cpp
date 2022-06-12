#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int N,K;    scanf("%d%d",&N,&K);
    vector<vector<string> > asw(K+1);
    for(int i = 0; i < N; i++){
        string str;     str.resize(10); scanf("%s",str.c_str());
        int C;  cin>>C;
        for(int j = 0; j < C; j++){
            int temp;   scanf("%d",&temp);
            asw[temp].push_back(str);
        }
    }
    for(int i = 1; i < asw.size(); i++) sort(asw[i].begin(),asw[i].end());
    for(int i = 1; i < asw.size(); i++){
        //cout<<i<<" "<<asw[i].size()<<endl;
        printf("%d %d\n",i,asw[i].size());
        for(int j = 0; j < asw[i].size(); j++){
            printf("%s\n",asw[i][j].c_str());
        }
    }

    return 0;
}

