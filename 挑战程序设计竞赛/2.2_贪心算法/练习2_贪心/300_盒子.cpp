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

int u[4] = {0, 5, 3, 1};    //当6*6中没有3*3时，新箱子，先不考虑放2*2
//当6*6中有一个3*3时，可以放5个2*2
//当6*6中有两个3*3时，可以放3个2*2
//当6*6中有三个3*3时，可以放1个2*2

int main()
{
    int a, b, c, d, e, f;
    while(cin>>a>>b>>c>>d>>e>>f){
        if(a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)    break;
        int asw = 0;
        int x, y;   //x和y分别代表2*2和1*1空间的剩余数目
        asw = f + e + d + (c + 3) / 4;
        y = d * 5 + u[c % 4];
        
        if(b > y)   asw += (b - y + 8) / 9;
        x = 36 * asw - 36 * f - 25 * e - 16 * d - 9 * c - 4 * b;
        if(a > x)   asw += (a - x + 35) / 36;
        cout<<asw<<endl;
    }
    
    return 0;
}