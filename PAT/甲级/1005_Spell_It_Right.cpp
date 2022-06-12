#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    string str;     cin>>str;
    int sum = 0;
    for(int i = 0; i < str.size(); i++){
        int temp = str[i] - '0';
        sum += temp;
    }
    
    vector<string> asw;
    while(sum != 0){
        int temp = sum % 10;
        sum = sum / 10;
        switch(temp){
            case 0: 
                asw.push_back("zero");  break;
            case 1:
                asw.push_back("one");   break;
            case 2:
                asw.push_back("two");   break;
            case 3:
                asw.push_back("three"); break;
            case 4:
                asw.push_back("four");  break;
            case 5:
                asw.push_back("five");  break;
            case 6:
                asw.push_back("six");   break;
            case 7:
                asw.push_back("seven"); break;
            case 8:
                asw.push_back("eight"); break;
            case 9:
                asw.push_back("nine");  break;
        }
    }

    if(asw.size() == 0) {cout<<"zero"; return 0;}

    cout<<asw[asw.size()-1];
    for(int i = asw.size() - 2; i >= 0; i--){
        cout<<" "<<asw[i];
    }

    return 0;
}

