#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int t, n;
int a, b;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			if (!(i^1)) cin >> b;
			else cin >> a;
			if (i && b^1) {
				b /= __gcd(b, a);
			}
		}
		if (!(b^1)) cout << "Asssss!!\n";
		else cout << "zzz...\n";
	}
  return 0;
}