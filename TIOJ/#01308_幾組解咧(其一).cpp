#include <cstdio>
long long int n, m, ans, k;
int factor[50+5];
int main() {
  while(scanf("%lld%lld",&n,&m) && n != 0) {
    ans = 1;
    for (int i = 2; i <= m+n-1; i++) {
      factor[i] = 0;
      k = i;
      for (int j = 2; j <= k; j++) {
        while(k % j == 0) {
          factor[j]++;
          k /= j;
        }
      }
    }
    for (int i = 2; i <= m; i++) {
      k = i;
      for (int j = 2; j <= k; j++) {
        while(k % j == 0) {
          factor[j]--;
          k /= j;
        }
      }
    }
    for (int i = 2; i <= n-1; i++) {
      k = i;
      for (int j = 2; j <= k; j++) {
        while(k % j == 0) {
          factor[j]--;
          k /= j;
        }
      }
    }
    for (int i = 2; i <= m+n-1; i++) {
      for (int j = 0; j < factor[i]; j++) ans *= i;
    }
    printf("%lld\n", ans);
  }
  return 0;
}

