
#include <iostream>

using namespace std;

int main()
{
    int list[1000001] = {0,1,1,1};
    int temp = 4;
    while(temp != 1000001){
        list[temp] = list[temp/2 -1] + list[temp/2] + list[temp/2+1];
        temp++;
    }

    int count = 0;
    cin >> count;
    while(count != 0){
        int tempa = 0;
        cin >> tempa;
        cout << list[tempa] << endl;
        count--;
    }
}
