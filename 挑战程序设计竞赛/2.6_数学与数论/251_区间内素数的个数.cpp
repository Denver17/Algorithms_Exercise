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

const long long MAXN = 1000000 + 10;
vector<bool> p(MAXN, true);

int main()
{
    long long a, b;   cin>>a>>b;
    p[1] = false;
    for(int i = 2; i <= sqrt(b); i++){
        if(p[i] == true){
            for(int j = 2 * i; j <= sqrt(b); j += i){
                p[j] = false;
            }
        }
    }

    vector<int> prime;
    for(int i = 2; i <= sqrt(b); i++){
        if(p[i] == true)    prime.push_back(i);
    }

    int asw = 0;
    for(long long i = a; i <= b; i++){
        int j;
        for(j = 0; j < prime.size(); j++){
            //i为素数倍数时不为素数，等于素数时就是素数了
            if(i % (long long)prime[j] == 0 && i != (long long)prime[j])   break;
        }
        if(j == prime.size()){
            asw++;
        }
    }

    cout<<asw<<endl;

    return 0;
}
