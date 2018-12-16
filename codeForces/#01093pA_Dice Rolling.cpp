#include <iostream>
#include <cstdio>

int t, n, ans;

int main() {
    scanf("%d",&t);
    for (int i = 0; i < t; i++) {
        scanf("%d",&n);
        ans = (n+2)/3;
        printf("%d\n",ans);
    }
    return 0;
}
