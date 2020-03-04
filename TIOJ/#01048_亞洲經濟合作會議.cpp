#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n, m;
int f[15];
vector <char> abc;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	f[0] = 1;
	for (int i = 1; i < 15; i++)
		f[i] = f[i-1] * i;
	while (cin >> n >> m) {
		if (!n && !m) return 0;
		for (int i = 0; i < n; i++)
			abc.pb((char)('A'+i));
		m = (m-1) % f[n];
		for (int i = n-1; i >= 0; i--) {
			cout << abc[m / f[i]] << " \n"[!i];
			abc.erase(abc.begin() + m / f[i]);
			m %= f[i];
		}
	}
	return 0;
}