#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

struct number{
    int n;
    int A;
};

int gcd(int a, int b){
    if(b == 0)  return a;
    else return gcd(b, a % b);
}

bool isValid(int num){
    if(num <= 2)    return false;
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0)    return false;
    }
    return true;
}

bool cmp(number a, number b){
    if(a.n != b.n)  return a.n < b.n;
    return a.A < b.A;
}

int main()
{
    int N;  cin>>N;
    for(int i = 0; i < N; i++){
        int K, m;   cin>>K>>m;
        cout<<"Case "<<i + 1<<endl;
        vector<long long> vec;
        long long num = pow(10, K - 1) + 99;
        while(num < pow(10, K)){
            int sum = 0;
            long long temp = num;
            while(temp != 0){
                sum += temp % 10;
                temp = temp / 10;
            }
            if(sum == m)    vec.push_back(num);
            num += 100;
        }
        vector<number> ns;
        for(int j = 0; j < vec.size(); j++){
            long long temp = vec[j] + 1;
            int n = 0;
            while(temp != 0){
                n += temp % 10;
                temp = temp / 10;
            }
            if(isValid(gcd(n, m))){
                number temp;    temp.n = n; temp.A = vec[j];
                ns.push_back(temp);
            }
        }
        sort(ns.begin(), ns.end(), cmp);
        if(ns.size() == 0){
            cout<<"No Solution"<<endl;
            continue;
        }
        
        for(int j = 0; j < ns.size(); j++){
            cout<<ns[j].n<<" "<<ns[j].A<<endl;
        }
    }

    return 0;
}

