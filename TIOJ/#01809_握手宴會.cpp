#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, q;
int a, b;
unordered_set <int> appr;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		appr.insert(a*(n+1)+b);
	}
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		if (appr.count(a*(n+1)+b))
			cout << "yes\n";
		else
			cout << "no\n";
	}
}