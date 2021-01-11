#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct T{
    int to;
    int length;
};
int *status;
vector<T> *list;
int n, m;
long long total = 0;
int min_i = INT16_MAX;
int head;
T *min_s;
struct comp {
        comp() {}
        ~comp() {}
        bool operator()(const T a,const T b) {
            return a.length > b.length;//最小堆，从小到大排序
        }
};
priority_queue<T,vector<T>,comp> minHeap;
void Prim_s_Algorithm();


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n >> m;
    status = new int[n + 1]();
    list = new vector<T>[n + 1]();
    for(int i = 0; i < m; i++){
        int k, j, l;
        cin >> k >> j >> l;
        T *tmpa = new T;
        T *tmpb = new T;
        tmpa->length = tmpb->length = l;
        tmpa->to = j;
        tmpb->to = k;
        list[k].push_back(*tmpa);
        list[j].push_back(*tmpb);
        if(min_i > l){
            min_i = l;
            head = k;
            min_s = tmpa;
        }
    }
    Prim_s_Algorithm();
    cout << total << endl;
}

void Prim_s_Algorithm(){
    int count = 2;
    status[head] = 1;
    status[min_s->to] = 1;
    total += min_s->length;
    for(int i = 0; i < list[head].size(); i++){
        if(status[list[head][i].to] != 1){
            minHeap.push(list[head][i]);
        }
    }
    for(int i = 0; i < list[min_s->to].size(); i++){
        if(status[list[min_s->to][i].to] != 1){
            minHeap.push(list[min_s->to][i]);
        }
    }
    while (count != n) {
        int tmp;
        tmp = minHeap.top().to;
        if(status[tmp] == 0){
            total += minHeap.top().length;
            minHeap.pop();
            for(int i = 0; i < list[tmp].size(); i++){
                if(status[list[tmp][i].to] != 1){
                    minHeap.push(list[tmp][i]);
                }
            }
            count ++;
            status[tmp] = 1;
        }
        else{
            minHeap.pop();
        }
    }
}
