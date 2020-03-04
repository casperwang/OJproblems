#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

const int INF = 2e18;
int n, m, a, b, ans;
int A, B;
bool tfA, tfB;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		if (!n) return 0;
		a = b = 0;
		tfA = tfB = 0;
		m = INF;
		for (int i = 0; i < n; i++) {
			cin >> A >> B;
			if (A < B) {
				a += A, tfB = 1;
				m = min(m, B - A);
			} else {
				b += B, tfA = 1;
				m = min(m, A - B);
			}
		}
		if (n == 1) {
			if (A && B) ans = -1;
			else ans = 0;
		} else if (!tfA || !tfB) {
			ans = a + b + m;
		} else {
			ans = a + b;
		}
		cout << ans << "\n";
	}
}