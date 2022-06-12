#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;

bool isValid(string str, double &num){
    if(str.size() == 0) return false;
    if(str[0] != '-' && !(str[0]<= '9' && str[0] >= '0'))   return false;
    else if(str[0] == '-' && str.size() == 1)   return false;
    for(int i = 1; i < str.size(); i++){
        if(str[i] != '.' && !(str[i]<= '9' && str[i] >= '0'))   return false;
    }
    int _count = count(str.begin(), str.end(),'.');
    if(_count > 1)   return false;

    if(_count == 1 && (str.size() - str.find(".") > 3 || str[str.find(".") - 1] == '-' ))  return false;

    if(str[0] != '-'){
        num = atof(str.c_str());
    }
    else{
        str.erase(0,1);
        num = atof(str.c_str());
        num *= (-1.0);
    }
    if(num > 1000 || num < -1000)   return false;
   
    return true;
}

int main()
{
    int N;  cin>>N;
    vector<double> vec;
    double asw = 0;
    for(int i = 0; i < N; i++){
        string str; cin>>str;
        double num;
        if(isValid(str,num))    vec.push_back(num); 
        else    cout<<"ERROR: "<<str<<" is not a legal number"<<endl;
    }
    if(vec.size() == 0)     cout<<"The average of 0 numbers is Undefined"<<endl;
    else if(vec.size() == 1)    { 
        cout<<"The average of 1 number is ";
        printf("%.2f",vec[0]);
    }
    else{
        for(int i = 0; i < vec.size(); i++){
            asw += vec[i];
        }
        printf("The average of %d numbers is %.2f", vec.size(), asw/vec.size());
    }

    return 0;
}

