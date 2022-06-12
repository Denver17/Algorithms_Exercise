//位运算的优先级很低要加括号啊
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    string str;     getline(cin, str);
    vector<unsigned> vec;
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            vec.push_back((int)(str[i] - 'a') + 1);
        }
        else if(str[i] >= 'A' && str[i] <= 'Z'){
            vec.push_back((int)(str[i] - 'A') + 1);
        }
    }
    if(vec.size() == 0){
        cout<<0<<" "<<0;
        return 0;
    }
    unsigned sum = 0;
    for(int i = 0; i < vec.size(); i++) sum += vec[i];
   
    unsigned num = 1 << 31;
    while((num & sum) == 0)   num = num >> 1;   //括号勿忘
    
    int asw0 = 0, asw1 = 0;
    while(num != 0){
        if((num & sum) == 0)  asw0++;   //括号勿忘
        else    asw1++;
        num = num >> 1;
    }
    cout<<asw0<<" "<<asw1;

    return 0;
}

