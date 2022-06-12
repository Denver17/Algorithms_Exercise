#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

struct bign{
    int d[1000];
    int len;
    bign(){
        memset(d,0,sizeof(d));
        len = 0;
    }
};

bign change(string str){
    bign a;
    int size = str.size();
    for(int i = size - 1; i >= 0; i--){
        a.d[a.len++] = str[i] - '0';   
    }
    return a;
}

bign divide(bign a,int b,int &r){
    bign c;     c.len = a.len;
    for(int i = a.len - 1; i >= 0; i--){
        r = r * 10 + a.d[i];
        if(r < b)   c.d[i] = 0;
        else{
            c.d[i] = r / b;
            r = r % b;
        }
    }
    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0){
        c.len--;
    }
    return c;
}

void print(bign a){
    for(int i = a.len - 1; i >= 0; i--) printf("%d",a.d[i]);
    return ;
}

int main()
{
    string A;   int B;
    cin>>A;     cin>>B;
    bign a = change(A);
    int r = 0;
    print(divide(a,B,r));
    printf(" %d",r);
    return 0;
}

