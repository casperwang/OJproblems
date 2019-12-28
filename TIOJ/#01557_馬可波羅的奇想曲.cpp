#include <bits/stdc++.h>
#define pb push_back
#define MAXN 10000
#define MOD 1073741824
using namespace std;

int n, m;
int a, b;
bool vis[MAXN+5];
int cnt[MAXN+5];
int deg[MAXN+5];
vector <int> path[MAXN+5];

void DFS(int now) {
	for (int i : path[now]) {
		cnt[i] = (cnt[i] + cnt[now]) % MOD;
		deg[i]--;
		if (!deg[i]) DFS(i), vis[i] = 1;
	}
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
  	cin >> a >> b;
  	path[a].pb(b);
  	deg[b]++;
  }
  cin >> a >> b;
  cnt[a] = 1;
  for (int i = 1; i <= n; i++) {
  	if (!deg[i] && !vis[i]) DFS(i), vis[i] = 1;
  }
  cout << cnt[b] << '\n';
}