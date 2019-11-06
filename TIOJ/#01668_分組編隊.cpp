#include <bits/stdc++.h>
#define MAXN 100000
#define pb push_back
using namespace std;

int t, l, r;
int ans;
bool tf[MAXN*2+5];
bool not_prime[MAXN+5];
vector <int> primes;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	for (int i = 2; i <= MAXN; i++) {
		if (!not_prime[i]) primes.pb(i);
		for (int j = 0; j < primes.size(); j++) {
			if (primes[j] * i > MAXN) break;
			not_prime[primes[j] * i] = 1;
			if (i % primes[j] == 0) break;
		}
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> l >> r;
		ans = 0;
		for (int j = 0; j <= r-l; j++) tf[j] = 1;
		for (int j = 0; j < primes.size(); j++) {
			for (int k = max(primes[j]*2,l-l%(primes[j])); k <= r; k+=primes[j])
				if (k-l >= 0) tf[k-l] = 0;
		}
		for (int j = 0; j <= r-l; j++) {
			ans += tf[j];
		}
		cout << ans << '\n';
	}
	return 0;
}