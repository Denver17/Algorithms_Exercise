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

bool Judge(int n){
    if(n <= 1)  return false;
    else if(n == 2) return true;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)  return false;
    }
    return true;
}

int main()
{
    int n;  cin>>n;
    if(Judge(n))    cout<<"Yes"<<endl;
    else    cout<<"No"<<endl;

    return 0;
}
