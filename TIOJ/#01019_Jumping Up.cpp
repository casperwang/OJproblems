#include <bits/stdc++.h>
#define MAXN 1000
#define int long long
using namespace std;

int t, n;
int arr[MAXN+5];
int dp[MAXN+5];

int ab(int a, int b) {
  if (a > b) return a-b;
  else return b-a;
}

signed main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> arr[j];
      if (j >= 2) dp[j] = min(dp[j-2]+ab(arr[j], arr[j-2]), dp[j-1]+ab(arr[j], arr[j-1]));
      else if (j == 1) dp[j] = dp[j-1]+ab(arr[j], arr[j-1]);
    }
    cout << dp[n-1] << endl;
  }
}