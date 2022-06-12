#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct bign{
    vector<int> d;
    int len;
    bool flag;
    bign(){
        d.resize(1e4,0);
        len = 0;
    }
};

bign change(string str){
    bign a;
    a.len = 0;
    if(str[0] == '-')   { a.flag = false; str.erase(0,1); }
    else    a.flag = true;
    for(int i = str.size() - 1; i >= 0; i--){
        a.d[a.len++] = str[i] - '0';
    }
    return a;
}

bign add(bign a, bign b){
    bign c;     c.len = 0;
    int carry = 0;
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

bign sub(bign a,bign b){
    bign c;     c.len = 0;
    for(int i = 0; i < a.len || i < b.len; i++){
        if(a.d[i] < b.d[i]){
            a.d[i+1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0){
        c.len--;
    }
    return c;
}

bool compare(bign a,bign b){
    if(a.len > b.len)   return true;
    else if(a.len < b.len)  return false;
    for(int i = a.len - 1; i >= 0; i--){
        if(a.d[i] > b.d[i]) return true;
        else if(a.d[i] < b.d[i])    return false;
    }
    return false;
}

bool query(bign a,bign b,bign c){
    bign sum;
    if(a.flag == true && b.flag == true)    { sum = add(a,b); sum.flag = true; }
    else if(a.flag == true && b.flag == false){
        if(compare(a,b)){
            sum = sub(a,b);
            sum.flag = true;
        }
        else{
            sum = sub(b,a);
            sum.flag = false;
        }
    } 
    else if(a.flag == false && b.flag == true){ 
        if(compare(a,b)){
            sum = sub(a,b);
            sum.flag = false;
        }
        else{
            sum = sub(b,a);
            sum.flag = true;
        }
    }
    else if(a.flag == false && b.flag == false) { sum = add(a,b); sum.flag = false; }
    
    // if(compare(sum,c))  return true;
    // return false;
    if(sum.flag == true && c.flag == false) return true;
    else if(sum.flag == false && c.flag == true)    return false;
    if(sum.flag && c.flag && compare(sum,c))    return true;
    if(!sum.flag && !c.flag && compare(c,sum))  return true;
    return false;
}

int main()
{
    int T;  cin>>T;
    for(int i = 0; i < T; i++){
        string A,B,C;   cin>>A>>B>>C;
        bign a = change(A);
        bign b = change(B);
        bign c = change(C);
        if(query(a,b,c))    cout<<"Case #"<<i+1<<": true"<<endl;
        else    cout<<"Case #"<<i+1<<": false"<<endl;
    }

    return 0;
}

