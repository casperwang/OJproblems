#include <bits/stdc++.h>
#define int long long
using namespace std;

string n, tmp;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		tmp = "";
		for (int i = 1; i < n.size(); i++) tmp += '0';
		tmp += '5';
		if (n < tmp && n[n.size()-1] == '0') return 0;
		if (n[n.size()-1]%2) cout << "LOSE ";
		else cout << "WIN ";
		if (n >= tmp) {
			if (n[n.size()-1]%2) cout << "LOSE\n";
			else cout << "WIN\n";
		} else {
			if (n[n.size()-1] == '2') cout << "LOSE\n";
			else cout << "WIN\n";
		}
	}
}