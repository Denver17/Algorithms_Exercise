#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct node{
    int addr;
    int data;
    int next;
};

vector<node> list(1e5 + 10);

int main()
{
    int L1, L2, N;  scanf("%d %d %d", &L1, &L2, &N);
    for(int i = 0; i < N; i++){
        int adr;    scanf("%d", &adr);
        list[adr].addr = adr;
        scanf("%d %d", &list[adr].data, &list[adr].next);
    }

    vector<node> l1;
    vector<node> l2;
    int start1 = L1;
    while(start1 != -1){
        l1.push_back(list[start1]);
        start1 = list[start1].next;
    }

    int start2 = L2;
    while(start2 != -1){
        l2.push_back(list[start2]);
        start2 = list[start2].next;
    }

    if(l1.size() < l2.size()){
        swap(l1, l2);
    }
    if(l1.size() > l2.size()){
        reverse(l2.begin(), l2.end());
    }

    vector<node> asw;
    int pos;
    for(pos = 0; pos < l2.size(); pos++){
        asw.push_back(l1[2 * pos]);
        asw.push_back(l1[2 * pos + 1]);
        asw.push_back(l2[pos]);
    }
    int _count = 2 * pos;
    while(_count < l1.size()){
        asw.push_back(l1[_count]);
        _count++;
    }
    for(int i = 0; i < asw.size(); i++){
        if(i != asw.size() -1){
            printf("%05d %d %05d\n", asw[i].addr, asw[i].data, asw[i + 1].addr);
        }
        else{
            printf("%05d %d %d\n", asw[i].addr, asw[i].data, -1);
        }
    }


    return 0;
}

