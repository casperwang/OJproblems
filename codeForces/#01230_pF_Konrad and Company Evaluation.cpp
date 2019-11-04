#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define MAXN 100000
#define int long long
#define pb push_back
using namespace std;

int n, m, q;
int a, b, ans;
int in[MAXN+5], out[MAXN+5];
vector <int> path[MAXN+5];

signed main() {
	Hina;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		path[min(a, b)].pb(max(a, b));
		in[min(a, b)]++;
		out[max(a, b)]++;
	}
	for (int i = 1; i <= n; i++) {
		ans += in[i] * out[i];
	}
	cout << ans << endl;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a;
		ans -= in[a] * out[a];
		out[a] += in[a];
		in[a] = 0;
		for (int j = 0; j < path[a].size(); j++) {
			path[path[a][j]].pb(a);
			ans -= in[path[a][j]] * out[path[a][j]];
			in[path[a][j]]++, out[path[a][j]]--;
			ans += in[path[a][j]] * out[path[a][j]];
		}
		path[a].clear();
		cout << ans << endl;
	}
	return 0;
}