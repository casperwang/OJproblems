#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;

int n, m, a, t, ans;
priority_queue <int, vector<int>, greater<int>> nxt;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		nxt.push(a);
	}
	for (int i = m; i < n; i++) {
		cin >> a;
		t = nxt.top(), nxt.pop();
		nxt.push(t + a);
	}
	while (nxt.size()) {
		ans = max(ans, nxt.top());
		nxt.pop();
	}
	cout << ans << '\n';
}