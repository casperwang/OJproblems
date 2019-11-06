#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

short m, n;
int sum;
int arr[100];
bool dp[MAXN+5];

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> m >> n;
  for (register int i = 0; i < m; i++) {
    sum = 0;
    for (register int j = 0; j < n; j++) cin >> arr[j], sum += arr[j];
    for (register int j = 0; j <= sum/2; j++) dp[j] = 0;
    if (sum/2*2 != sum) {
      cout << "No" << '\n';
      continue;
    }
    dp[sum/2] = 1;
    for (register int j = 0; j < n; j++) {
      for (register int k = arr[j]; k <= sum/2; k++) {
        if (dp[k]) dp[k-arr[j]] = 1;
      }
    }
    if (dp[0]) cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }
  return 0;
}