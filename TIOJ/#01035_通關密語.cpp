#include <bits/stdc++.h>
#define MAXN 50000
using namespace std;

int sum1, sum2, ans, len;
char s1[MAXN+5], s2[MAXN+5];

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> s1 >> s2;
	for (int i = 0; i < MAXN; i++) {
		if (s1[i]==0) break;
		len++;
	}
	for (int i = 0; i < len; i++) {
		if (len-i <= ans) break;
		sum1 = sum2 = 0;
		for (int j = i; j < len && sum1 + len-j > ans; j++) {
			if (s1[j] == s2[j-i]) sum1++;
		}
		for (int j = i; j < len && sum2 + len-j > ans; j++) {
			if (s1[j-i] == s2[j]) sum2++;
		}
		ans = sum1 > ans ? sum1 : ans;
		ans = sum2 > ans ? sum2 : ans;
	}
	cout << ans << '\n';
	return 0;
}