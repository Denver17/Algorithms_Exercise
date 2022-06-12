#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    int N;  cin>>N;
    double asw = 0;
    for(int i = 0; i < N; i++){
        double val1, val2;  cin>>val1>>val2;
        double num = val1 * val1 + val2 * val2;
        num = sqrt(num);
        if(num > asw)   asw = num;
    }
    
    printf("%.2f",asw);

    return 0;
}

