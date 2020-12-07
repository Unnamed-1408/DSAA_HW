#include <iostream>

using namespace std;

int *stack = new int[1000];
int stackptr = -1;
int *pre = new int[1000];
int *in = new int[1000];
void push(int a);
void output();

void ans(int a, int b, int count){
    if(count == 1){
        push(pre[a]);
        return;
    }
    else if(count <= 0){
        return;
    }
    int i = 0;
    for(i = 0; pre[a] != in[b+i]; i++);
    ans(a+1 , b , i);
    ans(a+i+1,b+i+1,count-i-1);
    push(pre[a]);
}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T = 0;
    cin >> T;
    while(T--){
        stackptr = -1;
        int N = 0;
        cin >> N;
        for(int i = 0; i < N ; i++){
            cin >> pre[i];
        }
        for(int i = 0; i< N ; i++){
            cin >> in[i];
        }
        ans(0,0,N);
        output();
    }
}

void output(){
    for(int i = 0; i <= stackptr;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

void push(int a){
    stack[++stackptr] = a;
}
