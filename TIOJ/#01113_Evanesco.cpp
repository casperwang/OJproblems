#include <bits/stdc++.h>
using namespace std;

string s;
bool tf;

void DFS(int now, int vis, string a) {
	vis |= (1<<now);
	a += s[now];
	if (a.length() == s.length()) {
		cout << a << '\n';
		return;
	}
	for (int i = 0; i < s.size(); i++) {
		if (!(vis & (1<<i))) DFS(i, vis, a);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> s) {
		if (tf) cout << '\n';
		else tf = 1;
		for (int i = 1; i < s.size(); i++) {
			for (int j = 1; j < s.size(); j++) {
				if (s[j] < s[j-1]) swap(s[j], s[j-1]);
			}
		}
		for (int i = 0; i < s.size(); i++) DFS(i, 0, "");
	}
	return 0;
}