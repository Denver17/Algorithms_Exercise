#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;

int main()
{
    string str;     cin>>str;
    string A, B;    cin>>A>>B;
    reverse(str.begin(), str.end());
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    int carry = 0;
    string asw;
    for(int i = 0; i < A.size() || i < B.size(); i++){
        int mod = atoi(str.substr(i, 1).c_str());
        if(mod == 0)    mod = 10;
        int num1 = 0, num2 = 0;
        if(i < A.size()) num1 = atoi(A.substr(i, 1).c_str());
        if(i < B.size()) num2 = atoi(B.substr(i ,1).c_str());
        int sum = ( num1 + num2 + carry );
        if(sum >= mod)   carry = 1;
        else    carry = 0;
        sum = sum % mod;
        asw.push_back((char)(sum + '0'));
    }
    if(carry != 0){
        asw.push_back((char)(carry + '0'));
    }

    for(int i = asw.size() - 1; i >= 0; i--){
        if(asw[i] == '0' && asw.size() > 1)   asw.pop_back();
        else break;
    }
    reverse(asw.begin(), asw.end());
    cout<<asw<<endl;

    return 0;
}

