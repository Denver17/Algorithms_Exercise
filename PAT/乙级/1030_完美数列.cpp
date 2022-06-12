#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int N;
    double p;     
    scanf("%d %lf", &N, &p);
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        scanf("%d", &vec[i]);
    }
    sort(vec.begin(), vec.end());

    if(N == 1){
        if(p < 1)   printf("0\n");
        else    printf("1\n");
        return 0;
    }

    int asw = 0;
    int left = 0, right = 1;
    while(right < vec.size()){
        double temp = (double)vec[right] / (double)vec[left];
        if(temp <= p){
            if(right - left + 1 > asw)  asw = right - left + 1;
            right++;
        }
        else{
            left++;
        }
        if(right == left)   right++;
    }

    printf("%d\n", asw);

    return 0;
}

