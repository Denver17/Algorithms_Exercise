#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool cmp(string a, string b){
    string str1 = a + b;
    string str2 = b + a;
    if(str1 != str2)    return str1 < str2;
}

int main()
{
    int N;  cin>>N;
    vector<string> vec(N);
    for(int i = 0; i < N; i++)  cin>>vec[i];
    
    string asw;
    sort(vec.begin(), vec.end(), cmp);

    for(int i = 0; i < N; i++){
        asw += vec[i];
    }

    reverse(asw.begin(), asw.end());
    for(int i = asw.size() - 1; i > 0; i--){
        if(asw[i] == '0') asw.pop_back();
        else    break;
    }
    reverse(asw.begin(), asw.end());

    cout<<asw<<endl;

    return 0;
}

