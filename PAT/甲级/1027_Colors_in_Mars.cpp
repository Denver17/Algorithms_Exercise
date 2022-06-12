#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string tran(int num){
    string res;
    while(num != 0){
        int temp = num % 13;
        if(temp == 10)  res.push_back('A');
        else if(temp == 11) res.push_back('B');
        else if(temp == 12) res.push_back('C');
        else res.push_back((char)(temp+'0'));
        num = num / 13;
    }
    if(res.size() == 1) res.push_back('0');
    else if(res.size() == 0) {res.push_back('0');   res.push_back('0');}
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    int R,G,B;  cin>>R>>G>>B;
    string asw1,asw2,asw3;
    asw1 = tran(R);    
    asw2 = tran(G);    
    asw3 = tran(B);
    cout<<"#"<<asw1<<asw2<<asw3;
    
    return 0;
}

