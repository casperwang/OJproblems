#include <bits/stdc++.h>
using namespace std;

string s;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == 'd' || s[i] == 'g' || s[i] == 't')
			cout << 1;
		else
			cout << 0;
	cout << '\n';
}