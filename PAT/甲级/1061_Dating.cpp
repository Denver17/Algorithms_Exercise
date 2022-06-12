#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std;

int main()
{
    char asw1, asw2;
    int asw3 = 0;
    string str1, str2, str3, str4;
    cin>>str1>>str2>>str3>>str4;
    
    // map<char, int> mp;
    // for(int i = 0; i < str1.size(); i++){
    //     mp[str1[i]]++;
    // }

    int pos;
    for(pos = 0; pos < str2.size(); pos++){
        if(str2[pos] >= 'A' && str2[pos] <= 'G' &&  str1[pos] == str2[pos]){
            asw1 = str2[pos];
            pos++;
            break;
        }
    }
    
    while(pos < str2.size()){
        if( ((str2[pos] >= 'A' && str2[pos] <= 'N') ||
            (str2[pos] >= '0' && str2[pos] <= '9') )&& 
            str1[pos] == str2[pos]){
            asw2 = str2[pos];
            break;
        }
        pos++;
    }

    for(int i = 0; i < str3.size() && i < str4.size(); i++){
        if( (str3[i] >= 'A' && str3[i] <= 'Z' ||
            str3[i] >= 'a' && str3[i] <= 'z' ) &&
            str3[i] == str4[i]){
            asw3 = i;
            break;
        }
    }

    map<char, string> change;
    change['A'] = "MON";
    change['B'] = "TUE";
    change['C'] = "WED";
    change['D'] = "THU";
    change['E'] = "FRI";
    change['F'] = "SAT";
    change['G'] = "SUN";

    map<char, int> trans;
    trans['0'] = 0;
    trans['1'] = 1;
    trans['2'] = 2;
    trans['3'] = 3;
    trans['4'] = 4;
    trans['5'] = 5;
    trans['6'] = 6;
    trans['7'] = 7;
    trans['8'] = 8;
    trans['9'] = 9;
    trans['A'] = 10;
    trans['B'] = 11;
    trans['C'] = 12;
    trans['D'] = 13;
    trans['E'] = 14;
    trans['F'] = 15;
    trans['G'] = 16;
    trans['H'] = 17;
    trans['I'] = 18;
    trans['J'] = 19;
    trans['K'] = 20;
    trans['L'] = 21;
    trans['M'] = 22;
    trans['N'] = 23;

    printf("%s %02d:%02d", change[asw1].c_str(), trans[asw2], asw3);

    return 0;
}

