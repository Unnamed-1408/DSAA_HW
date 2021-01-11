#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int N = 50010;
int query[N], ans[N];
struct Node
{
    int len, u, id;
    Node (int _len = 0, int _u = 0, int _id = 0) {
        len = _len, u = _u, id = _id;
    }
    bool operator < (const Node &b) const{
        return len > b.len;
    }
};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, q;
        std::vector<std::pair<int, int> > G[N];
        memset(ans, 0, sizeof(ans));
        scanf("%d %d %d", &n, &m, &q);
        for (int i = 0, u, v, w; i < m; i++) {
            scanf("%d %d %d", &u, &v, &w);
            G[u].push_back(std::make_pair(w, v));
        }
        for (int i = 1; i <= n; i++) std::sort(G[i].begin(), G[i].end());
        int mx = 0;
        for (int i = 0; i < q; i++) {
            scanf("%d", &query[i]);
            mx = std::max(query[i], mx);
        }
        std::priority_queue<Node> que;
        for (int i = 1; i <= n; i++) {
            if (G[i].size()) que.push(Node(G[i][0].first, i, 0));
        }
        int cnt = 0;
        while (!que.empty()) {
            Node no = que.top();
            que.pop();
            int u = no.u, id = no.id, len = no.len;
            ans[++cnt] = len;
            if (cnt == mx) break;
            if (id < (int)G[u].size() - 1) {
                que.push(Node(len - G[u][id].first + G[u][id+1].first, u, id + 1));
            }
            cout << no.u << endl;
            int v = G[u][id].second;
            cout << v << endl;
            if (G[v].size()) {
                que.push(Node(len + G[v][0].first, v, 0));
            }
        }
        for (int i = 0; i < q; i++) printf("%d\n", ans[query[i]]);
    }
    return 0;
}
