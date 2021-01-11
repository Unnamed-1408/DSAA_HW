#include <iostream>
#include <vector>
using namespace std;

long long length = INT_FAST16_MAX;
vector<int> *T = new vector<int>[200005];
vector<int> *value = new vector<int>[200005];
int *status = new int[200005]();
int n, m;

void dfs(int node, int how_long){
    status[node] = 1;
//    cout << how_long << endl;
    cout << node << endl;
    for(int i = 0; i < T[node].size(); i++){
        if(status[T[node][i]] != 1){
            dfs(T[node][i], how_long + value[node][i]);
        }
    }
    if(node == n){
//        cout << how_long << endl;
        length = (length < how_long) ? length : how_long;
    }
}

int main()
{

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int q, w, e;
        cin >> q >> w >> e;
        T[q].push_back(w);
        value[q].push_back(e);
        T[w].push_back(q);
        value[w].push_back(e);
    }
    dfs(1, 0);
    cout << length << endl;
}
