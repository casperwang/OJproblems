#include <bits/stdc++.h>
#define MAXN 10000
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define int short
using namespace std;

int n, a;
bool not_prime[MAXN+5];
vector <int> primes;
vector <pii> ans[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	primes.reserve(1229);
	for (int i = 2; i <= MAXN; i++) {
		if (!not_prime[i]) primes.pb(i);
		for (int j = 0; j < primes.size(); j++) {
			if (primes[j] * i > MAXN) break;
			not_prime[primes[j] * i] = 1;
			if (i % primes[j] == 0) break;
		}
		ans[i].reserve(primes.size());
	}
	ans[0].pb(pii(1,1));
	ans[1].pb(pii(1,1));
	ans[2].pb(pii(2,1));
	for (int i = 3; i <= MAXN; i++) {
		for (pii k : ans[i-1])
			ans[i].pb(k);
		int tmp = i;
		for (int j = 0; j < primes.size(); j++) {
			while (tmp % primes[j] == 0) {
				tmp /= primes[j];
				if (ans[i].size() > j) ans[i][j].ss++;
				else ans[i].pb(pii(primes[j], 1));
			}
		}
	}
	cin >> n;
	while (n--) {
		cin >> a;
		for (int i = 0; i < ans[a].size(); i++) {
			if (i) cout << '*';
			cout << '(';
			cout << ans[a][i].ff;
			if (ans[a][i].ss > 1) cout << '^' << ans[a][i].ss;
			cout << ')';
		}
		cout << '\n';
	}
}