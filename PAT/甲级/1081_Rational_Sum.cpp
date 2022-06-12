#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct fraction{
    long long up,down;
};

fraction add(fraction a,fraction b){
    fraction res;
    res.down = a.down * b.down;
    res.up = a.up * b.down + a.down * b.up;
    return res;
}

long long gcd(long long a,long long b){
    if(b == 0)  return a;
    else    return gcd(b,a % b);
}

fraction reduction(fraction r){
    if(r.down < 0){
        r.up = -r.up;
        r.down = -r.down;
    }
    if(r.up == 0){
        r.down = 1;
    }
    else{
        long long d = gcd(abs(r.up),abs(r.down));
        r.up /= d;
        r.down /= d;
    }
    return r;
}

void display(fraction r){
    r = reduction(r);
    if(r.down == 1) cout<<r.up;
    else if(abs(r.up) > r.down){    //假分数
        cout<<r.up / r.down <<" "<<abs(r.up) % r.down<<"/"<<r.down;
    }
    else{   //真分数
        cout<<r.up<<"/"<<r.down;
    }
}

int main()
{
    int N;      cin>>N;
    fraction asw;
    asw.up = 0; asw.down = 1;
    for(int i = 0; i < N; i++){
        fraction temp;
        cin>>temp.up;
        getchar();
        cin>>temp.down;
        asw = add(asw,temp);
    } 

    display(asw);

    return 0;
}

