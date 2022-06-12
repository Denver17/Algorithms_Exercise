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


int main()
{
    string str;     cin>>str;
    string res = str.substr(0, 3) + str.substr(4, 1);
    reverse(res.begin(), res.end());

    res.insert(res.begin() + 1, '.');

    cout<<res<<endl;

    return 0;
}
