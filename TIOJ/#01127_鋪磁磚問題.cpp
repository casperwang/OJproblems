#include <cstdio>
using namespace std;
// by C
long long int dp[40+5][2];
int n;
int main() {
  dp[1][0] = 1;
  dp[1][1] = 1;
  for (int i = 3; i <= 41; i+=2) {
    dp[i][0] = dp[i-2][0]*3 + dp[i-2][1];
    dp[i][1] = dp[i-2][0]*2 + dp[i-2][1];
  }
  while (scanf("%d",&n)!=EOF) {
    printf("%lld\n",dp[n][0]);
  }
}
