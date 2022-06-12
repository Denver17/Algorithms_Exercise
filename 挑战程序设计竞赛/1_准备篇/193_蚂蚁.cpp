#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
using namespace std;


int main()
{
    int T;
    cin>>T;
    for(int i = 0; i < T; i++){
        int L, n;   cin>>L>>n;
        vector<int> vec(n);
        for(int j = 0; j < n; j++){
            cin>>vec[j];
        }
        int asw_min = 0, asw_max = 0;
        sort(vec.begin(), vec.end());
        for(int j = 0; j < n; j++){
            if(vec[j] < L / 2)  asw_min = max(vec[j], asw_min);
            else    asw_min = max((L - vec[j]), asw_min);
        }
        for(int j = 0; j < n; j++){
            if(vec[j] < L / 2)  asw_max = max((L - vec[j]), asw_max);
            else    asw_max = max(vec[j], asw_max);
        }
        cout<<asw_min<<" "<<asw_max<<endl;
    }

    return 0;
}
