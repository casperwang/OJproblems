#include <iostream>
#include <cstdio>
#define INF 2147483647
using namespace std;
int n, t;
int a[50+5], dp[50+5][50+5];
int DP(int x, int y) {
  if (dp[x][y] > -1) return dp[x][y];
  if (x+1 == y) {
  	dp[x][y] = 0;
  } else {
  	int ans = INF;
  	for (int i = x+1; i < y; i++) {
  	  ans = min(ans, DP(x, i) + DP(i, y));
	}
	dp[x][y] = ans + a[y] - a[x];
  }
  return dp[x][y];
}
int main() {
  while (scanf("%d",&n)) {
  	if (!n) return 0;
  	for (int i = 0; i <= 50; i++) {
  	  for (int j = 0; j <= 50; j++) {
  	  	dp[i][j] = -1;
  	  }
  	}
  	scanf("%d",&t);
  	a[0] = 0; a[t+1] = n;
  	for (int i = 1; i <= t; i++) scanf("%d",&a[i]);
  	printf("The minimum cutting is %d.\n", DP(0, t+1));
  }
  return 0;
}
