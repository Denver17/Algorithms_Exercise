#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

int main()
{
    int N, M;   cin>>N>>M;
    for(int i = 0; i < N; i++){
        double G2;  cin>>G2;
        vector<double> vec;
        for(int j = 0; j < N - 1; j++){
            double num; cin>>num;
            if(num < 0 || num > M)  continue;
            vec.push_back(num);
        }
        double res = 0;
        double _max = -1, _min = M + 1;
        for(int j = 0; j < vec.size(); j++){
            if(vec[j] > _max)   _max = vec[j];
            if(vec[j] < _min)   _min = vec[j];
        }
        for(int j = 0; j < vec.size(); j++){
            if(vec[j] == _max){
                vec.erase(vec.begin() + j);
                break;
            }
        }
        for(int j = 0; j < vec.size(); j++){
            if(vec[j] == _min){
                vec.erase(vec.begin() + j);
                break;
            }
        }
        
        for(int j = 0; j < vec.size(); j++) res += vec[j];
        res = res / vec.size();
        res = (res + G2) / 2;
        int asw = round(res);
        cout<<asw<<endl; 
    }


    return 0;
}

