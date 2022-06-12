#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    double R1,P1,R2,P2;
    cin>>R1>>P1>>R2>>P2;
    double A, B;
    A = R1 * R2 * (cos(P1) * cos(P2) - sin(P1) * sin(P2));
    B = R1 * R2 * (cos(P1) * sin(P2) + sin(P1) * cos(P2));
    string flag1 =  A >= -0.001 ? "" : "-"; 
    cout<<flag1;
    printf("%.2f", abs(A));
    string flag2 =  B >= -0.001 ? "+" : "-"; 
    cout<<flag2;
    printf("%.2fi", abs(B));
    return 0;
}

