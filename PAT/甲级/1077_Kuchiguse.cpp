//这题注意使用getline要将换行符吸收
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int N;  scanf("%d",&N);
    getchar();          //将换行符吸收
    vector<string> vec(N);
    string asw;
    int _min = 300;
    for(int i = 0; i < N; i++){
        getline(cin,vec[i]);
        reverse(vec[i].begin(),vec[i].end());
        if(_min > vec[i].size())    _min = vec[i].size();
    }

    bool flag = true;
    for(int i = 1; i <= _min && flag == true; i++){
        string str = vec[0].substr(0,i);
        string temp = asw;
        for(int j = 1; j < vec.size(); j++){
            if(str == vec[j].substr(0,i)){
                asw = str;
            }
            else{
                asw = temp;
                flag = false;
                break;
            }
        }
    }

    reverse(asw.begin(),asw.end());

    if(asw.size() == 0) cout<<"nai";
    else    cout<<asw;


    return 0;
}

