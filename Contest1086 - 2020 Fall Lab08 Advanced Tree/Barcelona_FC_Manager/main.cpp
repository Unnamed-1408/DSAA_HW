#include <iostream>
#include <algorithm>

struct HeapStruct{
    int num = 0;
    int *heap = new int[300000]();
};

struct FC{
    int a;
    int time;
};
FC *list = new FC[100005];

bool compare(FC &a,FC &b);
void Insert_min(int X, HeapStruct* H);
int Delete_min(HeapStruct* H);

using namespace std;

int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T = 0;
    cin >> T;
    while(T--){
        int n = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> list[i].a;
        }
        for(int i = 0; i < n; i++){
            cin >> list[i].time;
        }
        sort(list,list+n,compare);
        int time_total = 0;
        HeapStruct *a = new HeapStruct;
        for(int i = 0; i < n; i++){
            if(time_total < list[i].time){
                Insert_min(list[i].a,a);
                time_total++;
            }
            else if(time_total == list[i].time){
                if(list[i].a > a->heap[1]){
                    Delete_min(a);
                    Insert_min(list[i].a,a);
                }
            }
        }
        long long total = 0;
        while(a->num != 0){
            total += Delete_min(a);
        }
        cout << total << endl;
        delete a;
    }
}

bool compare(FC &a,FC &b)
{
    if(a.time != b.time)
        return a.time < b.time; //升序排列，如果改为return a>b，则为降序
    else
        return a.a > b.a;
}

void Insert_min(int X, HeapStruct* H){
    int i;

    for( i = ++H->num; H->heap[i/2] > X; i/=2){
        H->heap[i] = H->heap[i/2];
    }
    H->heap[i] = X;
}


int Delete_min(HeapStruct* H){
    int i , Child ;
    int min , last;

    min = H->heap[1];
    last = H->heap[H->num--];

    for(i = 1; i*2 <=H->num; i = Child){

        Child = i*2;

        if(Child != H->num && H->heap[Child +1] < H->heap[Child])
            Child++;
        if(last > H->heap[Child])
            H->heap[i] = H->heap[Child];
        else {
            break;
        }
    }
    H->heap[ i ] = last;
//    cout << min << endl;
    return min;
}
