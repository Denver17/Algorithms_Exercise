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

int gcd(int a, int b){
    if(b == 0)  return a;
    return gcd(b, a % b);
}

int main()
{
    int x1, y1, x2, y2;     cin>>x1>>y1>>x2>>y2;
    int a = abs(x1 - x2), b = abs(y1 - y2);
    
    if(a == 0 && b == 0)    cout<<0<<endl;
    else    cout<<gcd(a, b) - 1<<endl;

    return 0;
}
