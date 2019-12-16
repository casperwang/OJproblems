#include <bits/stdc++.h>
using namespace std;

short a, b, c;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> a >> b >> c) {
		if (a+b+c - max({a,b,c}) == max({a,b,c}))
			cout << "Good Pair\n";
		else 
			cout << "Not Good Pair\n";
	}
}