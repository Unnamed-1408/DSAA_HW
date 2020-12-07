#include <iostream>
#include <string>
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
    char *list =  new char[26];
    for(int i = 0; i < 26; i++){
        cin >> list[i];
    }

    string to_t = "";
    cin >> to_t;

    string to_target = "";
    for(int i = 0; i<to_t.length(); i++){
        to_target += list[to_t.at(i) - 'a'];
    }
//    cout << to_target<< endl;

    string total = to_t + to_target;
    int *next = find_next(total);
    cout << to_t.length() - next[total.length()] << endl;
}
