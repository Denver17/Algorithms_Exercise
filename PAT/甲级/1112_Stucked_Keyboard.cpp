//res要求按字符串出现的顺序排列，好刁钻，恶心
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<map>
using namespace std;

int main()
{
    int N;  cin>>N;
    string str; cin>>str;

    unordered_map<char, bool> mp;
    for(int i = 0; i < str.size(); i++){
        if(count(str.begin(), str.end(), str[i]) % N == 0)  continue;
        else    mp[str[i]] = false;
    }

    int pos = 0;
    while(pos < str.size()){
        if(mp.count(str[pos]) != 0 && mp[str[pos]] == false)   pos++;
        else if(mp.count(str[pos]) != 0 && mp[str[pos]] == true){
            int temp = pos;
            while(temp < str.size() && str[temp] == str[pos])   temp++;
            if( (temp - pos) % N == 0) mp[str[pos]] = true;
            else    mp[str[pos]] = false;
            pos = temp;
        }
        else{
            int temp = pos;
            while(temp < str.size() && str[temp] == str[pos])   temp++;
            if( (temp - pos) % N == 0) mp[str[pos]] = true;
            else    mp[str[pos]] = false;
            pos = temp;
        }
    }

    string res, asw;
    // for(unordered_map<char, bool>::iterator it = mp.begin(); it != mp.end(); it++){
    //     if(it->second == true)  res += it->first;
    // }
    unordered_map<char, bool> mp2 = mp;
    for(int i = 0; i < str.size(); i++){
        if(mp2[str[i]] == true){
            res += str[i];
            mp2[str[i]] = false;
        }
    }
    for(int i = 0; i < str.size(); ){
        if(mp[str[i]] == false){ asw += str[i]; i++; }
        else{
            asw += str[i];
            i += N;
        }
    }

    //reverse(res.begin(), res.end());

    cout<<res<<endl;
    cout<<asw<<endl;

    return 0;
}

