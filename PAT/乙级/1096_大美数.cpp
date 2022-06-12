#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool judge(vector<int> &vec, int num){
    if(vec.size() < 4)  return false;
    for(int a = 0; a < vec.size(); a++){
        for(int b = a + 1; b < vec.size(); b++){
            for(int c = b + 1; c < vec.size(); c++){
                for(int d = c + 1; d < vec.size(); d++){
                    if((vec[a] + vec[b] + vec[c] + vec[d]) % num == 0){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    int K;  cin>>K;
    for(int i = 0; i < K; i++){
        vector<int> vec;
        int num;    cin>>num;
        for(int j = 1; j <= num; j++){
            if(num % j == 0)    vec.push_back(j);
        }
        
        if(judge(vec, num)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
    return 0;
}

