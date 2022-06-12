#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int n, k, x;    scanf("%d %d %d", &n, &k, &x);
    vector<vector<int> > vec(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>vec[i][j];
        }
    }

    int _count = 0;
    for(int i = 0; i < n; i++){
        if((i + 1) % 2 == 1){
            _count = _count % k;
            int pos = n - 1;
            for(int j = n - 1 - (_count + 1); j >= 0; j--){
                vec[i][pos--] = vec[i][j];
            }
            for(int j = 0; j < _count + 1; j++){
                vec[i][j] = x;
            }
            _count++;
        }
    }
    
    // for(int i = 0; i < n; i++){
    //     printf("%d",vec[i][0]);
    //     for(int j = 1; j < n; j++){
    //         if(j != n-1)
    //             printf(" %d",vec[i][j]);
    //         else
    //             printf(" %d\n",vec[i][j]);
    //     }
    // }

    for(int j = 0; j < n; j++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += vec[i][j];
        }
        if(j != 0)  printf(" %d",sum);
        else    printf("%d",sum);
    }

    return 0;
}

