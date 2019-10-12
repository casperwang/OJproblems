#include <bits/stdc++.h>
#define MAXN 5000
#define pb push_back
#define int long long
using namespace std;

int n, k;
bool not_prime[MAXN+5];
vector <int> primes;

signed main() {
	for (int i = 2; i <= MAXN; i++) {
		if (!not_prime[i]) primes.pb(i);
		for (int j = 0; j < primes.size() && primes[j]*i <= MAXN; j++) {
			not_prime[primes[j]*i] = 1;
			if (i % primes[j] == 0) break;
		}
	}
	while (cin >> n) {
		k = 0;
		//primes between 1 ~ 10: 2 3 5 7
		cout << "primes between 1 ~ " << n << ":";
		while (primes[k] <= n && k < primes.size()) {
			cout << " " << primes[k];
			k++;
		}
		cout << endl;
	}
}