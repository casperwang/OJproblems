#include <iostream>
#include <cstdio>
#define N 1048576

short n;
int tmp;
bool num[N+5];

int main() {
    while (scanf("%d",&n) && n) {
        for (int i = 0; i < N; i++) {
            num[i] = 0;
        }
        num[0] = 1;
        for (short i = 0; i < n; i++) {
            scanf("%d",&tmp);
            for (int j = 0; j < N; j++) {
                if (num[j]) num[tmp^j] = 1;
            }
        }
        for (int i = N-1; i >= 0; i--) {
            if (num[i]) {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
