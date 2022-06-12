#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct person{
    string id;
    string sign_in;
    string sign_out;
};

bool cmp1(person a,person b){
    if(a.sign_in != b.sign_in)  return a.sign_in < b.sign_in;   
}

bool cmp2(person a,person b){
    if(a.sign_out != b.sign_out)    return a.sign_out > b.sign_out;
}

int main()
{
    int M;  cin>>M;
    person per[M];
    for(int i = 0; i < M; i++){
        cin>>per[i].id>>per[i].sign_in>>per[i].sign_out;
    }  
    
    sort(per,per+M,cmp1);

    cout<<per[0].id<<" ";

    sort(per,per+M,cmp2);

    cout<<per[0].id;


    return 0;
}

