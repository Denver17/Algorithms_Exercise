#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<stdlib.h>

using namespace std;


int main()
{
    int n, m;
    cin>>n>>m;

    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin>>vec[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                for(int l = 0; l < n; l++){
                    if(vec[i] + vec[j] + vec[k] + vec[l] == m){
                        cout<<"Yes"<<endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout<<"No"<<endl;
    return 0;
}
