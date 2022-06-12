#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct student{
    int ID;
    int virtue;
    int talent;
    int total;
};

//vector<student> stu;

bool cmp(student a, student b){
    if(a.total != b.total)  return a.total > b.total;
    else if(a.virtue != b.virtue)   return a.virtue > b.virtue;
    else    return a.ID < b.ID;
}

int main()
{
    int N, L, H;    scanf("%d %d %d", &N, &L, &H);
    vector<student> sage;
    vector<student> nobleman;
    vector<student> foolman;
    vector<student> smallman;
    for(int i = 0; i < N; i++){
        int vs, ts;
        student temp;
        scanf("%d %d %d", &temp.ID, &vs, &ts);
        if(vs < L || ts < L)    continue;
        temp.virtue = vs;   temp.talent = ts;
        temp.total = temp.talent + temp.virtue;
        //stu.push_back(temp); 
        if(temp.virtue >= H && temp.talent >= H){
            sage.push_back(temp);
        }   
        else if(temp.virtue >= H && temp.talent < H){
            nobleman.push_back(temp);
        }
        else if(temp.virtue < H && temp.talent < H && temp.virtue >= temp.talent){
            foolman.push_back(temp);
        }
        else    smallman.push_back(temp);
    }
    
    sort(sage.begin(), sage.end(), cmp);
    sort(nobleman.begin(), nobleman.end(), cmp);
    sort(foolman.begin(), foolman.end(), cmp);
    sort(smallman.begin(), smallman.end(), cmp);
    
    printf("%d\n", sage.size() + nobleman.size() + foolman.size() + smallman.size());
    for(int i = 0; i < sage.size(); i++)    printf("%d %d %d\n", sage[i].ID, sage[i].virtue, sage[i].talent);
    for(int i = 0; i < nobleman.size(); i++)    printf("%d %d %d\n", nobleman[i].ID, nobleman[i].virtue, nobleman[i].talent);
    for(int i = 0; i < foolman.size(); i++)    printf("%d %d %d\n", foolman[i].ID, foolman[i].virtue, foolman[i].talent);
    for(int i = 0; i < smallman.size(); i++)    printf("%d %d %d\n", smallman[i].ID, smallman[i].virtue, smallman[i].talent);
    
    return 0;
}

