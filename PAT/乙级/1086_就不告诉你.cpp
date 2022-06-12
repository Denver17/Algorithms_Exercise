#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int A, B;   cin>>A>>B;
    int res = A * B;
    string asw = to_string(res);
    reverse(asw.begin(), asw.end());
    cout<<atoi(asw.c_str())<<endl;

    return 0;
}

