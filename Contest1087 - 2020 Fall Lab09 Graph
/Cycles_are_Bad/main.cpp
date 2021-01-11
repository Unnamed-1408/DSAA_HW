#include <iostream>
#include <vector>
using namespace std;

vector<int> *T = new vector<int>[100001];
int *list = new int[100001]();

bool dfs(int i,int pre){
    list[i] = 1;
//    cout << i << endl;
    bool out = true;
    for(int j = 0; j < T[i].size(); j++){
        if(list[T[i][j]] == 0){
            out = dfs(T[i][j],i);
            if(out == false)
                break;
        }
        else if(T[i][j] != pre){
            return false;
        }
    }
    return out;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int j, k;
        cin >> j >> k;
        T[j].push_back(k);
        T[k].push_back(j);
    }
    bool total = true;
    for(int i = 1; i <= n ;i++){
        if(list[i] == 0){
            total = dfs(i,0);
        }
        if(total == false){
            break;
        }
    }
    if(total){
        cout << "Good" << endl;
    }
    else{
        cout << "Bad" << endl;
    }
}
