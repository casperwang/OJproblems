#include <cstdio>
int n, a, ans[180];
int main() {
  for (int i = 180; i > 0; i--) {
    if (180 % i == 0) {
        for (int j = 180/i; j <= 180-360/i; j += 180/i) {
          ans[j] = i;
        }
    } else if ((180*(i-2))%i == 0) {
      ans[(180*(i-2))/i] = i;
    }
  }
  ans[179] = 360;
  scanf("%d",&n);
  for (int i = 0; i < n; i++) {
    scanf("%d",&a);
    printf("%d\n",ans[a]);
  }
}
