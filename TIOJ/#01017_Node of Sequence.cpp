#include <iostream>
#include <cstdio>
#define N 1000000
using namespace std;

int t, n, maximum, minimum;
int num[N+5], ans;
bool f[N+5];

int main() {
    scanf("%d",&t);
    for (int i = 0; i < t; i++) {
        scanf("%d",&n);
        ans = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d",&num[j]);
            f[j] = 0;
        }
        maximum = num[0];
        for (int j = 1; j < n; j++) {
            if (num[j] > maximum) f[j] = 1;
            maximum = max(maximum, num[j]);
        }
        minimum = num[n-1];
        for (int j = n-1; j >= 0; j--) {
            if (num[j] >= minimum) f[j] = 0;
            minimum = min(minimum, num[j]);
        }
        for (int j = 0; j < n; j++) {
            if (f[j]) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
