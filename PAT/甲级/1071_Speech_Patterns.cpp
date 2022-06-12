//字符串分割要注意，比如aaa*aaaa
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main()
{
    map<string,int> mp;
    string str;
    while(cin>>str){
        transform(str.begin(),str.end(),str.begin(),::tolower);
        int left,right;
        vector<string> vstr;
        string sstr;
        for(left = 0,right = 0; left < str.size();){
            if(str[right] <= 'z' && str[right] >= 'a' || str[right] <= '9' && str[right] >= '0'){
                right++;
            }
            else{
                sstr = str.substr(left,right - left);
                vstr.push_back(sstr);
                right++;    left = right;
            }
        }
        for(int i = 0; i < vstr.size(); i++){
            mp[vstr[i]]++;
        }
    }
    int _max = 0;   vector<string> asw;
    string str2;
    for(map<string,int>::iterator it = mp.begin(); it != mp.end(); it++){
        if(it->second > _max){
            _max = it->second;
            str2 = it->first;
            asw.clear();
            asw.push_back(str2);
        }
        else if(it->second == _max){
            str2 = it->first;
            asw.push_back(str2);
        }
    }
    sort(asw.begin(),asw.end());
    cout<<asw[0]<<" "<<_max;

    return 0;
}

