#include <iostream>

using namespace std;
struct quene{
   int *que = new int[3000000];
   int top = 0;
   int tail = -1;
} ans;
void push(quene* b,int a);
int top(quene* b);
void pop(quene* b);
int *A = new int[3000000];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int k = 0;
    int n = 0;
    cin >> k >> n;

    for(int i = 0;i < n; i++){
        cin >> A[i];
    }

    int max = 0;

    for(int i = 0;i < n; i++){
        if(A[i] > ans.top && A[i] < ans.top+k){
            push(&ans,i);
        }
        else if(A[i] > ans.top+k){
            while(A[i] > ans.top+k && ans.top <= ans.tail){
                pop(&ans);
            }
            push(&ans,i);
        }
        if(max < i - ans.top){
            max = i - ans.top+1;
        }
    }
    printf("%d\n",max);
}

void push(quene* b,int a){
    b->que[++b->tail] = a;
}

int top(quene* b){
    return b->que[b->top];
}
void pop(quene* b){
    b->top++;
}
