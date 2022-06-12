//素数可能会很大所以打表不太好使，直接根号n判断就行
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<stdlib.h>
#include<cmath>
using namespace std;

const int maxn = 1e6 + 10;
vector<bool> p(maxn,false);
set<int> prime;

void getPrime(){
    for(int i = 2; i < maxn; i++){
        if(p[i] == false){
            prime.insert(i);
            for(int j = i; j < maxn; j += i){
                p[j] = true;
            }
        }
    }
}

bool isPrime(int num){
    if(num <= 1)    return false;
    if(num == 2)    return true;
    for(int i = 2; i < sqrt(num); i++){
        if(num % i == 0)    return false; 
    }
    return true;
}


int main()
{
    //getPrime();
    int L,K;    scanf("%d %d", &L, &K);
    string str; str.resize(L);
    scanf("%s", str.c_str());
    int left = 0, right = K - 1;
    while(right < L){
        int num = atoi(str.substr(left, K).c_str());
        if(isPrime(num)){
            string snum = to_string(num);
            if(snum.size() < K){
                reverse(snum.begin(), snum.end());
                snum.append(K - snum.size(), '0');
                reverse(snum.begin(), snum.end());
            }
            printf("%s", snum.c_str());
            return 0;
        }
        left++; right++;
    }
    printf("404");

    return 0;
}

