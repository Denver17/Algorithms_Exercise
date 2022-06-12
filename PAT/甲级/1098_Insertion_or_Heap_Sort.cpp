#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<vector<int> > ins;
vector<vector<int> > heap;

void insertion_sort(vector<int> &vec){
    for(int i = 1; i < vec.size(); i++){
        int temp = vec[i];
        int j;
        for(j = i; j > 0; j--){
            if(temp < vec[j - 1]){
                vec[j] = vec[j - 1];
            }
            else    break;
        }
        vec[j] = temp;
        ins.push_back(vec);
    }
    return ;
}

void downAdjust(int low, int high, vector<int> &vec){
    int i = low, j = 2 * i + 1;
    while(j <= high){
        if(j + 1 <= high && vec[j + 1] > vec[j]){
            j = j + 1;
        }

        if(vec[j] > vec[i]){
            swap(vec[j], vec[i]);
            i = j;
            j = 2 * i + 1;
        }
        else    break;
    }
}

void createHeap(vector<int> &vec){
    for(int i = vec.size() / 2; i >= 0; i--){
        downAdjust(i, vec.size() - 1, vec);
    }
    return ;
}

void heap_sort(vector<int> &vec){
    createHeap(vec);
    
    for(int i = vec.size() - 1; i > 0; i--){
        swap(vec[i], vec[0]);
        downAdjust(0, i - 1, vec);
        heap.push_back(vec);
    }
    return ;
}

int main()
{
    int N;  cin>>N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        scanf("%d", &vec[i]);
    }

    //ins.push_back(vec);
    //heap.push_back(vec);

    vector<int> res(N);
    for(int i = 0; i < N; i++){
        scanf("%d", &res[i]);
    }

    vector<int> copyvec = vec;
    insertion_sort(vec);
    heap_sort(copyvec);

    for(int i = 0; i < ins.size(); i++){
        if(res == ins[i]){
            printf("Insertion Sort\n");
            printf("%d", ins[i + 1][0]);
            for(int j = 1; j < ins[i + 1].size(); j++){
                printf(" %d", ins[i + 1][j]);
            }
            return 0;
        }
    }

    for(int i = 0; i < heap.size(); i++){
        if(res == heap[i]){
            printf("Heap Sort\n");
            printf("%d", heap[i + 1][0]);
            for(int j = 1; j < heap[i + 1].size(); j++){
                printf(" %d", heap[i + 1][j]);
            }
        }
    }

    return 0;
}

