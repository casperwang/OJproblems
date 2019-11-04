#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define INF 1e18
#define int long long
#define MAXN 500000
#define ff first
#define ss second
using namespace std;

int n;
double ans;
pair <int,int> pt[MAXN+5];

double dis(int i, int j) {
	return hypot(pt[j].ff-pt[i].ff, pt[j].ss-pt[i].ss);
}

signed main() {
	Hina;
	while (cin >> n) {
		ans = INF;
		for (register int i = 0; i < n; i++) {
			cin >> pt[i].ff >> pt[i].ss;
		}
		sort(pt, pt+n);
		for (register int i = 0; i < n; i++) {
			for (register int j = i-1; j >= 0; j--) {
				if (pt[i].ff - pt[j].ff >= ans) break;
				ans = min(ans, dis(i, j));
			}
		}
		cout << fixed << setprecision(6) << ans << "\n";
	}
	return 0;
}