#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    string str; str.resize(1e5 + 10);
    scanf("%s", str.c_str());
    //int left = 0, right = 0;
    long long asw = 0;

    vector<int> dpA(str.size(), 0);
    vector<int> dpP(str.size(), 0);
    
    int resT = 0;
    for(int i = str.size() - 1; i >= 0; i--){
        if(str[i] == 'T')   resT++;
        else if(str[i] == 'A')  dpA[i] = resT;
    }

    int resA = 0;
    for(int i = str.size() - 1; i >= 0; i--){
        if(str[i] == 'A')   resA += dpA[i];
        else if(str[i] == 'P')  asw += resA;
    }

    long long mod = 1e9;
    asw = asw % (mod + 7);
    printf("%lld\n", asw);

    return 0;
}

