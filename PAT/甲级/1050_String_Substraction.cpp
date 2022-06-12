#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    string str1,str2;   
    getline(cin,str1);
    getline(cin,str2);

    int hashTable[129] = {0};

    for(int i = 0; i < str2.size(); i++){
        hashTable[(int)str2[i]] = 1;
    }

    string asw;
    for(int i = 0; i < str1.size(); i++){
        if(hashTable[(int)str1[i]] == 0)    asw.push_back(str1[i]);
    }

    cout<<asw;

    return 0;
}

