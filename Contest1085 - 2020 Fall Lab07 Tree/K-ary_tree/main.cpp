#include <iostream>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T = 0;
    cin >> T;
    while(T--){
        long long N,K;
        cin >> N >> K;
        cout << (N*K-N+1)/K << endl;
    }
}
