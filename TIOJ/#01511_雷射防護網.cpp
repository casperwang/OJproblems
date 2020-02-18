#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int unsigned long long
using namespace std;

int n, k;
string s;
int a, r, o;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> s) {
		k = (n-3) / 2;
		r = n * (n-2) / 2 * (n%2==0);
		o = k * (k+1) / 2 * n;
		a = n * (n-1) / 2 * (n-2) / 3 - r - o;
		if (s[0] == 'R') cout << r << "\n";
		if (s[0] == 'O') cout << o << "\n";
		if (s[0] == 'A') cout << a << "\n";
		cin >> s;
	}

	return 0;
}