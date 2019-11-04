#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define MAXN 7000
#define pb push_back
#define int long long
using namespace std;

int n, ans, s;
int a[MAXN+5], b[MAXN+5];
map <int,int> appr;
vector <int> v;

signed main() {
	Hina;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) {
		if (appr.count(a[i])) {
			ans += b[appr[a[i]]] + b[i];
			b[appr[a[i]]] = b[i] = 0;
			if (appr[a[i]] != n) v.pb(a[i]);
			appr[a[i]] = n;
		} else {
			appr[a[i]] = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!b[i]) continue;
		for (int j = 0; j < v.size(); j++) {
			if ((a[i]|v[j]) == v[j]) {
				ans += b[i];
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}