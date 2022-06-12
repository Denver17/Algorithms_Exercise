#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

struct people{
    string birthday;
    string name;
}p[100000];

int main()
{
    int N;
    cin>>N;
    int asw = 0;
    string young = "2014/09/06";
    string old = "1814/09/06";
    string oldest = young;
    string youngest = old;
    for(int i = 0; i < N; i++){
        cin>>p[i].name>>p[i].birthday;
        if(p[i].birthday >= old && p[i].birthday <= young){ 
            asw++;
            if(p[i].birthday < oldest)  oldest = p[i].birthday;
            if(p[i].birthday > youngest)    youngest = p[i].birthday;  
        }
    }

    if(asw == 0) { cout<<asw; return 0; }
    else cout<<asw<<" ";
    for(int i = 0; i < N; i++){
        if(p[i].birthday == oldest) cout<<p[i].name;
    }
    cout<<" ";
    for(int i = 0; i < N; i++){
        if(p[i].birthday == youngest)   cout<<p[i].name;
    }
    


    return 0;
}
