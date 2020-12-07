#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int M = 1e5 + 10;
int a[M] , Next[M] , pre[M] , que[M];
int main() {
    int t;
    scanf("%d" , &t);
    while(t--) {
        int n;
        scanf("%d" , &n);
        Next[0] = 1;
        pre[n + 1] = n;
        int tot = 0;
        for(int i = 1 ; i <= n ; i++) {
            scanf("%d" , &a[i]);
            que[tot++] = i;
            Next[i] = i + 1;
            pre[i] = i - 1;
        }
        int flag = 0;
        int ans = n;
        while(!flag) {
            flag = 1;
            int pos = 0;
            int useful = 0;
            while(pos < tot) {
                int now = que[pos];
                int cnt = 0;
                while(Next[now] <= n) {
                    if(a[now] > a[Next[now]]) now = Next[now] , cnt++ , flag = 0;
                    else break;
                }
                if(cnt) {
                    ans -= (cnt + 1);
                    Next[pre[que[pos]]] = Next[now];
                    pre[Next[now]] = pre[que[pos]];
                    que[useful++] = pre[que[pos]];
                }
                while(que[pos] <= now && pos < tot) pos++;
            }
            tot = useful;
        }
//        printf("%d\n" , ans);
        int now = Next[0];
        while(ans--) {
            printf("%d " , a[now]);
            now = Next[now];
        }
        printf("\n");
    }
    return 0;
}
