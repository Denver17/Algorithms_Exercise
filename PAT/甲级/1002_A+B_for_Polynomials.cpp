#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct polynomial{
    int len;
    double matrix[100][2];
};

int main()
{
    int K1; scanf("%d",&K1);
    polynomial p1,p2;
    p1.len = K1;
    for(int i = 0; i < K1; i++){
        scanf("%lf%lf",&p1.matrix[i][0],&p1.matrix[i][1]);
    }
    int K2; scanf("%d",&K2);
    p2.len = K2;
    for(int i = 0; i < K2; i++){
        scanf("%lf%lf",&p2.matrix[i][0],&p2.matrix[i][1]);
    }
    polynomial asw;
    asw.len = 0;
    int ptr1,ptr2,ptr = 0;
    for(ptr1 = 0,ptr2 = 0; ptr1 < p1.len && ptr2 < p2.len; ){
        if(p1.matrix[ptr1][0] > p2.matrix[ptr2][0]){
            asw.matrix[ptr][0] = p1.matrix[ptr1][0];
            asw.matrix[ptr][1] = p1.matrix[ptr1][1];
            ptr1++; ptr++;
        }
        else if(p1.matrix[ptr1][0] < p2.matrix[ptr2][0]){
            asw.matrix[ptr][0] = p2.matrix[ptr2][0];
            asw.matrix[ptr][1] = p2.matrix[ptr2][1];
            ptr2++; ptr++;
        }
        else{
            if(p1.matrix[ptr1][1] + p2.matrix[ptr2][1] == 0){
                ptr1++; ptr2++;
                continue;
            }
            asw.matrix[ptr][0] = p1.matrix[ptr1][0];
            asw.matrix[ptr][1] = p1.matrix[ptr1][1] + p2.matrix[ptr2][1];
            ptr++;  ptr1++; ptr2++;
        }
    }
    while(ptr1 < p1.len){
        asw.matrix[ptr][0] = p1.matrix[ptr1][0];
        asw.matrix[ptr][1] = p1.matrix[ptr1][1];
        ptr1++; ptr++;
    }
    while(ptr2 < p2.len){
        asw.matrix[ptr][0] = p2.matrix[ptr2][0];
        asw.matrix[ptr][1] = p2.matrix[ptr2][1];
        ptr2++; ptr++;
    }
    asw.len = ptr;
    printf("%d",asw.len);
    for(int i = 0; i < asw.len; i++){
        printf(" %d %.1f",(int)asw.matrix[i][0],asw.matrix[i][1]);
    }


    return 0;
}

