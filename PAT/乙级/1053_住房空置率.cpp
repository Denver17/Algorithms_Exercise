#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int N, D;
    double e;
    cin>>N>>e>>D;
    double asw1 = 0, asw2 = 0;
    for(int i = 0; i < N; i++){
        int K;  cin>>K;
        int num = 0;
        for(int j = 0; j < K; j++){
            double val;    cin>>val;
            if(val < e) num++;
        }
        if(num > K / 2) asw1++;
        if(num > K / 2 && K > D){ asw1--; asw2++;}
    }
    asw1 = asw1 / N * 100;
    asw2 = asw2 / N * 100;
    printf("%.1f%% %.1f%%", asw1, asw2);
    return 0;
}

