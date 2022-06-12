//略显复杂，有点恶心呃呃呃
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<ctime>
#include<stdlib.h>
using namespace std;

vector<double> toll(24);

struct record{
    string name;
    string time;
    bool state;
}records[1000];

struct bill{
    string start,end;
    double lasting;
    double charge;
};

struct customer{
    string name;
    vector<bill> bills;
    double total_bills;
}customers[1000];

bool cmp1(record a,record b){
    if(a.name != b.name)    return a.name < b.name;
    else if(a.time != b.time)   return a.time < b.time;
}

bool cmp2(customer a,customer b){
    if(a.name != b.name)    return a.name < b.name;
}

// double my_sub(string a,string b){
//     struct tm t1 = { 0 };
//     struct tm t2 = { 0 };
//     t1.tm_min = atoi(a.substr(9,2).c_str());
//     t2.tm_min = atoi(b.substr(9,2).c_str());
//     t1.tm_hour = atoi(a.substr(6,2).c_str());
//     t2.tm_hour = atoi(b.substr(9,2).c_str());
//     t1.tm_mday = atoi(a.substr(3,2).c_str());
//     t2.tm_mday = atoi(a.substr(3,2).c_str());
//     double minute = difftime(mktime(&t2),mktime(&t1));
//     return minute;
// }

void my_count(string a,string b,double &l,double &c){
    int min1 = atoi(a.substr(9,2).c_str());
    int min2 = atoi(b.substr(9,2).c_str());
    int hour1 = atoi(a.substr(6,2).c_str());
    int hour2 = atoi(b.substr(6,2).c_str());
    int day1 = atoi(a.substr(3,2).c_str());
    int day2 = atoi(b.substr(3,2).c_str());
    while( !(day1 == day2 && hour1 == hour2 && min1 == min2) ){
        c += toll[hour1];
        l++;    min1++;
        if(min1 == 60){
            min1 = 0;   hour1++;
            if(hour1 == 24){
                hour1 = 0;  day1++; 
            }
        }
    }
    return ;
}


void my_sort(int N)
{
    string month = records[0].time.substr(0,2);
    sort(records,records + N,cmp1);
    int _count = 0;
    customers[0].name = records[0].name;
    int left = 0; int right = 1;
    for(int i = 1; i < N; i++){
        if(records[i].name != records[i-1].name){
            _count++;
            customers[_count].name = records[i].name;
            left = i;   right = i + 1;
            continue;
        }
        if(records[left].state == true && records[right].state == false){
            bill temp_bill;
            double l = 0; double c = 0;
            my_count(records[left].time,records[right].time,l,c);
            temp_bill.lasting = l;
            temp_bill.charge = c;
            temp_bill.start = records[left].time.substr(3,8);
            temp_bill.end = records[right].time.substr(3,8);
            customers[_count].bills.push_back(temp_bill);
        }
        left++; right++;
    }

    sort(customers,customers + _count + 1,cmp2);

    for(int i = 0; i < _count + 1; i++){
        if(customers[i].bills.size() == 0)  continue;
        cout<<customers[i].name<<" "<<month<<endl;
        double total = 0;
        for(int j = 0; j < customers[i].bills.size(); j++){
            cout<<customers[i].bills[j].start<<" "
                <<customers[i].bills[j].end<<" "
                <<customers[i].bills[j].lasting<<" $";
            printf("%.2f\n",customers[i].bills[j].charge/100);
            total += customers[i].bills[j].charge;
        }
        customers[i].total_bills = total;
        printf("Total amount: $%.2f\n",customers[i].total_bills/100);
        //cout<<"Total amount: $"<<customers[i].total_bills<<endl;
    }

    return ;
}



int main()
{

    for(int i = 0; i < 24; i++) cin>>toll[i];
    int N;  cin>>N;
    for(int i = 0; i < N; i++){
        string cname,ctime,cstate;
        cin>>cname>>ctime>>cstate;
        records[i].name = cname;    records[i].time = ctime;   
        if(cstate == "on-line") records[i].state = true;
        else if(cstate == "off-line")   records[i].state = false;
    }

    my_sort(N);

    return 0;
}