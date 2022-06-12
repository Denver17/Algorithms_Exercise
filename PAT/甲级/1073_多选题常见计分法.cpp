#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

struct question{
    int id;
    double score;
    int number;
    int right_number;
    vector<char> right;
    map<char, int> wrong;
};


int main()
{
    int N, M;  cin>>N>>M;
    vector<question> qes(M);
    for(int i = 0; i < M; i++){
        scanf("%lf %d %d", &qes[i].score, &qes[i].number, &qes[i].right_number);
        qes[i].right.resize(qes[i].number,'-');
        for(int j = 0; j < qes[i].right_number; j++){
            char c; scanf(" %c",&c);
            qes[i].right[(int)(c - 'a')] = c;
        }
        for(int j = 0; j < qes[i].number; j++){
            qes[i].wrong[(char)('a' + j)] = 0;
        }
        qes[i].id = i + 1;
    }
    for(int i = 0; i < N; i++){
        double score = 0;
        for(int j = 0; j < M; j++){
            getchar();
            int num;
            scanf("(%d", &num);
            vector<char> vec(qes[j].number,'-');
            for(int k = 0; k < num; k++){
                char c; scanf(" %c", &c);
                vec[(int)(c - 'a')] = c;
            }
            getchar();
            if(vec == qes[j].right){
                score += qes[j].score;
                continue;
            }
            bool flag = true, ischose = false;
            for(int k = 0; k < qes[j].number; k++){
                if(vec[k] == qes[j].right[k] && vec[k] == '-')  continue;
                else if(vec[k] == qes[j].right[k] && vec[k] != '-') ischose = true;
                else if(vec[k] != qes[j].right[k] && vec[k] == '-'){
                    qes[j].wrong[(char)('a' + k)]++;
                    continue;
                }
                else if(vec[k] != qes[j].right[k] && vec[k] != '-'){
                    ischose = true;
                    qes[j].wrong[(char)('a' + k)]++;
                    flag = false;
                }
            }
            if(flag == false)   score += 0;
            else if(flag == true && ischose == false)   score += 0;
            else score += (double)qes[j].score / 2.0;
        }
        printf("%.1f\n",score);
    }
    vector<char> asw[2];
    int _max = 0;
    for(int i = 0; i < M; i++){
        for(map<char, int>::iterator it = qes[i].wrong.begin(); it != qes[i].wrong.end(); it++){
            if(it->second > _max){
                _max = it->second;
                asw[0].clear(); asw[1].clear();
                asw[0].push_back((char)(qes[i].id + '0'));
                asw[1].push_back(it->first);
            }
            else if(it->second == _max){
                asw[0].push_back((char)(qes[i].id + '0'));
                asw[1].push_back(it->first);
            }
        }
    }
    if(_max == 0)   printf("Too simple\n");
    else{
        for(int i = 0; i < asw[0].size(); i++){
            printf("%d %c-%c\n", _max, asw[0][i], asw[1][i]);
        }
    }  

    return 0;
}

