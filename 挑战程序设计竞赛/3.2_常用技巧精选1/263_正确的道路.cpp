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

int N;
vector<int> vec;

int solve(int K){
    int sum = 0;
    int res = 0;
    vector<int> f(N, 0);    //f[i]代表[i, i + K - 1]是否进行了翻转,1代表翻转了,0代表未翻转
    for(int i = 0; i <= N - K; i++){
        if((vec[i] + sum) % 2 == 1){
            f[i] = 1;
            res++;
        }
        sum += f[i];
        if(i - K + 1 >= 0){
            sum -= f[i - K + 1];
        }
    }
    for(int i = N - K + 1; i < N; i++){
        if((vec[i] + sum) % 2 == 1)     return -1;
        if(i - K + 1 >= 0){
            sum -= f[i - K + 1];
        }
    }
    return res;
}

int main()
{
    cin>>N;
    vec.resize(N);
    for(int i = 0; i < N; i++){
        char c;     cin>>c;
        if(c == 'F')    vec[i] = 0;
        else    vec[i] = 1;
    }
    int M = 0x3f3f3f3f;
    int K;
    for(int i = 1; i <= N; i++){
        int res = solve(i);
        if(res < M && res >= 0){
            K = i;
            M = res;
        }
    }
    cout<<K<<" "<<M<<endl;

    return 0;
}
