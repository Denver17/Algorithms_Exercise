#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

const int maxn = 2022;

struct polynomial{
    int len;
    double matrix[maxn];
    polynomial(){
        len = 0;
        memset(matrix,0,sizeof(matrix));
    }
};

int main()
{
    int K1; cin>>K1;
    polynomial p1,p2;
    p1.len = K1;
    for(int i = 0; i < K1; i++){
        int index;  cin>>index;
        cin>>p1.matrix[index];
    }
    int K2; cin>>K2;
    p2.len = K2;
    for(int i = 0; i < K2; i++){
        int index;  cin>>index;
        cin>>p2.matrix[index];
    }

    polynomial asw;
    asw.len = 0;
    for(int i = 0; i < maxn / 2; i++){
        for(int j = 0; j < maxn / 2; j++){
            int index = i + j;
            double res = p1.matrix[i] * p2.matrix[j];
            asw.matrix[index] += res;
        }
    }
    for(int i = 0; i < maxn; i++){
        if(asw.matrix[i] != 0) asw.len++;
    }
    cout<<asw.len;
    for(int i = maxn - 1; i >= 0; i--){
        if(asw.matrix[i] != 0)
            printf(" %d %.1f",i,asw.matrix[i]);
    }
    


    return 0;
}

