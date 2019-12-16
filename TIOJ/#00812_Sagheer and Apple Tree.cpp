#include <bits/stdc++.h>
#define MAXN 100000
#define pb push_back
#define int long long
using namespace std;

int n, tmp, ans;
int r, b, x;
int a[MAXN+5];
bool v[MAXN+5];
int cnt[(1<<24)+5];
vector <int> path[MAXN+5];

int dfs(int now) {
	bool tf = 0;
	for (int i : path[now])
		tf = dfs(i);
	v[now] = tf;
	return !tf;
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
  	cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
  	cin >> tmp;
  	path[tmp].pb(i);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
  	if (v[i]) b++;
  	else r++, x ^= a[i];
  }
  if (!x) {
  	ans = b*(b-1)/2 + r*(r-1)/2;
  	for (int i = 1; i <= n; i++)
  		if (v[i]) cnt[a[i]]++;
  	for (int i = 1; i <= n; i++)
  		if (!v[i]) ans += cnt[a[i]];
  } else {
  	for (int i = 1; i <= n; i++)
  		if (v[i]) cnt[a[i]]++;
  	for (int i = 1; i <= n; i++)
  		if (!v[i]) ans += cnt[a[i]^x];
  }
  cout << ans << '\n';
}