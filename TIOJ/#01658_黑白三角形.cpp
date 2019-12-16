#include <bits/stdc++.h>
using namespace std;

int a, b;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> a >> b) {
		for (int i = 1; i <= a; i++) {
			for (int j = a-i; j > 0; j--) cout << " ";
			cout << "*";
			for (int j = 0; j < i*2-3; j++)
				if (b || i == a) cout << "*";
				else cout << " ";
			if (i > 1) cout << "*";
			cout << '\n';
		}
	}
}