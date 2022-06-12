#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct mooncake{
    double inventory;
    double prices;
    double single_price;
};

bool cmp(mooncake a, mooncake b){
    if(a.single_price != b.single_price)    return a.single_price > b.single_price;
}


int main()
{
    int N, D;   cin>>N>>D;
    vector<mooncake> mk(N);
    for(int i = 0; i < N; i++){
        cin>>mk[i].inventory;
    }
    for(int i = 0; i < N; i++){
        cin>>mk[i].prices;
        mk[i].single_price = mk[i].prices / mk[i].inventory;
    }
    sort(mk.begin(), mk.end(), cmp);
    
    double asw = 0;
    int _count = 0;
    int ptr = 0;
    while(_count < D){
        if(ptr == mk.size())    break;
        int temp = mk[ptr].inventory;
        if(_count + temp <= D){
            asw += mk[ptr].prices;
            _count += temp;
        }
        else{
            int num = D - _count;
            asw += mk[ptr].single_price * num;
            _count += num;
        }
        ptr++;
    }

    printf("%.2f", asw);


    return 0;
}

