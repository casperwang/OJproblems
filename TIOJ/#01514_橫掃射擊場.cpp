#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define MAXN 1000000
#define pb push_back
using namespace std;

int n;
bool not_prime[MAXN+5];
int phi[MAXN+5];
vector <int> primes;

signed main() {
	Hina;
	for (int i = 2; i <= MAXN; i++) {
		if (!not_prime[i]) {
			phi[i] = i-1;
			primes.pb(i);
		}
		for (int j = 0; j < primes.size() && primes[j]*i <= MAXN; j++) {
			not_prime[primes[j]*i] = 1;
			if (i % primes[j] == 0) {
				phi[primes[j]*i] = phi[i] * primes[j];
				break;
			} else {
				phi[primes[j]*i] = phi[i] * phi[primes[j]];
			}
		}
	}
	for (int i = 1; i <= MAXN; i++) phi[i] += phi[i-1];
	while (cin >> n) {
		if (n < 0) return 0;
		cout << phi[n]*2+3 << endl; 
	}
	return 0;
}