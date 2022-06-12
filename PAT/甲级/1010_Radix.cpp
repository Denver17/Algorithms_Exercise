#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<limits>
using namespace std;

int getnum(char c){
    if(c >= '0' && c <= '9')    return (int)(c - '0');
    else if(c >= 'a' && c <= 'z')   return (int)(c - 'a' + 10);
    return -1;
}

long long change(string num, int radix){
    long long res = 0;
    reverse(num.begin(), num.end());
    for(int i = 0; i < num.size(); i++){
        res += (long long)pow(radix, i) * getnum(num[i]);
    }
    return res;
}

long long getlow(string target){
    long long res = 0;
    for(int i = 0; i < target.size(); i++){
        int temp;
        if(target[i] >= 'a' && target[i] <= 'z')    temp = (int)(target[i] - 'a' + 10);
        else if(target[i] >= '0' && target[i] <= '9')   temp = (int)(target[i] - '0');
        else    temp = -1;
        if(temp > res)  res = temp;
    }
    return res + 1;
}

int main()
{
    string N1, N2;
    int tag, radix;
    cin>>N1>>N2>>tag>>radix;

    string num = (tag == 1 ? N1 : N2);
    string target = (tag == 1 ? N2 : N1);

    long long decnum = change(num, radix);
    long long left = getlow(target);
    long long right = max(left, decnum);
    while(left <= right){
        long long mid = left + (right - left) / 2;
        if(decnum > change(target, mid) && change(target, mid) >= 0){
            left = mid + 1;
        }
        else if(decnum < change(target, mid) || change(target, mid) < 0){
            right = mid - 1;
        }
        else{
            printf("%d\n", mid);
            return 0;
        }
    }
    
    printf("Impossible\n");

    return 0;
}

