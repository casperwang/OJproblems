#include <bits/stdc++.h>
#define MAXN 10000000
#define pb push_back
using namespace std;

int t, n;
short cnt[MAXN+5];
vector <bool> not_prime;
vector <int> primes;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	not_prime.resize(MAXN+5);
	cnt[1] = 1;
	for (int i = 2; i <= MAXN; i++) {
		if (!not_prime[i])
			primes.pb(i), cnt[i] = 2;
		for (int p : primes) {
			if (i*p > MAXN) break;
			not_prime[i*p] = 1;
			if (i%p == 0) {
				int t = i, c = 2;
				while (t%p == 0) t/=p, c++;
				cnt[i*p] = cnt[t]*c;
				break;
			} else cnt[i*p] = cnt[i]*cnt[p];
		}
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << cnt[n] << '\n';
	}
}