#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<stdlib.h>
using namespace std;

int main()
{
    int N;  cin>>N;
    map<int,string> mp;
    string str1[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
    string str2[13] = {"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
    for(int i = 0; i < 169; i++){
        int low = i % 13;
        int high = i / 13;
        string str = "";
        if(high != 0){
            str = str2[high]; 
        }    
        if(str.size() != 0) str += " ";
        if(low == 0){
            str = str2[high];
        }
        else{
            str += str1[low];
        }
        mp[i] = str;
    }
    getchar();
    for(int i = 0; i < N; i++){
        string str;     getline(cin,str);
        if(str[0] <= '9' && str[0] >= '0'){
            int temp = atoi(str.c_str());
            cout<<mp[temp]<<endl;
        }
        else{
            for(map<int,string>::iterator it = mp.begin(); it != mp.end(); it++){
                if(it->second == str){
                    cout<<it->first<<endl;
                }
            }
        }
    }
    
    return 0;
}

