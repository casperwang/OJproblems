#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
using namespace std;

int a, b, c;

int mul(int a, int b) {
	int tmp = 0, now = 1;
	for (; now <= b; now *= 2) {
		if (now & b) tmp = (tmp + a) % c;
		a = (a + a) % c;
	}
	return tmp;
}

signed main() {
	Hina;
	while (cin >> a >> b >> c) {
		cout << mul(a, b) << endl;
	}
	return 0;
}