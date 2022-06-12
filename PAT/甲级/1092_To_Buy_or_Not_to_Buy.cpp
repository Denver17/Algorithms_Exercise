#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main()
{
    bool flag = true;
    int asw = 0;        //如果多了，多多少
    int res = 0;        //如果缺少，少多少
    string str1, str2;      cin>>str1>>str2;
    map<char, int> mp1;
    map<char, int> mp2;
    for(int i = 0; i < str1.size(); i++){
        mp1[str1[i]]++;
    }

    for(int i = 0; i < str2.size(); i++){
        mp2[str2[i]]++;
    }

    for(map<char, int>::iterator it = mp1.begin(); it != mp1.end(); it++){
        if(mp2.count(it->first) == 0)   asw += it->second;
    }
    
    for(map<char, int>::iterator it = mp2.begin(); it != mp2.end(); it++){
        if(mp1.count(it->first) == 0){
            flag = false;
            res += it->second;
        }
        else if(mp1[it->first] < it->second){
            flag = false;
            res += it->second - mp1[it->first];
        }
        else if(mp1[it->first] >= it->second){
            asw += mp1[it->first] - it->second;
        }
    }

    if(flag == true){
        cout<<"Yes "<<asw<<endl;
    }
    else{
        cout<<"No "<<res<<endl;
    }

    return 0;
}

