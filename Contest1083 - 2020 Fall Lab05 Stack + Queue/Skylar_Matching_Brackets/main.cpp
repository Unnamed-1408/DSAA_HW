#include <iostream>

using namespace std;
bool Test(int n);

char stack[30000];
int stack_ptr = -1;

int main()
{
    int T = 0;
    cin >> T;
    while(T--){
    stack_ptr = -1;
    int n = 0;
    cin >> n;
    if(Test(n)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO"<< endl;
    }
}
}

bool Test(int n){
    if(n == 1){
        char a;
        cin >> a;
        return false;
    }
    bool out = true;
    while(n--){
        char a;
        cin >> a;
        if(a == ')' || a== ']' || a=='}'){
            if(stack_ptr != -1 && ((a - stack[stack_ptr] == 1)||(a - stack[stack_ptr] == 2))){
                stack_ptr--;
            }
            else{
                out = false;
            }
        }
        else{
            stack[++stack_ptr] = a;
        }
    }
    if(stack_ptr != -1){
        out = false;
    }
    return out;
}
