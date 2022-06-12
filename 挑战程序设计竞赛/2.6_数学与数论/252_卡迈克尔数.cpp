#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int n;

int quickmod(int a, int b){
    if(b == 0)  return 1;
    else if(b == 1) return a;
    int num;
    if(b % 2 == 1)  return ((quickmod(a, b - 1) % n) * a) % n;
    else    num = quickmod(a, b / 2);
    return ((num % n) * (num % n)) % n;
}

bool isPrime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)  return false;
    }
    return true;
}

int main()
{
    while(cin>>n){
        if(n == 0)  break;
        bool flag = true;
        if(isPrime(n))  flag = false;
        for(int i = 2; i < n; i++){
            int res1 = quickmod(i, n) % n;
            if(res1 != i){
                flag = false;   break;
            }
        }
        if(flag)    cout<<"The number "<<n<<" is a Carmichael number."<<endl;
        else    cout<<n<<" is normal."<<endl;
    }

    return 0;
}
