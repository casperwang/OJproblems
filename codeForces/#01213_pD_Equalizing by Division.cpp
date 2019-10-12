#include <bits/stdc++.h>
#define MAXN 200000
#define INF 1e18
#define int long long
using namespace std;

int n, k, p, ans, sum;
int a[MAXN+5];
vector <int> val[MAXN+5];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p = 0;
    while (a[i] > 0) {
      val[a[i]].push_back(p);
      p++;
      a[i] /= 2;
    }
    val[0].push_back(p);
  }
  ans = INF;
  for (int i = 0; i <= MAXN; i++) {
    sort(val[i].begin(), val[i].end());
    if (val[i].size() >= k) {
      sum = 0;
      for (int j = 0; j < k; j++) sum += val[i][j];
      ans = min(ans, sum);
    }
  }
  cout << ans << endl;
} 

