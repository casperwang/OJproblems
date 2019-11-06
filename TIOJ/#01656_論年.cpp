#include <cstdio>
short n;
signed main() {
  while (scanf("%d",&n) != EOF) {
  	(n%3)||!(n%9)&&(n%27)?puts("happy"):puts("sad");
  }
}