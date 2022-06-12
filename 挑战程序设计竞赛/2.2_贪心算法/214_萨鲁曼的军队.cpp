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
    int R, N;
    while(cin>>R>>N){
        if(R == -1 && N == -1)  break;
        vector<int> vec(N);
        for(int i = 0; i < N; i++){
            cin>>vec[i];
        }
        sort(vec.begin(), vec.end());
        int asw = 1;
        int left = vec[0];
        int cur = vec[0];
        for(int i = 1; i < N; i++){
            if(vec[i] - left <= R){
                cur = vec[i];
            }
            else{
                if(cur + R >= vec[i])   continue;
                else{
                    asw++;
                    left = vec[i];
                    cur = vec[i];
                }
            }
        }
        cout<<asw<<endl;
    }
    

    return 0;
}
