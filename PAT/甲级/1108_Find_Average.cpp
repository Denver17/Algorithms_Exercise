#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;

bool judge(string str){
    int cnt = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] != '.' && !(str[i] >= '0' && str[i] <= '9') 
            && str[i] != '-' && str[i] != '+')  return false;
        if(str[i] == '-' && i != 0) return false;
        if(str[i] == '+' && i != 0) return false;
        if(str[i] == '.' && i == 0) return false;
        if(str[i] == '.')   cnt++;
    }
    if(cnt >= 2)    return false;

    if(cnt == 1){
        int pos = str.find(".");
        //if(pos == 0)    return false;
        int len = str.size() - pos;
        if(len > 3) return false;
    }

    double num = atof(str.c_str());
    if(num > 1000 || num < -1000)   return false;
    
    return true;
}

int main()
{
    int N;  cin>>N;
    vector<double> asw;
    for(int i = 0; i < N; i++){
        string str;     cin>>str;
        if(judge(str))  asw.push_back(atof(str.c_str()));
        else    printf("ERROR: %s is not a legal number\n", str.c_str());
    }
    if(asw.size() == 0) printf("The average of %d numbers is Undefined", asw.size());
    else if(asw.size() == 1)    printf("The average of 1 number is %.2f", asw[0]);
    else{
        double average = 0;
        for(int i = 0; i < asw.size(); i++) average += asw[i];
        printf("The average of %d numbers is %.2f", asw.size(), average / asw.size());
    }


    return 0;
}

