#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int N;  cin>>N; getchar();
    for(int i = 0; i < N; i++){
        string str;     getline(cin, str);
        bool flag_valid = true, flag_number = false, flag_word = false;
        if(str.size() < 6)  printf("Your password is tai duan le.\n");
        else{
            for(int j = 0; j < str.size(); j++){
                if( !( (str[j] >= '0' && str[j] <= '9') ||
                    (str[j] >= 'a' && str[j] <= 'z') ||
                    (str[j] >= 'A' && str[j] <= 'Z') ||
                    str[j] == '.')
                ){
                    flag_valid = false;
                }
                else if(str[j] >= '0' && str[j] <= '9'){
                    flag_number = true;
                }
                else if(str[j] >= 'a' && str[j] <= 'z' ||
                        str[j] >= 'A' && str[j] <= 'Z'){
                    flag_word = true;
                }
            }
            if(flag_valid == false) printf("Your password is tai luan le.\n");
            else if(flag_number == false)   printf("Your password needs shu zi.\n");
            else if(flag_word == false) printf("Your password needs zi mu.\n");
            else    printf("Your password is wan mei.\n");
        }
    }
    
    return 0;
}

