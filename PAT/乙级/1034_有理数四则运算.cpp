#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct Fraction{
    long long up,down;
};

long long gcd(long long a,long long b){
    if(b == 0)  return a;
    else return gcd(b,a % b);
}

Fraction reduction(Fraction result){
    if(result.down < 0){
        result.up = -result.up;
        result.down = -result.down;
    }
    if(result.up == 0){
        result.down = 1;
    }else{
        int d = gcd(abs(result.up),abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}

void display(Fraction r){
    r = reduction(r);
    if(r.up < 0)    cout<<"(";
    if(r.down == 1) cout<<r.up;
    else if(abs(r.up) > r.down) cout<<r.up / r.down<<" "<<abs(r.up) % r.down<<"/"<<r.down;
    else cout<<r.up<<"/"<<r.down;
    if(r.up < 0)    cout<<")";
    return ;
}

void add(Fraction f1,Fraction f2){
    Fraction result;
    result.down = f1.down * f2.down;
    result.up = f1.up * f2.down + f2.up * f1.down;
    display(f1);
    cout<<" + ";
    display(f2);
    cout<<" = ";
    display(result);
    cout<<endl;
    return ;
}

void reduce(Fraction f1,Fraction f2){
    Fraction result;
    result.down = f1.down * f2.down;
    result.up = f1.up * f2.down - f2.up * f1.down;
    display(f1);
    cout<<" - ";
    display(f2);
    cout<<" = ";
    display(result);
    cout<<endl;
    return ;
}

void multi(Fraction f1,Fraction f2){
    Fraction result;
    result.down = f1.down * f2.down;
    result.up = f1.up * f2.up;
    display(f1);
    cout<<" * ";
    display(f2);
    cout<<" = ";
    display(result);
    cout<<endl;
    return ;
}

void divide(Fraction f1,Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    display(f1);
    cout<<" / ";
    display(f2);
    cout<<" = ";
    if(f2.up == 0){
        cout<<"Inf"<<endl;
        return ;
    }
    display(result);
    cout<<endl;
    return ;
}


int main()
{
    Fraction f1,f2;
    cin>>f1.up; getchar();  cin>>f1.down;
    cin>>f2.up; getchar();  cin>>f2.down;  
    
    add(f1,f2);
    reduce(f1,f2);
    multi(f1,f2);
    divide(f1,f2);

    return 0;
}

