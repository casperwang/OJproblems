#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0);
#define MAXN 1500000
#define pb push_back
using namespace std;

int n, m, arr[MAXN+5];
bool appr[MAXN+5];
bool not_prime[MAXN+5];
bool tf = 1;
vector <int> primes;

signed main() {
	Hina;
	cin >> n;
	for (int i = 2; i <= MAXN; i++) {
		if (!not_prime[i]) primes.pb(i);
		for (int j = 0; j < primes.size(); j++) {
			if (primes[j] * i > MAXN) break;
			not_prime[primes[j] * i] = 1;
			if (i % primes[j] == 0) break;
		}
	}
	m = 2;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (!tf) arr[i] = m;
		while (appr[arr[i]]) arr[i]++, tf = 0;
		if (!not_prime[arr[i]]) {
			for (int j = arr[i]; j <= MAXN; j += arr[i]) {
				appr[j] = 1;
			}
		} else {
			int tmp = arr[i];
			for (int j = 0; j < primes.size() && tmp > 1; j++) {
				if (tmp % primes[j] == 0) {
					while (tmp % primes[j] == 0) tmp /= primes[j];
					for (int k = primes[j]; k <= MAXN; k += primes[j]) {
						appr[k] = 1;
					}
				}
				if (!not_prime[tmp]) break;
			}
			if (tmp > 1) {
				for (int j = tmp; j <= MAXN; j += tmp) {
					appr[j] = 1;
				}
			}
		}
		while (appr[m]) m++;
		cout << arr[i] << " \n"[i==n-1];
	}
	return 0;
}