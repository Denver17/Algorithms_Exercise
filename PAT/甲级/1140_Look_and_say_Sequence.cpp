#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int d,N;    scanf("%d %d", &d, &N);
    string asw = to_string(d);
    for(int i = 0; i < N - 1; i++){
        string str = asw;
        asw.clear();
        int left = 0, right = 0;
        while(left < str.size()){
            while(right < str.size() && str[left] == str[right])    right++;
            asw.append(1, str[left]);
            asw.append(to_string(right - left));
            left = right;
        }
    }
    printf("%s", asw.c_str());

    return 0;
}

