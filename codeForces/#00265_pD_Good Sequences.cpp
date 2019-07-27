#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;
 
int n, ans=1;
int arr[MAXN+5], dp[MAXN+5];
int pri[MAXN+5];
 
void mdy(int num, int k) {
  for (int i = 1; i <= (int)sqrt(num); i++) {
    if (num % i == 0) {
      pri[i] = max(pri[i], k);
      pri[num/i] = max(pri[num/i], k);
    }
  } 
}
 
int maxLen(int num) {
  int val = pri[num];
  for (int i = 2; i <= (int)sqrt(num); i++) {
    if (num % i == 0) {
      val = max(val, max(pri[i], pri[num/i]));
    }
  }
  return val+1;
}
 
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  dp[1] = 1;
  mdy(arr[1], 1);
  for (int i = 2; i <= n; i++) {
    dp[i] = maxLen(arr[i]);
    ans = max(ans,dp[i]);
    mdy(arr[i], dp[i]);
  }
  cout << ans << endl; 
}

