#include <bits/stdc++.h>
using namespace std;

int n, ans;
string s;

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s[2]==s[3]&&s[3]==s[4]&&s[4]==s[5]) ans += 2000;
		else if (s[2]==s[3]&&s[4]==s[5]) ans += 1500;
		else if ((s[2]==s[3]||s[4]==s[5])&&s[3]==s[4]) ans += 1000;
	}
	cout << ans << '\n';
}