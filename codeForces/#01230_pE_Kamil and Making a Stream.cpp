#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define MAXN 100000
#define MOD 1000000007
#define pb push_back
#define int long long
using namespace std;

int n, x, y, ans;
int a[MAXN+5];
bool vis[MAXN+5];
map <int, int> appr[MAXN+5];
vector <int> path[MAXN+5];

void DFS(int now, int par) {
	appr[now][a[now]]++;
	for (int i = 0; i < path[now].size(); i++) {
		if (path[now][i] != par) {
			for (auto j : appr[now]) {
				appr[path[now][i]][__gcd(j.first, a[path[now][i]])] += j.second;
			}
			DFS(path[now][i], now);
		}
	}
	return;
}

signed main() {
	Hina;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		path[x].pb(y);
		path[y].pb(x);
	}
	DFS(1, 0);
	for (int i = 1; i <= n; i++) {
		for (auto j : appr[i]) {
			ans += j.second * j.first;
			ans %= MOD;
		}
	}
	cout << ans << "\n";
	return 0;
}