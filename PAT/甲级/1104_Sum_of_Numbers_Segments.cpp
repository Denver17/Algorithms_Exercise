#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

long double asw = 0;


int main()
{
    long long N;
    scanf("%lld",&N);
    vector<long double> vec(N);
    for(long long i = 0; i < N; i++){
        scanf("%llf",&vec[i]);
    }

    vector<long double> nums(N);
    for(long long i = 0; i < N; i++){
        nums[i] = (N - i) * (i + 1); 
    }

    for(long long i = 0; i < N; i++){
        asw += nums[i] * vec[i];
    }

    printf("%.2Lf",asw);

    return 0;
}



