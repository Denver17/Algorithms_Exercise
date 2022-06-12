#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

const int maxn = 100010;

struct node{
    char data;
    int next;
    bool flag = false;
}List[maxn];

int main()
{
    int addr1,addr2,N;  cin>>addr1>>addr2>>N;
    for(int i = 0; i < N; i++){
        int adr;    cin>>adr;
        cin>>List[adr].data>>List[adr].next;
    }
    int adr1 = addr1;
    while(adr1 != -1){
        List[adr1].flag = true;
        adr1 = List[adr1].next;
    }
    int adr2 = addr2;
    while(adr2 != -1){
        if(List[adr2].flag == true){
            printf("%05d",adr2);
            return 0;
        }
        adr2 = List[adr2].next;
    }
    cout<<"-1";

    return 0;
}

