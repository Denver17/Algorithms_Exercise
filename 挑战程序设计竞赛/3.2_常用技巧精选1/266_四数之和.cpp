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
    int n;  cin>>n;
    vector<int> A(n), B(n), C(n), D(n);
    for(int i = 0; i < n; i++){
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }
    vector<int> res;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res.push_back(C[i] + D[j]);
        }
    }
    sort(res.begin(), res.end());
    int asw = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int left1 = -1, right1 = n * n;
            while(left1 < right1 - 1){
                int mid = left1 + (right1 - left1) / 2;
                if(A[i] + B[j] + res[mid] >= 0)  right1 = mid;
                else if(A[i] + B[j] + res[mid] < 0) left1 = mid;
            }
            if(right1 == n * n || A[i] + B[j] + res[right1] != 0)     continue;
            int left2 = -1, right2 = n * n;
            while(left2 < right2 - 1){
                int mid = left2 + (right2 - left2) / 2;
                if(A[i] + B[j] + res[mid] > 0)  right2 = mid;
                else    left2 = mid;
            }
            if(left2 == -1)     continue;
            asw += (left2 - right1 + 1);
        }
    }
    cout<<asw<<endl;

    return 0;
}
