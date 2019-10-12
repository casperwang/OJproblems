#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, a, b, c;

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (a > 0 && b > 0 && c > 0 &&
		(a*a + b*b == c*c
		|| b*b + c*c == a*a
		|| a*a + c*c == b*b))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}