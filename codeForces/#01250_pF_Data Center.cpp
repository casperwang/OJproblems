#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define MAXN 100000
#define ff first
#define ss second
using namespace std;

int n;

signed main() {
	Hina;
	cin >> n;
	for (int i = sqrt(n); i >= 1; i--) {
		if (n % i == 0) {
			cout << i*2 + n/i*2 << endl;
			return 0;
		}
	}
	return 0;
}