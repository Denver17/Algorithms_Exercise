#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

const int maxn = 100010;

struct node{
    int addr;
    int key;
    int next;
}List[maxn];

int main()
{
    int begin,N;    cin>>begin>>N;
    for(int i = 0; i < N; i++){
        int temp;   cin>>temp;
        cin>>List[temp].key>>List[temp].next;
        List[temp].addr = temp;
    }
    vector<node> list1,list2;
    map<int,int> mp;
    int adr = begin;
    while(adr != -1){
        mp[abs(List[adr].key)] = 1;
        adr = List[adr].next;
    }
    adr = begin;
    while(adr != -1){
        if(mp[List[adr].key] == 1 || mp[-List[adr].key] == 1){
            list1.push_back(List[adr]);
            mp[abs(List[adr].key)] = 2;
        }
        else if(mp[List[adr].key] == 2 || mp[-List[adr].key] == 2){
            list2.push_back(List[adr]);
        }
        adr = List[adr].next;
    }
    for(int i = 0; i < list1.size()-1; i++){
        printf("%05d %d %05d\n",list1[i].addr,list1[i].key,list1[i+1].addr);
    }
    printf("%05d %d %d\n",list1.back().addr,list1.back().key,-1);

    if(list2.size() == 0){
        return 0;
    }
    for(int i = 0; i < list2.size()-1; i++){
        printf("%05d %d %05d\n",list2[i].addr,list2[i].key,list2[i+1].addr);
    }
    printf("%05d %d %d\n",list2.back().addr,list2.back().key,-1);

    return 0;
}

