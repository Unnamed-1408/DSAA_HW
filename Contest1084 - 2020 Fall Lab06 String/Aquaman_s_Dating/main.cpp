#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n = 0;
    cin >> n;
    string list[n];
    for(int i = 0; i< n; i++){
        cin >> list[i];
    }

    int L_ptr = 0;
    int R_ptr = 0;
    bool L = true;
    bool R = true;
    while(L == true || R == true){
        char a = list[0].at(L_ptr);
        for(int i = 0; i < n;i++){

        }
    }
}
