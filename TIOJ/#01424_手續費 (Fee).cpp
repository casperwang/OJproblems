#include <bits/stdc++.h>
using namespace std;

int n, a, b, ans;
priority_queue <int,vector<int>,greater<int>> nxt;

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a, nxt.push(a);
	}
	while (nxt.size() > 1) {
		a = nxt.top(), nxt.pop();
		b = nxt.top(), nxt.pop();
		ans += a+b, nxt.push(a+b);
	}
	cout << ans << '\n';
}