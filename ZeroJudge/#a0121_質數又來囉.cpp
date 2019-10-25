#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define pb push_back
#define int long long
#define MAXN 1000000
using namespace std;
 
int a, b, cnt;
bool tf;
bool not_prime[MAXN+5];
vector <int> primes;

signed main() {
	Hina;
	for (int i = 2; i <= MAXN; i++) {
		if (!not_prime[i]) primes.pb(i);
		for (int j = 0; j < primes.size() && i*primes[j] <= MAXN; j++) {
			not_prime[i*primes[j]] = 1;
			if (i % primes[j] == 0) break;
		}
	}
	while (cin >> a >> b) {
		cnt = 0;
		for (int i = a; i <= b; i++) {
			tf = i > 1;
			for (int j = 0; primes[j] <= sqrt(i); j++) {
				if (i % primes[j] == 0) {
					tf = 0;
					break;
				}
			}
			if (tf) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}