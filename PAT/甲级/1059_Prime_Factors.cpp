#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

const long long maxn = 10000;
vector<int> prime;
vector<bool> p(maxn,false);

void FindPrime(){
    for(long long i = 2; i < maxn; i++){
        if(p[i] == false){
            prime.push_back(i);
            for(long long j = i + i; j < maxn; j += i){
                p[i] = true;
            }
        }
    }
    return ;
}

struct factor{
    long long x,_count;
}fac[100];

int main()
{
    FindPrime();
    long long N;    cin>>N;
    if(N == 1){
        cout<<"1=1";    return 0;
    }
    long long Ncopy = N;
    long long i = 0,num = 0;
    while(prime[i] <= (long long)sqrt(N * 1.0)){
        if(N % prime[i] == 0){
            fac[num].x = prime[i];
            fac[num]._count = 0;
            while(N % prime[i] == 0){
                fac[num]._count++;
                N /= prime[i];
            }
            num++;
        }
        i++;
    }
    if(N != 1){
        fac[num].x = N;
        fac[num]._count = 1;
        num++;
    }
    
    if(fac[0]._count == 1)
        cout<<Ncopy<<"="<<fac[0].x;
    else
        cout<<Ncopy<<"="<<fac[0].x<<"^"<<fac[0]._count;
    for(i = 1; i < num; i++){
        if(fac[i]._count == 1)
            cout<<"*"<<fac[i].x;
        else 
            cout<<"*"<<fac[i].x<<"^"<<fac[i]._count;
    }

    return 0;
}

