//一开始将string转为double做很容易，但测试点5无法通过
//可能是数据会太大导致double精度或范围不够，所以只能用string做
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;

string change(string str, int N){
    int ptr = 0, e = 0;
    while(str.length() > 0 && str[0] == '0')    str.erase(str.begin());
    if(str[0] == '.'){
        str.erase(str.begin());
        while(str.length() > 0 && str[0] == '0'){
            str.erase(str.begin());
            e--;
        }
    }
    else{
        while(ptr < str.length() && str[ptr] != '.'){
            ptr++;
            e++;
        }
        if(ptr < str.length())  str.erase(str.begin() + ptr);
    }
    if(str.length() == 0)   e = 0;
    int num = 0;
    ptr = 0;
    string asw;
    while(num < N){
        if(ptr < str.length())  asw += str[ptr++];
        else    asw += '0';
        num++;
    }
    asw = "0." + asw + "*10^" + to_string(e);
    return asw;
}

int main()
{
    int N;  cin>>N;
    string str1, str2;  cin>>str1>>str2;
    string asw1 = change(str1, N);
    string asw2 = change(str2, N);

    if(asw1 == asw2)    cout<<"YES "<<asw1<<endl;
    else    cout<<"NO "<<asw1<<" "<<asw2<<endl;

    return 0;
}

