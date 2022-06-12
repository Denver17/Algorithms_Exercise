#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

bool check(vector<int> vec,int M,int N){
    int vptr = 0;   
    stack<int> st;
    for(int i = 1; i <= N; i++){
        st.push(i);
        if(st.size() > M)   return false;
        while(!st.empty() && st.top() == vec[vptr]){
            st.pop();   vptr++;
        }
    }
    if(st.empty())  return true;
    return false;
}


int main()
{
    int M,N,K;  cin>>M>>N>>K;   //M为栈容量，N为序列长，K为需解决问题个数
    for(int i = 0; i < K; i++){
        vector<int> vec(N);
        for(int j = 0; j < N; j++){
            cin>>vec[j];
        }
        if(check(vec,M,N))  cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
    }
    
    return 0;
}

