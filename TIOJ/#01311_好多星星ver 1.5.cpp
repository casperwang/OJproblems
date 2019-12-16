#include <bits/stdc++.h>
#define int long long
using namespace std;

int Z, X1, X2, Y1, Y2;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> Z) {
		if (!Z) return 0;
		cin >> X1 >> X2 >> Y1 >> Y2;
		for (int i = Y1; i <= Y2; i++) {
			for (int j = X1; j <= X2; j++) {
				if (__gcd(__gcd(i, j), Z) == 1)
					cout << '*';
				else
					cout << '.';
			}
			cout << '\n';
		}
		cout << "--\n";
	}
}