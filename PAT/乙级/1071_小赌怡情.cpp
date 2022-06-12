#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int T, K;   cin>>T>>K;
    for(int i = 0; i < K; i++){
        int n1, b, t, n2;   cin>>n1>>b>>t>>n2;
        if(t > T)   printf("Not enough tokens.  Total = %d.\n",T);
        else{
            if(n2 > n1 && b == 1){
                T += t;
                printf("Win %d!  Total = %d.\n", t, T);
            }
            else if( n2 < n1 && b == 0){
                T += t;
                printf("Win %d!  Total = %d.\n", t, T);
            }
            else if(n2 > n1 && b == 0){
                T -= t;
                printf("Lose %d.  Total = %d.\n", t, T);
            }
            else if(n2 < n1 && b == 1){
                T -= t;
                printf("Lose %d.  Total = %d.\n", t, T);
            }
            if(T <= 0){
                printf("Game Over.\n");
                break;
            }
        }
    }

    return 0;
}

