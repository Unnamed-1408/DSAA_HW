#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std; const int N = 50010;
 
int L, n, m;
int d[N];
 
bool check(int mid)
{
    int last = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
        if (d[i] - last < mid) cnt++;
        else last = d[i];
    return cnt <= m;
}
 
int main()
{
    scanf("%d%d%d", &L, &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
    d[++n] = L;
 
    int l = 1, r = 1e9;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
 
    printf("%d\n", r);
    return 0;
}
