#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;

int main()
{
    int A, D;   cin>>A>>D;
    double asw;
    string str = to_string(A);
    reverse(str.begin(), str.begin() + str.size() - D);
    reverse(str.begin() + str.size() - D, str.end());
    reverse(str.begin(), str.end()); 
    int B = atoi(str.c_str());
    asw = (double)B / A;
    printf("%.2f",asw);

    return 0;
}

