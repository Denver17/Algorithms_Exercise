#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main()
{
    int N;  scanf("%d", &N);
    map<int, int> mp;
    for(int i = 0; i < N; i++){
        int temp;   scanf("%d",&temp);
        mp[(-1) * abs(i + 1 - temp)]++;
    }
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
        if(it->second > 1)
            printf("%d %d\n", abs(it->first), it->second);
    }

    return 0;
}

