#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
#define pb push_back
using namespace std;

int t;
int R, G, B, Y, P;
string s;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		R = G = B = Y = P = 0;
		for (int i = 0; i < 12; i++) {
			cin >> s;
			for (int j = 0; j < s.size(); j++) {
				if (s[j] == 'R') R = 1;
				if (s[j] == 'G') G = 1;
				if (s[j] == 'B') B = 1;
				if (s[j] == 'Y') Y = 1;
				if (s[j] == 'P') P = 1;
			}
		}
		cout << R+G+B+Y+P << "\n";
	}
 	return 0;
}