#include <iostream>
#include <cstdio>
#define N 1000
using namespace std;

int n, a[N+5], tmp, ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    a[0] = 0;
    a[n+1] = 1001;
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i-1]+1 && a[i]+1 == a[i+1]) {
            tmp++;
        } else {
            tmp = 0;
        }
        ans = max(ans, tmp);
    }
    printf("%d\n", ans);
    return 0;
}
