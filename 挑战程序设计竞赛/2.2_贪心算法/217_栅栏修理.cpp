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

struct cmp{
	bool operator()(const long long a,const long long b) const{
		return a > b;
	}
};

int main()
{
    int n;  cin>>n;
    priority_queue<long long, vector<long long>, cmp> que;
    long long asw = 0;
    for(int i = 0; i < n; i++){
        long long temp;   cin>>temp;
        que.push(temp);
    }
    while(que.size() > 1){
        long long temp1 = que.top();
        que.pop();
        long long temp2 = que.top();
        que.pop();
        long long temp = temp1 + temp2;
        asw += temp;
        que.push(temp);
    }
    
    cout<<asw<<endl;

    return 0;
}
