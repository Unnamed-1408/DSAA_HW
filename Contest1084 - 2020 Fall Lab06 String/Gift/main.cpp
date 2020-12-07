#include <iostream>

using namespace std;

int* find_next(string a){
    int* next = new int[a.length()+1]();
    int front = 0;
    int last = -1;
    next[0] = -1;

    while(front < a.length()){

        if(last == -1 || a.at(front) == a.at(last)){
            next[++front] = ++last;
        }
        else{
            last = next[last];
        }
    }
    return next+1;
}

void kmp(string a){
    int *next = find_next(a);
    int R = next[a.length()-1];
    int temp = a.length() - R;
    int c = temp - R;
    while(c < 0 || c > temp){
        if(c < 0){
            c += temp;
        }
        else{
            c%=temp;
        }
    }
    printf("%d\n",c);
}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T = 0;
    cin >> T;
    while(T--){
        string temp = "";
        cin >> temp;
        kmp(temp);
    }
}
