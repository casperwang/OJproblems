#include <bits/stdc++.h>
using namespace std;

int t;
string a, b;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << (b.size()==a.size())*(a < b)+(a.size()<b.size()) << '\n';
	}
}
