#include <iostream>
#include <vector>

using namespace std;
int *list = new int[100000]();
vector<int> *tree = new vector<int>[100000]();
long long ans = 0;
int far = 0;

void dfs(int now, int last, int step){
    if(list[now] == 1 && ans < step){
        ans = step;
        far = now;
    }

    for(int i = 0; i < tree[now].size(); i++){
        if(last != tree[now][i])
            dfs(tree[now][i], now, step+1);
    }
}


int main()
{
    int T = 0;
    cin >> T;
    while(T--){
        ans = 0;
        far = 0;
        int N = 0, K = 0;
        cin >> N >> K;
        for(int i = 0; i < N-1; i++){
            int a,b;
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        int temp;
        for(int i = 0; i < K; i++){
            cin >> temp;
            list[temp] = 1;
        }

        dfs(temp, 0, 1);
        dfs(far, 0, 1);
        cout << ans/2 << endl;
        delete []tree;
        delete []list;
        list = new int[100000]();
        tree = new vector<int>[100000]();
    }
}
