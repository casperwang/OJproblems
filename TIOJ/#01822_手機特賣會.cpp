#include <bits/stdc++.h>
#define MAXN 300000
#define pb push_back
using namespace std;

int n, m, a;
int arr[MAXN+5];
int cnt[MAXN+5];
vector <int> ans;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		arr[a]++;
	}
	for (int i = 1; i <= n; i++) {
		arr[i] %= 2;
		if (arr[i])
			for (int j = i; j <= n; j += i)
				cnt[j]++;
		if (cnt[i] % 2) ans.pb(i);
	}
	cout << ans.size() << '\n';
	for (int i : ans) cout << i << '\n';
}