#include <bits/stdc++.h>
using namespace std;

int n;
string ans[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

signed main() {
	while (cin >> n) {
		cout << ans[(n+4)%7] << '\n';
	}
}