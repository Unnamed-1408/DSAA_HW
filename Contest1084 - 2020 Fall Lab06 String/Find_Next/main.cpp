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
    return next;
}

int main()
{
    string a = "";
    cin >> a;
    int *next = find_next(a);
    for(int i = 1; i<= a.length(); i++){
        printf("%d\n",next[i]);
    }
}
