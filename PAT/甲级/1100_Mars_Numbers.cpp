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
    getchar();
    string low[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string high[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    for(int i = 0; i < N; i++){
        string str;     getline(cin, str);
        if(str[0] >= '0' && str[0] <= '9'){
            int num = atoi(str.c_str());
            int nlow = num % 13;
            int nhigh = num / 13;
            if(nhigh != 0 && nlow != 0)
                cout<<high[nhigh]<<" "<<low[nlow]<<endl;
            else if(nhigh == 0)
                cout<<low[nlow]<<endl;
            else if(nlow == 0)
                cout<<high[nhigh]<<endl;
        }
        else if(str[0] >= 'a' && str[0] <= 'z'){
            int asw = 0;
            int pos = str.find(' ');
            string shigh = str.substr(0, pos);
            string slow = str.substr(pos + 1, str.size() - pos - 1);
            for(int j = 0; j < 13; j++){
                if(slow == low[j])  asw += j;
                if(shigh == high[j]) asw += 13 * j;
            }
            cout<<asw<<endl;
        }
    }


    return 0;
}

