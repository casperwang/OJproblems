#include <bits/stdc++.h>
#define MAXN 100000
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;

int n, m, ans;
int a[MAXN+5], b[MAXN+5];

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  	cin >> a[i];
  sort(a, a+n);
  for (int i = 0; i < m; i++)
  	cin >> b[i];
  sort(b, b+m);
  b[m] = 2e9;
  ans = max(a[0],b[0])-min(a[0],b[0]);
  for (int i = 0, j = 0; i < n && j < m; i++) {
  	while (b[j] < a[i])
  		ans = min(ans, a[i]-b[j]), j++;
  	if (b[j] >= a[i])
  		ans = min(ans, b[j]-a[i]);
  }
  cout << ans << '\n';
}