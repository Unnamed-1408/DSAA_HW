#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int Max = 50010;
long long *queue_a = new long long[Max]();
long long *ans = new long long[Max]();

struct T{
    long long length, pre, to;
    T(long long len = 0, int u = 0, int tmp = 0){
        length = len;
        pre  = u;
        to = tmp;
    }
    bool operator < (const T &b) const{
        return length > b.length;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int MX = 0;
    cin >> MX;
    while(MX--){
        int n, m, q;
        cin >> n >> m >> q;
        vector<pair<int, int>> list[Max];
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            list[u].push_back(make_pair(w, v));
        }
        for(int i = 1; i <= n; i++){
            sort(list[i].begin(), list[i].end());
        }
        long long tmp_max = 0;
        for(int i = 0; i < q; i++){
            cin >> queue_a[i];
            tmp_max = max(queue_a[i], tmp_max);
        }
        priority_queue<T> que;
        for(int i = 1; i <= n; i++){
            if(list[i].size())
                que.push(T(list[i][0].first, i, 0));
        }
        int count = 0;
        while(que.size() != 0){
            T tmp = que.top();
            que.pop();
            ans[++count] = tmp.length;
            if(count == tmp_max) break;
            if(tmp.to < (int)list[tmp.pre].size() - 1){
                que.push(T(tmp.length - list[tmp.pre][tmp.to].first+list[tmp.pre][tmp.to + 1].first, tmp.pre,tmp.to + 1));
            }
            int a = list[tmp.pre][tmp.to].second;
            if(list[a].size()){
                que.push(T(tmp.length + list[a][0].first, a, 0));
            }
        }
        for(int i = 0; i < q; i++){
            printf("%lld\n", ans[queue_a[i]]);
        }
    }
}
