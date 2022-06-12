#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

struct school{
    string name;
    double sum;
    int number;
    school(){
        sum = 0;
        number = 0;
    }
};

bool cmp(school a, school b){
    if((int)a.sum != (int)b.sum)  return a.sum > b.sum;             //此处取整后才能过真恶心
    else if(a.number != b.number)   return a.number < b.number;
    return a.name < b.name;
}

int main()
{
    int N;  cin>>N;
    map<string, school> mp;
    for(int i = 0; i < N; i++){
        string id;  id.resize(6);
        int score;  string sc_name; sc_name.resize(6);
        scanf("%s %d %s", id.c_str(), &score, sc_name.c_str());
        transform(sc_name.begin(), sc_name.end(), sc_name.begin(), ::tolower);
        if(mp.count(sc_name) == 0){
            school sc;  sc.name = sc_name;
            mp[sc_name] = sc;
            mp[sc_name].number = 1;
        }
        else{
            mp[sc_name].number++;
        }
        if(id[0] == 'B'){
            mp[sc_name].sum += (double)score / 1.5;
        }
        else if(id[0] == 'A'){
            mp[sc_name].sum += (double)score;
        }
        else if(id[0] == 'T'){
            mp[sc_name].sum += (double)score * 1.5;
        }
    }

    vector<school> res;
    for(map<string, school>::iterator it = mp.begin(); it != mp.end(); it++){
        res.push_back(it->second);
    }
    sort(res.begin(), res.end(), cmp);

    printf("%d\n", res.size());
    int rank = 1;
    printf("%d %s %d %d\n", rank, res[0].name.c_str(), (int)res[0].sum, res[0].number);
    for(int i = 1; i < res.size(); i++){
        if((int)res[i].sum == (int)res[i - 1].sum){
            printf("%d %s %d %d\n", rank, res[i].name.c_str(), (int)res[i].sum, res[i].number);
        }
        else{
            rank = i + 1;
            printf("%d %s %d %d\n", rank, res[i].name.c_str(), (int)res[i].sum, res[i].number);
        }
    }
    
    return 0;
}

