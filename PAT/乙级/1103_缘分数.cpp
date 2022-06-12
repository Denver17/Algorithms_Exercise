#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

int main()
{
    int m, n;   cin>>m>>n;
    bool flag = false;
    for(int i = m; i <= n; i++){
        for(int j = i - 1; j > 0; j--){
            if(i * i * i - (i - 1) * (i - 1) * (i - 1) == 
            (j * j + (j - 1) * (j - 1)) * (j * j + (j - 1) * (j - 1)) ){
                printf("%d %d\n", i, j);
                flag = true;
            }
        }
    }

    if(flag == false)   printf("No Solution\n");

    return 0;
}