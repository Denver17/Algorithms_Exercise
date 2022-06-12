#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    string str; cin>>str;
    long long asw = 0;
    int numT = 0, num = 0;
    for(int i = str.size() - 1; i >= 0; i--){
        if(str[i] == 'T')   numT++;
        else if(str[i] == 'A'){
            num += numT;
        }
        else if(str[i] == 'P')  asw += num;
    }
    int mod = 1e9 + 7;
    asw = asw % mod;
    printf("%d\n", asw);

    return 0;
}

