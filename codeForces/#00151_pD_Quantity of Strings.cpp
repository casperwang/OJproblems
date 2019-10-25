#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
#define int long long
#define MOD 1000000007
#define MAXN 2000
using namespace std;
 
int n, m, k, cnt;
int dsu[MAXN+5];
map <int,int> appr;

int pw(int a, int n) {
	int b = 1, tmp = 1;
	for (; b <= n; b <<= 1) {
		if (b & n) tmp = (tmp * a) % MOD;
		a = (a * a) % MOD;
	}
	return tmp;
}

int finding(int now) {
	if (dsu[now] != now) dsu[now] = finding(dsu[now]);
	return dsu[now];
}
 
signed main() {
	Hina;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		dsu[i] = i;
	}
	for (int i = 1; i <= n-k+1; i++) {
		for (int j = 0; j < k/2; j++) {
			dsu[finding(dsu[i+j])] = finding(dsu[i+k-1-j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		appr[finding(dsu[i])] = 1;
	}
	for (auto i : appr) cnt++;
	cout << pw(m, cnt) << endl;
	return 0;
}