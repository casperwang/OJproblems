#include <bits/stdc++.h>
#define pb push_back
#define MAXN 60000
#define pii pair<int,int>
using namespace std;

int n, q;
int a, b, ans, t;
vector <int> C[MAXN+5];
map <pii, int> appr;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
  	cin >> a;
  	C[a].pb(i);
  }
  for (int i = 0; i < q; i++) {
  	cin >> a >> b;
  	if (C[a].size() > C[b].size()) swap(a, b);
  	if (!C[a].size() || !C[b].size()) {
  		cout << -1 << '\n';
  		continue;
  	} else if (appr.count(pii(a, b))) {
  		cout << appr[pii(a, b)] << '\n';
  		continue;
  	}
  	ans = MAXN+5;
  	for (int j : C[a]) {
  		t = upper_bound(C[b].begin(), C[b].end(), j)-C[b].begin();
  		if (t < C[b].size()) ans = min(ans, C[b][t]-j);
  		if (t) ans = min(ans, j-C[b][t-1]);
  	}
  	cout << ans << '\n';
  	appr[pii(a, b)] = ans;
  }
}