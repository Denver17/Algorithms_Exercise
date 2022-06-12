#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct bign{
    vector<int> d;
    int len;
    bign(){
        len = 0;
    }
};
 
bign change(string str){
    bign a;
    a.len = str.size();
    for(int i = str.size() - 1; i >= 0; i--){
        a.d.push_back((int)(str[i] - '0'));
    }
    return a;
}

string rechange(bign a){
    string str;
    //str.resize(a.len);
    for(int i = a.d.size() - 1; i >= 0; i--){
        str.push_back((char)(a.d[i] + '0'));
    }
    return str;
}

bool isPalindromic(string str){
    if(str.size() == 0) return false;
    for(int i = 0; i < str.size() / 2; i++){
        if(str[i] != str[str.size() - i - 1])   return false;
    }
    return true;
}

bign add(bign a, bign b){
    bign c; int carry = 0;
    for(int i = 0; i < a.len || i < b.len; i++){
        int temp = a.d[i] + b.d[i] + carry;
        c.d.push_back(temp % 10);
        carry = temp / 10;
        c.len++;
    }
    if(carry != 0){
        c.d.push_back(carry);
        c.len++;
    }
    return c;
}


int main()
{
    string str;     cin>>str;
    if(isPalindromic(str)){
        cout<<str<<" is a palindromic number."<<endl;
        return 0;
    }
    for(int i = 0; i < 10; i++){
        string reverse_str = str;
        reverse(reverse_str.begin(), reverse_str.end());
        bign a = change(str), b = change(reverse_str);
        bign tmpsum = add(a, b);
        string sum = rechange(tmpsum);
        cout<<str<<" + "<<reverse_str<<" = "<<sum<<endl;
        if(isPalindromic(sum)){
            cout<<sum<<" is a palindromic number."<<endl;
            return 0;
        }
        str = sum;
    }
    cout<<"Not found in 10 iterations."<<endl;

    return 0;
}

