//定义long long 类型，防止int溢出
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    long long G1,S1,K1,G2,S2,K2,G,S,K;
    cin>>G1; getchar(); cin>>S1; getchar(); cin>>K1; getchar();
    cin>>G2; getchar(); cin>>S2; getchar(); cin>>K2; getchar();
    long long sum1 = 0,sum2 = 0;

    sum1 = G1 * 17 * 29 + S1 * 29 + K1;
    sum2 = G2 * 17 * 29 + S2 * 29 + K2;

    long long asw = sum1 + sum2;

    K = asw % 29;
    asw = asw / 29;
    S = asw % 17;
    G = asw / 17;

    cout<<G<<'.'<<S<<'.'<<K;        

    return 0;
}

