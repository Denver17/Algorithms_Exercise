#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
#include<cmath>
using namespace std;

int main()
{
    string str;     cin>>str;
    //reverse(str.begin(), str.end());

    long long asw = 0;
    for(int i = str.size() - 1; i >= 0; i--){
        int left = atoi(str.substr(0, i).c_str());
        int right = atoi(str.substr(i + 1, str.size()).c_str());
        int now = (int)(str[i] - '0');
        if(now == 0)    asw += left * pow(10, str.size() - i - 1);
        else if(now == 1)   asw += left * pow(10, str.size() - i - 1) + right + 1;
        else if(now >= 2)   asw += (left + 1) * pow(10, str.size() - i - 1);
    }

    printf("%lld", asw);

    return 0;
}

