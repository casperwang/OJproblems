#include <bits/stdc++.h>
#define MAXN 300000
#define int long long
using namespace std;

int len, ans, k;
string s;

signed main() {
	cin >> len >> s;
	for (int i = 0; i < len; i++) {
		if (i && s[i] != s[i-1]) {
			ans += i-k-1;
			k = i;
			ans++;
		} else if (i) {
			if (k) ans++;
		}
	}
	cout << len*(len-1)/2-ans << endl;
	return 0;
}