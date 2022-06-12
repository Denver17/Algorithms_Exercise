//注意题目没有说丙是整数所以不能用int
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    double M, X, Y;    cin>>M>>X>>Y;
    int jia, yi;
    double bing;
    for(jia = 99; jia >= 10; jia--){
        yi = jia / 10 + (jia % 10) * 10;
        bing = 1.0 * yi / Y;
        // if(yi % Y != 0) continue;
        if(jia - yi == X * bing || yi - jia == X * bing){
            cout<<jia;
            if(jia == M)    cout<<" Ping";
            else if(jia > M)    cout<<" Cong";
            else    cout<<" Gai";
            if(yi == M)    cout<<" Ping";
            else if(yi > M)    cout<<" Cong";
            else    cout<<" Gai";
            if(bing == M)    cout<<" Ping";
            else if(bing > M)    cout<<" Cong";
            else    cout<<" Gai";
            return 0;
        }
    }
    cout<<"No Solution";

    return 0;
}

