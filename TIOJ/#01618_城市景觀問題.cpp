#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

const int MAXN = 500000;
const int INF = 1e18;
int n, k, sum;
int h[MAXN+5];
int v[MAXN+5];
pii ans;
deque <pii> now;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	ans.ff = -INF;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++) {
		while (now.size() && i-now.front().ss >= k)
			sum -= v[now.front().ss], now.pop_front();
		while (now.size() && h[i] >= now.back().ff)
			sum -= v[now.back().ss], now.pop_back();
		now.push_back(pii(h[i], i));
		sum += v[i];
		ans = max(ans, pii(sum, i));
	}
	cout << ans.ss << " " << ans.ff << "\n";
	return 0;
}