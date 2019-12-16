#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;

string s;
int cnt;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> s) {
		cnt = 0;
		for (char c : s) {
			if (c >= 'A' && c <= 'Z')
				cnt += c-'A'+1;
			else
				cnt += c-'a'+1;
		}
		cnt %= 17;
		if (cnt >= 13) cout << "SA\n";
		else if (cnt >= 10) cout << "A\n";
		else if (cnt >= 6) cout << "B\n";
		else if (cnt >= 3) cout << "C\n";
		else cout << "D\n";
	}
}