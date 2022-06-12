#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct Fraction{
    long long up, down;
};

long long gcd(long long a, long long b){
    if(b == 0)  return a;
    else    return gcd(b, a % b);
}

Fraction reduction(Fraction f){
    if(f.down < 0){
        f.down = -f.down;
        f.up = -f.up;
    }

    if(f.up == 0)   f.down = 1;
    else{
        long long d = gcd(abs(f.up), abs(f.down));
        f.up = f.up / d;
        f.down = f.down / d;
    } 
    return f;
}

void showResult(Fraction f){
    f = reduction(f);
    if(f.up < 0)    printf("(");
    if(f.down == 1) printf("%lld", f.up);
    else{
        if(abs(f.up) > f.down)   printf("%d %d/%d", f.up / f.down, abs(f.up) % f.down, f.down);
        else    printf("%d/%d", f.up, f.down);
    }
    if(f.up < 0)    printf(")");
    return ;
}

Fraction add(Fraction f1, Fraction f2){
    Fraction asw;
    asw.down = f1.down * f2.down;
    asw.up = f1.up * f2.down + f1.down * f2.up;
    return asw;
}

Fraction reduce(Fraction f1, Fraction f2){
    Fraction asw;
    asw.down = f1.down * f2.down;
    asw.up = f1.up * f2.down - f1.down * f2.up;
    return asw;
}

Fraction multi(Fraction f1, Fraction f2){
    Fraction asw;
    asw.up = f1.up * f2.up;
    asw.down = f1.down * f2.down;
    return asw;
}

Fraction divide(Fraction f1, Fraction f2){
    Fraction asw;
    asw.up = f1.up * f2.down;
    asw.down = f1.down * f2.up;
    return asw;
}


int main()
{
    Fraction f1, f2;
    scanf("%lld/%lld %lld/%lld", &f1.up, &f1.down, &f2.up, &f2.down);

    //Fraction nf1 = reduction(f1);
    //Fraction nf2 = reduction(f2);

    showResult(f1);
    printf(" + ");
    showResult(f2);
    printf(" = ");
    showResult(add(f1, f2));
    printf("\n");

    showResult(f1);
    printf(" - ");
    showResult(f2);
    printf(" = ");
    showResult(reduce(f1, f2));
    printf("\n");

    showResult(f1);
    printf(" * ");
    showResult(f2);
    printf(" = ");
    showResult(multi(f1, f2));
    printf("\n");

    showResult(f1);
    printf(" / ");
    showResult(f2);
    printf(" = ");
    if(f2.up == 0)
        printf("Inf");
    else
        showResult(divide(f1, f2));
    printf("\n");


    return 0;
}

