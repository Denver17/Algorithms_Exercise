//思路复杂了，A与B都有可能更长，直接开一个最大长度数组可能更好处理
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;

int main()
{
    string A,B;    cin>>A>>B;
    string asw;
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());

    int i;
    for(i = 0; i < A.size() && i < B.size(); i++){
        if( (i + 1) % 2 == 1){
            int temp = ( (A[i]-'0') + (B[i]-'0') ) % 13;
            if(temp == 10)  asw.push_back('J');
            else if(temp == 11) asw.push_back('Q');
            else if(temp == 12) asw.push_back('K');
            else    asw.push_back((char)(temp+'0'));
        }
        else{
            int temp = B[i] - A[i];
            if(temp < 0){
                temp += 10; asw.push_back((char)(temp+'0'));
            }
            else{
                asw.push_back((char)(temp+'0'));
            }
        }
    }

    while(i < B.size()){
        asw.push_back(B[i]);
        i++;
    }

    while(i < A.size()){
        if( (i + 1) % 2 == 1)   asw.push_back(A[i]);
        else{
            if('0' == A[i]) asw.push_back(A[i]);
            else{
                int temp = 10 + ('0' - A[i]);
                asw.push_back((char)(temp+'0'));
            }
        }
        i++;
    }
    
    reverse(asw.begin(),asw.end());

    cout<<asw;

    return 0;
}

