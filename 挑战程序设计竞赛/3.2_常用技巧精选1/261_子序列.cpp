//二分法
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
        for(int i = 0; res[i] + S <= res.back(); i++){
            int left = i, right = n;
            while(left < right - 1){
                int mid = left + (right - left) / 2;
                if(res[mid] - res[i] >= S)  right = mid;
                else    left = mid;
            }
            if(right - i < asw) asw = right - i;
        }
        cout<<asw<<endl;
    }
    

    return 0;
}
