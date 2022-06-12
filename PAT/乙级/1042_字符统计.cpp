#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    int hashTable[26] = {0};
    for(int i = 0; i < str.size(); i++) transform(str.begin(),str.end(),str.begin(),::towlower);
    for(int i = 0; i < str.size(); i++){
        if(str[i] <= 'z' && str[i] >= 'a')
            hashTable[str[i]-'a']++;
    }
    int _max = 0;
    for(int i = 0; i < 26; i++){
        if(hashTable[i] > _max) _max = hashTable[i];
    }
    for(int i = 0; i < 26; i++){
        if(_max == hashTable[i]){
            cout<<(char)('a'+i)<<" "<<hashTable[i];
            return 0;
        }
    }

    return 0;
}
