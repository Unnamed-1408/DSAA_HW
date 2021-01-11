#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct T{
    int from_x = 0;
    int from_y = 0;
    int to_x = 0;
    int to_y = 0;
    int dis = 0;
};

struct cmp {
     bool operator()(T x, T y){
        return x.dis < y.dis; // x小的优先级高       //也可以写成其他方式，如： return p[x] > p[y];表示p[i]小的优先级高
    }
};
priority_queue<T, vector<T>, cmp> maxHeap;    //定义方法

int n, m;
void Prim_s(int x, int y,vector<int> *list, vector<int> *dis, vector<int> *status);
int main()
{
    cin >> n >> m;
//    int list[n + 2][m + 2];
//    int dis[n + 2][m + 2];
//    int status[n + 2][m + 2];
//    for(int i = 0; i < n + 2; i++){
//        for(int j = 0; j < m + 2; j++){
//            list[i][j] = 0;
//            dis[i][j] = 0;
//            status[i][j] = 0;
//        }
//    }
    vector<int> *list = new vector<int>[n + 2];
    vector<int> *dis = new vector<int>[n + 2];
    vector<int> * status = new vector<int>[n + 2];
        for(int i = 0; i < n + 2; i++){
            for(int j = 0; j < m + 2; j++){
                list[i].push_back(0);
                dis[i].push_back(0);
                status[i].push_back(0);
            }
        }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> list[i + 1][j + 1];
        }
    }
    Prim_s(1, 1, list, dis, status);
    long long total = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            total += dis[i + 1][j + 1];
        }
    }
    cout << total << endl;
}

void Prim_s(int x, int y,vector<int> *list, vector<int> *dis, vector<int> *status){
    status[x][y] = 1;
//    cout << x << "  " << y << endl;
    if(list[x + 1][y] != 0 && status[x + 1][y] == 0){
//        cout << "1wwwwww" << endl;
        T *tmp = new T;
        tmp->from_x = x;
        tmp->from_y = y;
        tmp->to_x = x + 1;
        tmp->to_y = y;
        tmp->dis = list[x][y] * list[x + 1][y];
        maxHeap.push(*tmp);
    }
    if(list[x - 1][y] != 0 && status[x - 1][y] == 0){
        T *tmp = new T;
        tmp->from_x = x;
        tmp->from_y = y;
        tmp->to_x = x - 1;
        tmp->to_y = y;
        tmp->dis = list[x][y] * list[x - 1][y];
        maxHeap.push(*tmp);
    }
    if(list[x][y + 1] != 0 && status[x][y + 1] == 0){
        T *tmp = new T;
        tmp->from_x = x;
        tmp->from_y = y;
        tmp->to_x = x;
        tmp->to_y = y + 1;
        tmp->dis = list[x][y] * list[x][y + 1];
        maxHeap.push(*tmp);
    }
    if(list[x][y - 1] != 0 && status[x][y - 1] == 0){
        T *tmp = new T;
        tmp->from_x = x;
        tmp->from_y = y;
        tmp->to_x = x;
        tmp->to_y = y - 1;
        tmp->dis = list[x][y] * list[x][y - 1];
        maxHeap.push(*tmp);
    }
    if(!maxHeap.empty()){
        while(status[maxHeap.top().to_x][maxHeap.top().to_y] == 1 && maxHeap.empty() == false){
//            cout << maxHeap.top().to_x << "   " << maxHeap.top().to_y << endl;
//            cout << status[maxHeap.top().to_x][maxHeap.top().to_y] << endl;
            maxHeap.pop();
        }
//        cout << "end" << endl;
        if(maxHeap.empty()){
            return;
        }
        T tmpa = maxHeap.top();
        dis[tmpa.to_x][tmpa.to_y] = tmpa.dis;
        maxHeap.pop();
        Prim_s(tmpa.to_x, tmpa.to_y, list, dis, status);
    }
}
