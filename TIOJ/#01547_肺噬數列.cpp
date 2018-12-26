#include <cstdio>
int n, f[30+5], now;
int main() {
  scanf("%d",&n);
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = f[i-1] + f[i-2];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < f[i]; j++) printf("%d",(++now)%3);
    printf("\n");
  }
}
