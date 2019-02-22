#include <bits/stdc++.h>
#define MAXN 100000+5
using namespace std;

long long int t, n, k;
long long int l, r, len, op;
string a;
long long int pre[MAXN];
int dp[MAXN];

int slope(int i, int j, int k) {
  long long int cross = (j - i) * (pre[k] - pre[j]) - (k - j) * (pre[j]- pre[i]);
  return (cross > 0) - (cross < 0);
}

int main(){
  scanf("%lld", &t);
  for (int p = 0; p < t; p++) {
    scanf("%lld%lld", &n, &k);
    cin >> a;
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i-1] + a[i-1]-'0';
    }
    l = 0;
    r = k;
    len = 1;
    op = 1;
    dp[1] = 0;
    for (int i = k+1; i <= n; i++) {
      while (len >= 2 && slope(dp[len-1], dp[len], i-k) != 1) {
        if (op == len) op--;
        len--;
      }
      dp[++len] = i-k;
      while (op < len && slope(dp[op], dp[op+1], i) != -1) op++;
      long long int a = (pre[i] - pre[dp[op]]) * (r-l);
      long long int b = (pre[r] - pre[l]) * (i - dp[op]);
      if (a > b || (a == b && (i - dp[op] < r - l))) {
        l = dp[op];
        r = i;
      }
    }
    printf("%lld %lld\n", l+1, r);
  } 
	return 0;
}
