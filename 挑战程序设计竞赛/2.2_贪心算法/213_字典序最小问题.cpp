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
    int N;  cin>>N;
    vector<char> vec(N);
    for(int i = 0; i < N; i++){
        cin>>vec[i];
    }
    vector<char> asw;
    int left = 0, right = N - 1;
    while(left <= right){
        if(vec[left] < vec[right]){
            asw.push_back(vec[left]);
            left++;
        }
        else if(vec[left] > vec[right]){
            asw.push_back(vec[right]);
            right--;
        }
        else if(vec[left] == vec[right] && left == right){
            asw.push_back(vec[left]);
            break;
        }
        else{
            int temp_left = left + 1;
            int temp_right = right - 1;
            bool flag = true;   //为true选左边，为false选右边
            while(temp_left <= temp_right){
                if(vec[temp_left] == vec[temp_right]){
                    temp_left++;
                    temp_right--;
                }
                else if(vec[temp_left] < vec[temp_right]){
                    flag = true;
                    break;
                }
                else if(vec[temp_left] > vec[temp_right]){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                asw.push_back(vec[left]);
                left++;
            }
            else{
                asw.push_back(vec[right]);
                right--;
            }
        }
    }

    for(int i = 0; i < asw.size(); i++){
        cout<<asw[i];
        if(i % 80 == 79)   cout<<endl;
    }
    
    return 0;
}
