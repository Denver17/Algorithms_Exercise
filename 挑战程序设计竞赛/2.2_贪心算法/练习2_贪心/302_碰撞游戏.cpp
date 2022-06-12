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

int n;
vector<double> vec;

int main()
{
    cin>>n;
    vec.resize(n);
    priority_queue<double, vector<double>> que;
    for(int i = 0; i < n; i++){
        cin>>vec[i];
        que.push(vec[i]);
    }
    while(que.size() > 1){
        double m1 = que.top();      que.pop();
        double m2 = que.top();      que.pop();
        double m = 2 * sqrt(m1 * m2);
        que.push(m);
    }
    printf("%.3f\n", que.top());

    return 0;
}