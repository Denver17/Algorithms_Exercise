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
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin>>vec[i];
    }
    int asw = 0;

    sort(vec.begin(), vec.end());
    for(int a = 0; a < n - 2; a++){
        for(int b = a + 1; b < n - 1; b++){
            for(int c = b + 1; c < n; c++){
                if(vec[a] + vec[b] <= vec[c] || vec[b] + vec[c] <= vec[a] || vec[a] + vec[c] <= vec[b]) continue;
                if(vec[a] + vec[b] + vec[c] > asw)  asw = vec[a] + vec[b] + vec[c];
            }
        }
    }
    
    cout<<asw<<endl;

    return 0;
}
