#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int main()
{
    string str1,str2;
    cin>>str1>>str2;
    vector<int> hashTable1(62,0);
    vector<int> hashTable2(62,0);
    for(int i = 0; i < str1.size(); i++){
        if( str1[i] <= 'z' && str1[i] >= 'a' ){
            hashTable1[str1[i]-'a']++;
        }
        else if( str1[i] <= 'Z' && str1[i] >= 'A' ){
            hashTable1[str1[i]-'A'+26]++;
        }
        else if( str1[i] <= '9' && str1[i] >= '0'){
            hashTable1[str1[i]-'0'+52]++;
        }
    }
    for(int i = 0; i < str2.size(); i++){
        if( str2[i] <= 'z' && str2[i] >= 'a' ){
            hashTable2[str2[i]-'a']++;
        }
        else if( str2[i] <= 'Z' && str2[i] >= 'A' ){
            hashTable2[str2[i]-'A'+26]++;
        }
        else if( str2[i] <= '9' && str2[i] >= '0'){
            hashTable2[str2[i]-'0'+52]++;
        }
    }
    
    int asw = 0;
    bool flag = true;
    for(int i = 0; i < hashTable1.size(); i++){
        if( hashTable1[i] >= hashTable2[i] )    continue;
        else flag = false;
    }

    if(flag == false){
        for(int i = 0; i < hashTable1.size(); i++){
            if(hashTable2[i] > hashTable1[i])   asw += hashTable2[i] - hashTable1[i];
        }
        cout<<"No "<<asw;
    }
    else{
        for(int i = 0; i < hashTable1.size(); i++){
            if(hashTable1[i] > hashTable2[i])   asw += hashTable1[i] - hashTable2[i];
        }
        cout<<"Yes "<<asw;
    }

    return 0;
}
