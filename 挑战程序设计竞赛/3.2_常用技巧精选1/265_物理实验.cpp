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

const double g = 10.0;

int N, H, R, T;     

double solve(int T){
    if(T < 0)   return H;
    double t = sqrt(2 * H / g);
    int k = (int)(T / t);
    if(k % 2 == 0){
        double d = T - k * t;
        return H - g * d * d / 2;
    }
    else{
        double d = k * t + t - T;
        return H - g * d * d / 2;
    }
}

int main()
{
    int test;   cin>>test;
    while(test--){
        cin>>N>>H>>R>>T;
        vector<double> asw(N);
        for(int i = 0; i < N; i++){
            asw[i] = solve(T - i);
        }
        sort(asw.begin(), asw.end());
        for(int i = 0; i < N; i++){
            printf("%.2f%c", asw[i] + 2 * R * i / 100.0, i + 1 == N ? '\n' : ' ');
        }
    }   
    
    return 0;
}
