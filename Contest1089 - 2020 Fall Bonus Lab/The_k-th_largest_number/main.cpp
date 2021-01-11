#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> Max;

int main()
{
    int n = 0;
    cin >> n;

    while(n--){
        int i, j;
        cin >> i >> j;
        if(i == 1){
            Max.push(j);
        }
        else{
            j--;
            while(j--){
                Max.pop();
            }
            cout << Max.top() << endl;
        }
    }
    return 0;
}
