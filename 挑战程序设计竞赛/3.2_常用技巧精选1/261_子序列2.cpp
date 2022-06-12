//滑动窗口
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
    int T;  scanf("%d", &T);
    while(T--){
        int n, S;   scanf("%d %d", &n, &S);
        vector<int> vec(n);
        for(int i = 0; i < n; i++)  scanf("%d", &vec[i]);
        vector<int> res(n, 0);
        res[0] = vec[0];
        for(int i = 1; i < n; i++)  res[i] = res[i - 1] + vec[i];
        if(res.back() < S){
            printf("0\n");
            continue;
        }
        int asw = n;
        int left = 0, right = 0;
        while(right < res.size()){
            if(res[right] - res[left] >= S){
                if(right - left < asw)  asw = right - left;
                left++;
            }
            else{
                right++;
            }
        }
        cout<<asw<<endl;
    }

    return 0;
}
