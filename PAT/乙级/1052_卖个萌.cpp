#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<string> change(string str){
    vector<string> res;
    int left = 0, right = 0;
    while(left < str.size()){
        while(left < str.size() && str[left] != '[')    left++;
        right = left;
        while(right < str.size() && str[right] != ']')  right++;
        if(right > left && right < str.size()){
            string temp = str.substr(left + 1, right - left - 1);
            res.push_back(temp);
        }
        right++; left = right;
    }
    return res;
}

int main()
{
    string str1, str2, str3;
    getline(cin, str1);
    getline(cin, str2);
    getline(cin, str3);
    vector<string> res1 = change(str1);
    vector<string> res2 = change(str2);
    vector<string> res3 = change(str3);

    int K;  cin>>K;
    for(int i = 0; i < K; i++){
        bool flag = true;
        vector<string> asw;
        vector<int> temp(5);
        for(int j = 0; j < 5; j++){
            cin>>temp[j];
        }
        for(int j = 0; j < 5; j++){
            if(j == 0){
                if(temp[j] > res1.size() || temp[j] <= 0){
                    cout<<"Are you kidding me? @\\/@"<<endl;
                    flag = false;
                    break;
                }
                else{
                    asw.push_back(res1[temp[j] - 1]);
                }
                asw.push_back("(");
            }
            else if(j == 1){
                if(temp[j] > res2.size() || temp[j] <= 0){
                    cout<<"Are you kidding me? @\\/@"<<endl;
                    flag = false;
                    break;
                }
                else{
                    asw.push_back(res2[temp[j] - 1]);
                }
            }
            else if(j == 2){
                if(temp[j] > res3.size() || temp[j] <= 0){
                    cout<<"Are you kidding me? @\\/@"<<endl;
                    flag = false;
                    break;
                }
                else{
                    asw.push_back(res3[temp[j] - 1]);
                }
            }
            else if(j == 3){
                if(temp[j] > res2.size() || temp[j] <= 0){
                    cout<<"Are you kidding me? @\\/@"<<endl;
                    flag = false;
                    break;
                }
                else{
                    asw.push_back(res2[temp[j] - 1]);
                }
                asw.push_back(")");
            }
            else if(j == 4){
                if(temp[j] > res1.size() || temp[j] <= 0){
                    cout<<"Are you kidding me? @\\/@"<<endl;
                    flag = false;
                    break;
                }
                else{
                    asw.push_back(res1[temp[j] - 1]);
                }
            }
    
        }
        if(flag == true){
            for(int j = 0; j < asw.size(); j++){
                cout<<asw[j];
            }
            cout<<endl;
        }
    }

    return 0;
}

