#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define pb push_back
#define INF 1e18
using namespace std;

int a, b, n;
int m, t;
bool tf;
unordered_map <int, int> appr;

int pw(int a, int k) {
	int cnt = 1, mul = 1;
	for (; cnt <= k; cnt <<= 1) {
		if (cnt & k) mul = (mul * a) % n;
		a = (a * a) % n;
	}
	return mul;
}

signed main() {
	Hina;
	while (cin >> a >> b >> n) {
		tf = 0;
		m = sqrt(n);
		t = pw(a, m);
		appr.clear();
		for (int r = 1; r <= m; r++) {
			appr[(b*pw(a, r))%n] = r;
		}
		for (int k = 1; k <= n/m; k++) {
			if (appr[pw(t, k)]) {
				cout << m*k-appr[pw(t, k)] << endl;
				tf = 1;
				break;
			}
		}
		if (!tf) cout << "NOT FOUND" << endl;
	}
	return 0;
}