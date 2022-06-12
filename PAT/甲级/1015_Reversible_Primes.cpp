#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

string conversion(int num,int radix){
    string asw = "";
    do{
        int temp = num % radix;
        if(temp >= 0 && temp <= 9)  asw += temp + '0';
        else    asw += temp - 10 + 'a';
        num /= radix;
    }while(num != 0);
    reverse(asw.begin(),asw.end());
    return asw;
}

bool isPrime(int N){
    if(N <= 1)  return false;               //注意1不是素数
    int range = (int)sqrt(N * 1.0);
    for(int i = 2; i <= range; i++){        //等于号注意
        if(N % i == 0)  return false;
    }
    return true;
}

bool reconversion(string str,int radix){
    int sum = 0;
    for(int i = 0; i < str.size(); i++){
        sum = sum*radix + str[i] - '0';
    }
    return isPrime(sum);
}

bool isRPrime(int N,string str,int radix){
    if(!isPrime(N))  return false;
    reverse(str.begin(),str.end());
    return reconversion(str,radix);
}


int main()
{
    int N,D;
    while(cin>>N && N >= 0){
        cin>>D;
        string str = conversion(N,D);
        if(isRPrime(N,str,D))   cout<<"Yes"<<endl;
        else    cout<<"No"<<endl;
    }
    

    return 0;
}

