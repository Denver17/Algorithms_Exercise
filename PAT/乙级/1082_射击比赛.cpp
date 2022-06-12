#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct student{
    int ID;
    double x;
    double y;
};

int main()
{
    int N;  scanf("%d", &N);
    vector<student> stu(N);
    int asw1, asw2;
    double _min = 20000, _max = 0;
    for(int i = 0; i < N; i++){
        scanf("%d %lf %lf", &stu[i].ID, &stu[i].x, &stu[i].y);
        if(stu[i].x * stu[i].x + stu[i].y * stu[i].y < _min){
            asw1 = stu[i].ID;
            _min = stu[i].x * stu[i].x + stu[i].y * stu[i].y;
        }
        if(stu[i].x * stu[i].x + stu[i].y * stu[i].y > _max){
            asw2 = stu[i].ID;
            _max = stu[i].x * stu[i].x + stu[i].y * stu[i].y;
        }
    }
    printf("%04d %04d", asw1, asw2);

    return 0;
}

