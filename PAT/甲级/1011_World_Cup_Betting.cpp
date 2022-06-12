#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

char trans(int num){
    if(num == 0)    return 'W';
    else if(num == 1)   return 'T';
    return 'L';
}


int main()
{
    double bets[3][3];
    int col1,col2,col3;
    double asw = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin>>bets[i][j];
        }
    }
    
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                double temp;
                temp = (bets[0][i]*bets[1][j]*bets[2][k]*0.65 - 1) * 2;
                if(temp > asw){
                    asw = temp;
                    col1 = i;   col2 = j;   col3 = k;
                }
            }
        }
    }

   cout<<trans(col1)<<" "<<trans(col2)<<" "<<trans(col3)<<" ";
   printf("%.2f",asw);

    return 0;
}

