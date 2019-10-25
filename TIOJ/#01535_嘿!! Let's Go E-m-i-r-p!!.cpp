#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define MAXN 12000000
#define int long long
#define pb push_back
using namespace std;

int n, a;
bool not_prime[MAXN+5];
vector <int> primes;
vector <int> emirp;

int re(int a) {
	int tmp = 0;
	while (a) {
		tmp = tmp * 10 + a % 10;
		a /= 10;
	}
	return tmp;
}

signed main() {
	Hina;
	for (int i = 2; i <= MAXN; i++) {
		if (!not_prime[i]) primes.pb(i);
		for (int j = 0; j < primes.size() && primes[j]*i <= MAXN; j++) {
			not_prime[primes[j]*i] = 1;
			if (i % primes[j] == 0) break;
		}
	}
	for (int i = 0; i < primes.size(); i++) {
		a = re(primes[i]);
		if (a == primes[i]) continue;
		if (a <= MAXN) {
			if (!not_prime[a]) emirp.pb(primes[i]);
		} else {
			bool tf = 1;
			for (int j = 0; primes[j] <= sqrt(a)*2; j++) {
				if (a % primes[j] == 0) {
					tf = 0;
					break;
				}
			}
			if (tf) emirp.pb(primes[i]);
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cout << emirp[a-1] << endl;
	}
	return 0;
}