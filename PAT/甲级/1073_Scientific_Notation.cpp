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
    string asw;
    if(str[0] == '-')   asw.push_back('-');
    int pos = str.find('E');
    string base = str.substr(1, pos - 1);
    string index = str.substr(pos + 1, str.size() - pos);
    if(index[0] == '-'){
        base.erase(1, 1);
        index.erase(0, 1);
        int temp = atoi(index.c_str());
        asw.append(temp, '0');
        if(asw[0] == '-')   asw.insert(2, ".");
        else    asw.insert(1, ".");
        asw += base;
    }
    else{
        base.erase(1,1);
        index.erase(0, 1);
        asw += base;
        int temp = atoi(index.c_str());
        if(base.size() - 1 <= temp){
            asw.append(temp - base.size() + 1, '0');
        }
        else{
            asw.insert(temp + 2, ".");
        }
    }
    cout<<asw;

    return 0;
}

