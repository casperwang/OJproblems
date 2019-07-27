#include <bits/stdc++.h>
#define int long long
#define MAXN 200000
using namespace std;

int n, f, sum, ans;
int num[MAXN+5];
int appr[MAXN+5];

signed main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    appr[num[i]]++;
  }
  for (int i = 1; i <= MAXN+1; i++) {
    sum += appr[i];
    if (appr[i] < 2) {
      if (sum > ans) {
        ans = sum;
        f = i;
      }
      sum = appr[i];
    }
  }
  cout << ans << endl;
  if (appr[f] == 1) cout << f << " ";
  if (appr[f] <= 1) f--;
  int k = f;
  while (appr[k] > 1) {
    while (appr[k] > 1) {
      cout << k << " ";
      appr[k]--;
    }
    k--;
  }
  if (!appr[k]) k++;
  for (; k <= f; k++) {
    cout << k << " \n"[k==f];
  }
  
  return 0;
}
