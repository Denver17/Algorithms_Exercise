#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int N;
    cin>>N;
    int asw1 = 0, asw2 = 0;
    for(int i = 0; i < N; i++){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        if((A + C == B && A + C == D) || (A + C != B && A + C != D))    //甲乙均猜中或者均未猜中
            continue;
        else if(A + C != B && A + C == D)   //甲未猜中，乙猜中
            asw1++;
        else if(A + C == B && A + C != D)   //甲猜中，乙未猜中
            asw2++;
    }
    cout<<asw1<<' '<<asw2;


    return 0;
}
