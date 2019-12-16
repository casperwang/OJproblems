#include <bits/stdc++.h>
#define MAXN 2000000
#define pb push_back
using namespace std;

int n, a, t;
long long ans;
const int INF = (-1<<30);
int par[MAXN+5];
vector <int> appr;
stack <int> now;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	appr.resize(n);
	for (register int i = 0; i < n; i++) {
		cin >> a;
		appr[i] = a;
		t = INF;
		while (now.size() && a < now.top()) {
			if (t != INF) par[t] = now.top();
			par[now.top()] = a;
			t = now.top();
			now.pop();
		}
		if (now.size()) par[a] = now.top();
		else par[a] = INF;
		now.push(a);
	}
	for (register int i = 0; i < n; i++) {
		if (par[appr[i]] == INF) continue;
		ans += (long long)(appr[i]-par[appr[i]])*(appr[i]-par[appr[i]]);
	}
	cout << ans << '\n';
}