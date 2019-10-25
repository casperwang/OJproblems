#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
using namespace std;

int a, n, y;
int cnt;

int pw(int a, int k) {
	int cnt = 1, mul = 1;
	for (; cnt <= k; cnt <<= 1) {
		if (cnt & k) mul = (mul * a) % y;
		a = (a * a) % y;
	}
	return mul;
}

signed main() {
	Hina;
	while (cin >> a >> n >> y) {
		if (!a && !n && !y) return 0;
		cnt = 0;
		for (int i = (n==0); i < y; i++) {
			if (pw(i, n) == a) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}