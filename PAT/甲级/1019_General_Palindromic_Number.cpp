//应看清楚题目要求的进制，这个进制数可能很大，比如100进制，直接将
//单一的char转化可能转为非数字字符
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool isPalindromic(vector<string> str){
    if(str.size() == 0) return true;
    int left = 0, right = str.size() - 1;
    while(left < right){
        if(str[left] != str[right]) return false;
        left++;     right--;
    }
    return true;
}


int main()
{
    int N,b;  cin>>N>>b;
    vector<string> str;
    while(N != 0){
        int temp = N % b;
        N = N / b;
        str.push_back(to_string(temp));
    }
    reverse(str.begin(),str.end());
    if(isPalindromic(str))  cout<<"Yes"<<endl;
    else    cout<<"No"<<endl;
    cout<<str[0];
    for(int i = 1; i < str.size(); i++) cout<<" "<<str[i];

    return 0;
}

