#include <bits/stdc++.h>
#define MAXN 30000
using namespace std;

int k, d[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
long long int dp[MAXN+5];
double p;

int main(){
  dp[0] = 1;
  for (int i = 0; i < 11; i++) {
    for (int j = d[i]; j <= MAXN; j++) {
      dp[j] += dp[j-d[i]];
    }
  }
  while (cin >> p) {
    k = p * 100;
    if (k == 0) return 0;
    if (k % 5 == 4) k++;
    else if (k % 5 == 1) k--;
    printf("%6.2lf%17lld\n",p,dp[k]);
  }
}
