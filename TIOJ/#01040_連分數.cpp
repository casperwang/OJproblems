#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
using namespace std;

int a, b, n;

void GCD(int a, int b, int k) {
	if (a%b != 0) {
		cout << a/b << "+1/";
		if (b % (a%b) != 0) cout << "{", GCD(b, a%b, k+1);
		else GCD(b, a%b, k);
	} else {
		cout << a/b;
		while (k--) cout << "}";
		return;
	}
	return;
}

signed main() {
	Hina;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cout << a << "/" << b << " = ";
		GCD(a, b, 0);
		cout << endl;
	}
	return 0;
}