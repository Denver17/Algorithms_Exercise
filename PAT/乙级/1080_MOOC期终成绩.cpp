//我是傻逼
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<math.h>
using namespace std;

struct student{
    string ID;
    double Gp;
    double Gm;
    double Gf;
    int G;
    student(){
        ID.resize(20);
        Gp = Gm = Gf = -1;
        G = -1;
    }
};

bool cmp(student a, student b){
    if(a.G != b.G)  return a.G > b.G;
    return a.ID < b.ID;
}

int main()
{
    int P,M,N;  scanf("%d %d %d", &P, &M, &N);
    map<string, student> mp;
    vector<student> asw;
    for(int i = 0; i < P; i++){
        string str;     double temp;    
        str.resize(20);
        scanf("%s %lf", str.c_str(),&temp);
        mp[str].Gp = temp;
        mp[str].ID = str;
    }
    for(int i = 0; i < M; i++){
        string str;     double temp;
        str.resize(20);
        scanf("%s %lf", str.c_str(), &temp);
        mp[str].Gm = temp;
        mp[str].ID = str;
    }
    for(int i = 0; i < N; i++){
        string str;     double temp;
        str.resize(20);
        scanf("%s %lf", str.c_str(), &temp);
        mp[str].Gf = temp;
        mp[str].ID = str;
    }
    for(map<string, student>::iterator it = mp.begin(); it != mp.end(); it++){
        double GG;
        if(it->second.Gm > it->second.Gf) GG = it->second.Gm * 0.4 + it->second.Gf * 0.6;
        else    GG = it->second.Gf;
        it->second.G = round(GG);
        if(it->second.Gp < 200 || it->second.G < 60)  continue; //一开始第二个it->second.G写成了GG，我是傻逼
        asw.push_back(it->second);
    }
    sort(asw.begin(), asw.end(), cmp);    
    for(int i = 0; i < asw.size(); i++){
        printf("%s %d %d %d %d\n", asw[i].ID.c_str(), (int)asw[i].Gp, (int)asw[i].Gm, (int)asw[i].Gf, asw[i].G);
    }

    return 0;
}

