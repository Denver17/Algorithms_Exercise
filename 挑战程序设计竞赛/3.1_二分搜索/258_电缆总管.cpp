#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int N, K;
vector<double> vec;

bool judge(double len){
    int res = 0;
    for(int i = 0; i < vec.size(); i++){
        res += (int)(vec[i] / len);
    }
    return res >= K;
}

int main()
{
    scanf("%d %d", &N, &K);
    vec.resize(N);
    for(int i = 0; i < N; i++)  scanf("%lf", &vec[i]);

    double left = 0, right = 1e5 + 10;
    while(left < right - 0.01){
        double mid = left + (right - left) / 2;
        if(judge(mid))  left = mid;
        else    right = mid;
    }

    printf("%.2f", floor(left * 100 ) / 100);

    return 0;
}
