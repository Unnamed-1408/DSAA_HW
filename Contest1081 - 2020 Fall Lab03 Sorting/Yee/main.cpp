#include <iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n = 0;
    int count = 0;
    cin >> n >> count;
    int temp = 0;
    long list[n];

    while(temp != n){
        cin >> list[temp];
        temp++;
    }

    sort(list,list+n);
    cout << list[count-1] << endl;

}
