#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int a,b;    cin>>a>>b;
    int sum = a + b;
    string asw = to_string(sum);
   int pos = asw.size() - 3;
   while(pos > 0 && asw[pos-1] != '-'){
       asw.insert(pos,",");
       pos = pos - 3;
   }

    cout<<asw;

    return 0;
}

