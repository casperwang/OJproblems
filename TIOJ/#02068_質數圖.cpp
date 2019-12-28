#include <bits/stdc++.h>
#define MAXN 2345678
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n, now;
bool vis[MAXN*4+5];
bool not_prime[MAXN*4+5];
vector <pii> ans;
vector <int> primes;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 2; i <= 4*n; i++) {
		if (!not_prime[i])
			primes.pb(i);
		for (int j = 0; j < primes.size(); j++) {
			if (i * primes[j] > 4*n) break;
			not_prime[i * primes[j]] = 1;
			if (i % primes[j] == 0) break;
		}
	}
	for (int i = primes.size()-1; i >= 0; i--) {
		while (!vis[now] && !vis[4*n-primes[i]-now]) {
			vis[now] = vis[4*n-primes[i]-now] = 1;
			ans.pb(pii(now, 4*n-primes[i]-now));
			now++;
		}
		while (now <= 4*n && vis[now]) now++;
		if (now > 4*n) break;
	}
	for (pii i : ans)
		cout << i.ff << " " << i.ss << "\n";
}