#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;

void encode(string str){
    if(str.size() == 0) return ;
    string asw;
    int left = 0, right = 0;
    while(left < str.size()){
        while(right < str.size() && str[right] == str[left])  right++;
        int number = right - left;
        char character = str[left];
        string num = to_string(number);
        if(num != "1")
            asw.append(num); 
        asw.append(1, character);
        left = right;   
    }
    printf("%s", asw.c_str());
    return ;
}

void decode(string str){
    string asw;
    int left = 0, right = 0;
    while(left < str.size()){
        while( left < str.size() && !(str[left] >= '0' && str[left] <= '9') ){
            asw.append(1, str[left]);
            left++;
            right++;
        }
        while(str[right] >= '0' && str[right] <= '9')   right++;
        int number = atoi(str.substr(left, right - left).c_str());
        asw.append(number, str[right]);
        right++;
        left = right;
    }
    printf("%s", asw.c_str());
    return ;
}


int main()
{
    char c;     scanf("%c",&c);
    getchar();
    string str;     getline(cin, str);
    if(c == 'C')    encode(str);
    else if(c == 'D')   decode(str);

    return 0;
}

