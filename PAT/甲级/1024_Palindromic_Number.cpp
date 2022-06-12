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

bign add(bign a,bign b){
    int carry = 0;
    bign c;
    for(int i = 0; i < a.len || i < b.len; i++){
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if(carry != 0){
        c.d[c.len++] = carry;
    }
    return c;
}

bign change(string str){
    bign a;
    for(int i = str.size() - 1; i >= 0; i--){
        a.d[a.len++] = str[i] - '0';
    }
    return a;
}

bign _reverse(bign a){
    int left = 0,right = a.len - 1;
    while(left < right){
        int temp = a.d[left];
        a.d[left] = a.d[right];
        a.d[right] = temp;
        left++; right--;
    }
    return a;
}

bool isPNumber(bign a){
    int left = 0,right = a.len - 1;
    while(left < right){
        if(a.d[left] != a.d[right]) return false;
        left++; right--;
    }
    return true;
}

void print(bign a){
    for(int i = a.len - 1; i >= 0; i--) cout<<a.d[i];
    return ;
}

int main()
{
    string N;   int K;
    cin>>N;     cin>>K;
    bign a = change(N);
    int step = 0;
    while(!isPNumber(a) && step < K){
        bign b = _reverse(a);
        a = add(a,b);
        step++;
    }
    print(a);
    cout<<endl;
    cout<<step;    

    return 0;
}

