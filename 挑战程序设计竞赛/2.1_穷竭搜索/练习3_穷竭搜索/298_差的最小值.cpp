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

const int INF = 0x3f3f3f3f;

int asw = INF;

int main()
{
    int T;  cin>>T;
    getchar();
    while(T--){
        string str;     getline(cin, str);
        vector<int> vec;
        for(int i = 0; i < str.size(); i++){
            if(str[i] != ' '){
                vec.push_back(int(str[i] - '0'));
            }
        }
        sort(vec.begin(), vec.end());

        if(vec.size() == 2){
            cout<<abs(vec[0] - vec[1])<<endl;
            continue;
        }

        while(vec[0] == 0){
            next_permutation(vec.begin(), vec.end());
        }

        do{
            int mid = (vec.size() + 1) / 2;
            if(vec[mid]){
                int sum1 = 0, sum2 = 0;
                for(int i = 0; i < mid; i++){
                    sum1 = sum1 * 10 + vec[i];
                }
                for(int i = mid; i < vec.size(); i++){
                    sum2 = sum2 * 10 + vec[i];
                }
                asw = min(asw, abs(sum1 - sum2));
            }
        }while(next_permutation(vec.begin(), vec.end()));
        cout<<asw<<endl;
        asw = INF;
    }

    return 0;
}
