#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int N;  scanf("%d", &N);
    double p;    scanf("%lf", &p);
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        scanf("%d", &vec[i]);
    }
    if(N == 1){
        if(p < 1)   printf("0");
        else    printf("1");
        return 0;
    }
    sort(vec.begin(), vec.end());
    int left = 0, right = 1;
    int asw = 0;
    while(right < vec.size()){
        double temp = (double)vec[right] / vec[left];
        if(temp <= p){
            if(right - left + 1 > asw)  asw = right - left + 1;
            right++;
        }
        else{
            left++;
        }
        if(left == right)   right++;
    }
    
    printf("%d", asw);

    return 0;
}

