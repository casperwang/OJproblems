#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define INF 1e9
using namespace std;

int n, m;
int tmp;
int  dp[(1<<20)+5];
int len[(1<<20)+5];
int lg2[(1<<20)+5];
int dis[20+5][20+5];
string s;

int lowbit(int a) {
	return a&-a;
}

signed main() {
	Hina;
	cin >> n >> m >> s;
	for (int i = 1; i < s.length(); i++) {
		dis[s[i]-'a'][s[i-1]-'a']++;
		dis[s[i-1]-'a'][s[i]-'a']++;
	}
	for (int i = 0, j = 1; i <= 20; i++, j <<= 1) lg2[j] = i;
	for (int i = 1; i < (1<<m); i++) {
		dp[i] = INF;
		len[i] = len[i-lowbit(i)]+1;
		for (int j = 1; j <= (1<<m); j <<= 1) {
			if (!(i&j)) continue;
			tmp = 0;
			for (int k = 1; k <= (1<<m); k <<= 1) {
				if (j==k) continue;
				if (i&k) tmp += dis[lg2[j]][lg2[k]];
				else tmp -= dis[lg2[j]][lg2[k]];
			}
			dp[i] = min(dp[i], dp[i^j]+tmp*len[i]);
		}
		//cout << dp[i] << endl;
	}
	cout << dp[(1<<m)-1] << "\n";
	return 0;
}