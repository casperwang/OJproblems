#include <bits/stdc++.h>
#define MAXN 500000
#define INF 1e8
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n, q, num;
int a[MAXN+5];
int len[MAXN+5];
int ans[MAXN+5];
stack <pii> now;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		while (now.size() && a[i] >= now.top().ff) now.pop();
		if (now.empty()) len[i] = i;
		else len[i] = i - now.top().ss;
		now.push(pii(a[i], i));
	}
	while (now.size()) now.pop();
	for (int i = n; i >= 1; i--) {
		while (now.size() && a[i] >= now.top().ff) now.pop();
		if (now.empty()) len[i] += n - i;
		else len[i] += now.top().ss - i - 1;
		now.push(pii(a[i], i));
	}
	fill(ans, ans+1+n, INF);
	for (int i = 1; i <= n; i++)
		ans[len[i]] = min(ans[len[i]], a[i]);
	for (int i = n-1; i >= 1; i--)
		ans[i] = min(ans[i], ans[i+1]);
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> num;
		cout << ans[num] << '\n';
	}
}