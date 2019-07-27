#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;

int n, ans, k;
int num[MAXN+5], pos[MAXN+5];
int arr[MAXN+5][30];

void update(int l, int r, int m, int p) {
  if (r-l <= 1) return;
  if (p-l < r-p) {
    for (int i = l; i <= p-1; i++) {
      if (m-num[i] >= 1 && m-num[i] <= n && pos[m-num[i]] > p && pos[m-num[i]] <= r) ans++;
    }
  } else {
    for (int i = p+1; i <= r; i++) {
      if (m-num[i] >= 1 && m-num[i] <= n && pos[m-num[i]] < p && pos[m-num[i]] >= l) ans++;
    }
  }
  int k, s;
  if (p-l > 0) {
    k = floor(log2(p-l));
    s = max(arr[l][k], arr[p-(int)pow(2,k)][k]);
    update(l, p-1, s, pos[s]);
  }
  if (r-p > 0) {
    k = floor(log2(r-p));
    s = max(arr[p+1][k], arr[r+1-(int)pow(2,k)][k]);
    update(p+1, r, s, pos[s]);
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    arr[i][0] = num[i];
    pos[num[i]] = i;
    if (num[i] == n) k = i;
  }
  k = 2;
  for (int i = 1; i <= floor(log2(n)); i++) {
    for (int j = 1; j <= n-k+1; j++) {
      arr[j][i] = max(arr[j][i-1], arr[j+k/2][i-1]);
      //cout << arr[j][i] << " ";
    }
    k *= 2;
    //cout << endl;
  }
  for (int i = 1; i <= n; i++) {
    if (num[i] == n) k = i;
  }
  update(1, n, n, k);
  cout << ans << endl;
}
