#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;


void greedy(int N,double D,vector<double> inventory,vector<double> price){
    vector<double> porpotion;
    double asw=0;
    for(int i=0;i<N;i++){
        double temp=(double)price[i]/inventory[i];
        porpotion.push_back(temp);
    }
    double sum=0;
    while(sum<D){
        double max=0;
        int i=0;
        for(int j=0;j<N;j++){
            if(porpotion[j]>max){
                max=porpotion[j];
                //cout<<"Porpotion"<<j<<" "<<porpotion[j]<<endl;
                i=j;
            }
        }
        porpotion[i]=0;
        if(max==0){
            break;
        }
        if(sum+inventory[i]>D){
            double tmp=D-sum;
            sum+=tmp;
            asw+=(double)price[i]*tmp/inventory[i];
        }
        else{
            sum+=inventory[i];
            asw+=price[i];
            //cout<<asw<<endl;
        }
    }
    printf("%.2f",asw);
}


int main()
{
    int N;
    double D;
    scanf("%d %lf",&N,&D);
    //printf("%d %d",N,D);
    int temp=N;
    vector<double> inventory;
    while(temp--){
        double i;
        scanf("%lf",&i);
        inventory.push_back(i);
    }
    temp=N;
    vector<double> price;
    while(temp--){
        double i;
        scanf("%lf",&i);
        price.push_back(i);
    }
    greedy(N,D,inventory,price);

    return 0;
}



