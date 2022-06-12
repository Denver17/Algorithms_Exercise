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
    int n, k;   cin>>n>>k;
    vector<int> vec(n);
    for(int i = 0; i < n; i++)  cin>>vec[i];
    int left = -1, right = vec.size();
    while(left != right - 1){
        int mid = left + (right - left) / 2;
        if(vec[mid] < k)    left = mid;
        else if(vec[mid] >= k)  right = mid;
    }

    if(right != vec.size() && vec[right] >= k)  cout<<right<<endl;
    else    cout<<vec.size()<<endl;

    return 0;
}
