#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int M;  scanf("%d", &M);
    for(int i = 0; i < M; i++){
        int num;    scanf("%d", &num);
        bool flag = false;
        vector<int> res;
        int temp = num;
        while(temp != 0){
            res.push_back(temp % 10);
            temp = temp / 10;
        }
        for(int j = 1; j < 10; j++){
            vector<int> vec;
            int val = j * num * num;
            int tmpval = val;
            int size = 0;
            while(size < res.size()){
                size++;
                vec.push_back(tmpval % 10);
                tmpval = tmpval / 10;
            }
            if(res == vec){
                flag = true;
                cout<<j<<" "<<val<<endl;
                break;
            }
        }
        if(flag == false)
            cout<<"No"<<endl;
    }

    return 0;
}

