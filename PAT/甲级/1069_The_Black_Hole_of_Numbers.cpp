#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;

bool cmp(char a, char b){
    if(a != b)  return a > b;
}

int main()
{
    string str;     cin>>str;
    reverse(str.begin(), str.end());        //测试点可能不会输入0007而输入7，好贱
    str.append(4 - str.size(), '0');
    reverse(str.begin(), str.end());
    string rstr = str;

    int temp = 1;
    while(temp != 6174 && temp != 0){
        sort(str.begin(), str.end());
        sort(rstr.begin(), rstr.end(), cmp);
        int num1 = atoi(rstr.c_str());
        int num2 = atoi(str.c_str());
        temp = num1 - num2;
        printf("%04d - %04d = %04d\n", num1, num2, temp);
        str = to_string(temp);
        
        reverse(str.begin(), str.end());
        str.append(4 - str.size(), '0');
        reverse(str.begin(), str.end());
        
        rstr = str;
    }
    return 0;
}

