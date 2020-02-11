#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
#define pb push_back
using namespace std;

const int MAXN = 1100000;
int t, n, a, sum;
int phi[MAXN+5];
bool not_prime[MAXN+5];
vector <int> primes;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	phi[1] = 1;
	for (int i = 2; i <= MAXN; i++) {
		if (!not_prime[i])
			phi[i] = i-1, primes.pb(i);
		for (int j : primes) {
			if (j * i > MAXN) break;
			not_prime[i * j] = 1;
			if (i % j) phi[i * j] = phi[i] * phi[j];
			else {
				phi[i * j] = phi[i] * j;
				break;
			}
		}
	}
	cin >> t;
	while (t--) {
		cin >> n;
		sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			sum += phi[a];
		}
		cout << fixed << setprecision(2) << (double)sum/n << "\n";
	}
	return 0;
}