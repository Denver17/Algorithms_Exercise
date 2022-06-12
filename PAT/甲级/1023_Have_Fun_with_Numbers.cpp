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
    for(int i = str.size() - 1; i >= 0; i--){
        a.d[a.len++] = str[i] - '0';
    }
    return a;
}

bign multi(bign a,int b){
    bign c;
    int carry = 0;
    for(int i = 0; i < a.len; i++){
        int temp = b * a.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while(carry != 0){
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}

void print(bign a){
    for(int i = a.len - 1; i >= 0; i--) printf("%d",a.d[i]);
    return ;
}

int main()
{
    string str;     cin>>str;
    bign a = change(str);
    bign c = multi(a,2);
    int hashTable1[10] = {0},hashTable2[10] = {0};
    for(int i = 0; i < a.len; i++){
        hashTable1[a.d[i]]++;
    }
    for(int i = 0; i < c.len; i++){
        hashTable2[c.d[i]]++;
    }
    for(int i = 0; i < 10; i++){
        if(hashTable1[i] != hashTable2[i]){
            printf("No\n");
            print(c);
            return 0;
        }
    }
    printf("Yes\n");
    print(c);

    return 0;
}

