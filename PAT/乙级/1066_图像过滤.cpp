#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int M, N, A, B, K;   cin>>M>>N>>A>>B>>K;
    vector<vector<int> > asw(M,vector<int>(N));
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            scanf("%d",&asw[i][j]);
            if(asw[i][j] >= A && asw[i][j] <= B)    asw[i][j] = K; 
            if(j != 0 && j != N - 1)
                printf(" %03d",asw[i][j]);
            else if(j == 0)
                printf("%03d",asw[i][j]);
            else if(j == N - 1)
                printf(" %03d\n",asw[i][j]);
        }
    }

    return 0;
}

