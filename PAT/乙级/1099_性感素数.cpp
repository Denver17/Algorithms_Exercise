//不要忘记加根号前面的等于号
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

bool isPrime(int num){
    if(num <= 1)    return false;
    if(num == 2)    return true;
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0)    return false;
    }
    return true;
}

bool isSex(int num){
    if(isPrime(num) == false)   return false;
    if(isPrime(num - 6) || isPrime(num + 6))    return true;
    return false;
}

int main()
{
    int N;  cin>>N;
    if(isPrime(N) == false){
        while(isSex(++N) == false);
        printf("No\n");
        printf("%d",N);
        return 0;
    }
   
    if(isSex(N) == true){
        if(isSex(N - 6) == true){
            printf("Yes\n");
            printf("%d", N - 6);
        }
        else if(isSex(N + 6) == true){
            printf("Yes\n");
            printf("%d", N + 6);
        }
    }
    else{
        while(isSex(++N) == false);
        printf("No\n");
        printf("%d",N);
    }
    

    return 0;
}

