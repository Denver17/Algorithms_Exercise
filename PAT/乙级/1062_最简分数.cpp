#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int gcd(int a, int b){
    if(b == 0)  return a;
    else    return gcd(b, a % b);
}

int main()
{
    int N1, M1, N2, M2, K;
    scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);
    //int ptr = min(K * N1 / M1, K * N2 / M2);
    int ptr = 1;
    double _max = max((double)N1 / M1, (double)N2 / M2);
    double _min = min((double)N1 / M1, (double)N2 / M2);
    bool flag = false;
    while((double)ptr / K <= _min)  ptr++;
    while((double)ptr / K < _max){
        if(gcd(ptr, K) == 1 && flag == true)   printf(" %d/%d", ptr, K);
        else if(gcd(ptr, K) == 1 && flag == false){
            printf("%d/%d", ptr, K);
            flag = true;
        }
        ptr++;
    }
    
    return 0;
}

