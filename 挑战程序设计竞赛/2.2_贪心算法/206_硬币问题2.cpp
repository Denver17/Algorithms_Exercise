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
    int T;
    cin>>T;
    vector<int> values = {1, 5, 10, 50, 100, 500};
    for(int i = 0; i < T; i++){
        vector<int> vec(6);
        for(int j = 0; j < 6; j++){
            cin>>vec[j];
        }
        int A;
        cin>>A;
        int asw = 0;
        for(int j = 5; j >= 0; j--){
            int temp = min(A / values[j], vec[j]);
            A -= temp * values[j];
            asw += temp;
        }
        cout<<asw<<endl;
    }
    
    return 0;
}
