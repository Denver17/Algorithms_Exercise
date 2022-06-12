#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> hashTable;

const int maxn = 10010;
vector<int> prime;
vector<bool> isNotPrime(maxn,false);
void FindPrime(){
    for(int i = 2; i < maxn; i++){
        if(isNotPrime[i] == false){
            prime.push_back(i);
            for(int j = i + i; j < maxn; j += i){       //注意点1
                isNotPrime[j] = true;
            }
        }
    }
    return ;
}

int insert(int num){
    int step = 1;
    int pos = num % hashTable.size();
    if(hashTable[pos] == -1){
        hashTable[pos] = num;
        return pos;
    }
    else{       //注意点2
        for(int i = ( pos + 1 ) % hashTable.size() ; step <= hashTable.size() ; i = ( pos + step * step ) % hashTable.size() ){
            if(hashTable[i] == -1){
                hashTable[i] = num;
                return i;
            }
            else
                step++;
        }
    }
    return -1;
}

int main()
{
    int MSize,N;    cin>>MSize>>N;
    FindPrime();
    for(int i = 0; i < prime.size(); i++){
        if(prime[i] >= MSize){
            MSize = prime[i];
            break;
        }
    }
    hashTable.resize(MSize,-1);
    for(int i = 0; i < N - 1; i++){
        int num;    cin>>num;
        int pos = insert(num);
        if(pos == -1)   cout<<"- ";
        else    cout<<pos<<" ";
    }
    int number; cin>>number;
    int position = insert(number);
    if(position == -1)  cout<<"-";
    else    cout<<position;

    return 0;
}

