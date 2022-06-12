#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    long long N;  cin>>N;
    int left = 2, right = 2;
    vector<long long> asw;
    while(right <= sqrt(N)){
        //right = left;
        int res = 1;
        for(int i = left; i <= right; i++)  res = res * i;
        if(N % res == 0){
            if(right - left + 1 > asw.size()){
                asw.clear();
                for(int j = left; j <= right; j++){
                    asw.push_back(j);
                }
            }
            right++;
        }
        else{
            left++;
            right = left;
        }
    }

    if(asw.size() == 0) asw.push_back(N);

    cout<<asw.size()<<endl;
    for(int i = 0; i < asw.size(); i++){
        if(i != 0) cout<<"*"<<asw[i];
        else    cout<<asw[i];
    }

    return 0;
}

