//有两个点超时不知道为什么，用sort直接做可以轻松过
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    int N;  cin>>N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++)  cin>>vec[i];

    int left = 0, right = vec.size() - 1;
    bool flag = true;
    while(flag){
        int pivot = vec[left];
        while(left < right){
            while(right > left && vec[right] >= pivot) right--;
            vec[left] = vec[right];
            while(right > left && vec[left] <= pivot)  left++;
            vec[right] = vec[left];
        }
        
        vec[left] = pivot;
        if(left < vec.size() / 2){
            left++;     right = vec.size() - 1;
        }
        else if(left > vec.size() / 2){
            right--;    left = 0;
        }
        else    flag = false;
    }

    int res = (vec.size() % 2 == 0) ? 0 : 1;
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < vec.size() / 2; i++){
        sum1 += vec[i];
    }
    for(int i = vec.size() / 2; i < vec.size(); i++){
        sum2 += vec[i];
    }

    cout<<res<<" "<<abs(sum2 - sum1)<<endl;

    return 0;
}

