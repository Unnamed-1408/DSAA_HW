#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int T = 0;
    cin >> T;
    while(T--){
        long long a = 0;
        cin >> a;
        cout << (long long)log2(a) +1 << endl;
    }
}
