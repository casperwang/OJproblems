#include <bits/stdc++.h>
#define MAXN 1000
#define int long long
using namespace std;

int n, ans;
int A[MAXN+5], B[MAXN+5], C[MAXN+5];

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= n; i++) cin >> B[i];
  for (int i = 2; i <= n; i++) cin >> C[i];
  for (int i = 1; i <= n; i++) {
  	ans += B[A[i]];
  	if (i>1 && A[i] - A[i-1] == 1) ans += C[A[i]];
  }
  cout << ans << endl;
  return 0;
}