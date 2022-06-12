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

typedef pair<int, int> P;   //weight, value
vector<P> vec;

bool judge(double x, int k){
    vector<double> res;
    for(int i = 0; i < vec.size(); i++){
        res.push_back(vec[i].second - x * vec[i].first);
    }
    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    double asw = 0;
    for(int i = 0; i < k; i++)  asw += res[i];
    if(asw >= 0)    return true;
    else    return false;
}

int main()
{
    int n, k;   scanf("%d %d", &n, &k);
    vec.resize(n);
    for(int i = 0; i < n; i++)  scanf("%d %d", &vec[i].first, &vec[i].second);
    double left = 0, right = 1e6 + 1;
    for(int i = 0; i < 100; i++){
        double mid = left + (right - left) / 2;
        if(judge(mid, k))  left = mid;
        else    right = mid;
    }
    printf("%.2f", left);
    return 0;
}
