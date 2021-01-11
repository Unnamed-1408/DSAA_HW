#include <iostream>
#include <vector>

using namespace std;
long long calculate(int n);

vector<int> *T;
int *status;
int counta = 0;
int countb = 0;

void dfsa(int start){
    status[start] = 1;
    for(int i = 0; i < T[start].size(); i++){
        if(status[T[start][i]] == 1)
            continue;
        else{
            counta++;
            dfsa(T[start][i]);
        }
    }
}

void dfsb(int start){
    status[start] = 2;
//    cout << start << endl;
    for(int i = 0; i < T[start].size(); i++){
        if(status[T[start][i]] == 1){
            counta--;
            status[T[start][i]] = 2;
            dfsb(T[start][i]);
        }
        else if(status[T[start][i]] == 0){
            countb++;
            dfsb(T[start][i]);
        }
        else if(status[T[start][i]] == 2){
            continue;
        }
    }
}

int n, m, a, b;
int main()
{

    cin >> n >> m >> a >> b;
    T = new vector<int>[n+1];
    status = new int[n + 1]();
    for(int k = 0; k < m; k++){
        int i, j;
        cin >> i >> j;
        T[i].push_back(j);
        T[j].push_back(i);
    }
//    long long total = (n - 2)*(n - 3)/2;
    status[b] = 1;
    dfsa(a);
//    cout << counta << endl;
    status[a] = 2;
    dfsb(b);
//    cout << counta << "  " <<countb << endl;
    cout << counta * countb << endl;
}

//long long calculate(int n){
//    long long tmp = 0;
//    status[a] = 1;
//    for(int i = 1; i <= n; i++){
//        if(status[i] == 0){
//            dfs(i);
//        }
//    }
//}
