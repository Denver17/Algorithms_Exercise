#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int sum1 = 0,sum2 = 0;
    int G1,S1,K1,G2,S2,K2;
    cin>>G1; getchar(); cin>>S1; getchar(); cin>>K1;
    cin>>G2; getchar(); cin>>S2; getchar(); cin>>K2;

    sum1 = K1 + S1 * 29 + G1 * 17 * 29;
    sum2 = K2 + S2 * 29 + G2 * 17 * 29;

    int asw = abs ( sum2 - sum1 );

    int asw1 = asw % 29;
    asw = asw / 29;
    int asw2 = asw % 17;
    int asw3 = asw / 17;

    if(sum2 - sum1 >= 0)    cout<<asw3<<'.'<<asw2<<'.'<<asw1;
    else cout<<'-'<<asw3<<'.'<<asw2<<'.'<<asw1;
    
    return 0;
}

