#include <iostream>
#include <vector>
using namespace std;

vector<int> *list;
vector<int> *reverse;
int n, m;
int count = 0;
int *status;
void dfs(vector<int> *T, int node);
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n >> m;
    list = new vector<int>[n + 1];
    reverse = new vector<int>[n + 1];
    status = new int[n + 1]();
    for(int i = 0; i < m; i++){
        int k, j;
        cin >> k >> j;
        list[k].push_back(j);
        reverse[j].push_back(k);
    }
    dfs(reverse, 1);
//    cout << count << endl;
//    cout << last << endl;
    if(count != n){
        cout << "wawawa" << endl;
        return 0;
    }
    delete [] status;
    status = new int[n + 1]();
    count = 0;
    dfs(list, 1);
    if(count != n){
        cout << "wawawa" << endl;
    }
    else{
        cout << "Bravo" << endl;
    }
}

void dfs(vector<int> *T, int node){
    if(status[node] == 0){
        status[node] = 1;
        count++;
        for(int i = 0; i < T[node].size(); i++){
            dfs(T, T[node][i]);
        }
    }
}
