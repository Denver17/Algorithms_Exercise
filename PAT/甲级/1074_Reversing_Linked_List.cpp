#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

const int maxn = 100010;

struct node{
    int data;
    int next;
    int pos;
}List[maxn];


int main()
{
    int addr,N,K;   cin>>addr>>N>>K;
    for(int i = 0; i < N; i++){
        int adr;    cin>>adr;
        List[adr].pos = adr;
        cin>>List[adr].data>>List[adr].next;
    }
    int temp = addr;
    vector<node> vec;
    while(temp != -1){
        vec.push_back(List[temp]);
        temp = List[temp].next;
    }
    for(int i = 0; i*K + K <= vec.size(); i++){     //这里不能用N，而要用vec.size()
        reverse(vec.begin() + i*K,vec.begin() + i*K + K);
    }
    vec.back().next = -1;
    for(int i = vec.size() - 1; i > 0; i--){
        vec[i-1].next = vec[i].pos;
    }
    for(int i = 0; i < vec.size()-1; i++){
        printf("%05d %d %05d\n",vec[i].pos,vec[i].data,vec[i].next);
    }
    printf("%05d %d %d",vec.back().pos,vec.back().data,vec.back().next);

    return 0;
}

