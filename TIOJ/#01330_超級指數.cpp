#include <cstdio>
// by C
int t, n;
int main() {
  scanf("%d",&t);
  for (int i = 1; i <= t; i++) {
    scanf("%d",&n);
    printf("%d\n",n%2);
  }
}
