#include <bits/stdc++.h>
#define MAXN 1000000
#define INF 1e9
using namespace std;

long long n, sum, a;
signed mmin = INF;
signed arr[MAXN+5], val[MAXN+5], pos[MAXN+5];
signed dsu[MAXN+5], sze[MAXN+5], vis[MAXN+5];
signed min_val[MAXN+5];

int fnd(int now) {
	if (dsu[now] != now) dsu[now] = fnd(dsu[now]);
	return dsu[now];
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) min_val[i] = INF, dsu[i] = i, sze[i] = 1;
	for (int i = 1; i <= n; i++) cin >> val[i], mmin = min(mmin, val[i]);
	for (int i = 1; i <= n; i++) cin >> arr[i], pos[arr[i]] = i;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (fnd(a) != fnd(arr[i])) sze[min(dsu[a], dsu[arr[i]])] += sze[max(dsu[a], dsu[arr[i]])];
		dsu[max(dsu[a], dsu[arr[i]])] = min(dsu[a], dsu[arr[i]]);
		if (i != pos[a]) sum += val[a];
	}
	for (int i = 1; i <= n; i++) {
		fnd(i);
		min_val[dsu[i]] = min(min_val[dsu[i]], val[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[dsu[i]] || sze[dsu[i]] <= 2) continue;
		vis[dsu[i]] = 1;
		sum += min((long long)mmin*(sze[dsu[i]])+mmin+min_val[dsu[i]], (long long)min_val[dsu[i]]*(sze[dsu[i]]-2));
	}
	cout << sum << '\n';
	return 0;
}