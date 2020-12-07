#include <iostream>

using namespace std;
inline int read();
int *A = new int[200000];
int *stack = new int[200000];
int ptr = -1;

int main()
{
    int count = 0;
    count = read();
    while(count--){
    int *ans = new int[200000]{};
    ptr = -1;
    int T = 0;
    T = read();
    int temp = 0;
    while(temp != T){
        A[temp] = read();
        temp++;
    }

    temp = 0;
    while(temp != T){
            while(ptr != -1 && A[temp] > A[stack[ptr]]){
                ans[stack[ptr]] = temp - stack[ptr];
                ptr--;
            }
            stack[++ptr] = temp;
            temp++;
    }

    temp = read();
    while(temp--){
        int a = read();
        if(ans[a-1] != 0)
            printf("%d\n",ans[a-1]);
        else
            printf("-1\n");
    }
    delete []ans;
    }
}

inline int read() {
    int X = 0;
    bool flag = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
       // if (ch == '-')
        //    flag = 0;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        X = (X << 1) + (X << 3) + ch - '0';
        ch = getchar();
    }
    if (flag)
        return X;
    return ~(X - 1);
}
inline void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
