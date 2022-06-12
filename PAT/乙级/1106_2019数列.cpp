#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int N;  cin>>N;
    vector<int> vec = {2, 0, 1, 9};
    for(int i = 4; i < N; i++){
        vec.push_back( (vec[i - 1] + vec[i - 2] + vec[i - 3] + vec[i - 4]) % 10 );
    }
    for(int i = 0; i < N; i++){
        cout<<vec[i];
    }

    return 0;
}

