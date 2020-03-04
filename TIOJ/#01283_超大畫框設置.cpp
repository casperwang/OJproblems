#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
#define ppi pair<pii,int>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

const int MAXN = 100000;
const int INF = 3e18;
int n, m, ans;
int U[MAXN+5], D[MAXN+5];
int L[MAXN+5], R[MAXN+5];
stack <ppi> arr;
ppi tmp;

int rec(int i, int j) {
	return (D[j]-U[i])*(R[i]-L[j]);
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n, n /= 2;
	for (int i = 1; i <= n; i++) {
		cin >> R[i] >> U[i+1];
		R[i] += R[i-1];
		U[i+1] += U[i];
	}
	cin >> m, m /= 2;
	for (int i = 1; i <= m; i++) {
		cin >> D[i] >> L[i+1];
		D[i] += D[i-1];
		L[i+1] += L[i];
	}
	arr.push(ppi(pii(1, m), 1));
	for (int i = 2; i <= n; i++) {
		tmp = arr.top();
		while (arr.size() && rec(i, tmp.ff.ff) >= rec(tmp.ss, tmp.ff.ff)) {
			arr.pop();
			if (arr.size())
				tmp = arr.top();
		}
		if (!arr.size()) {
			arr.push(ppi(pii(1, m), i));
			continue;
		}
		int l = tmp.ff.ff+1, r = tmp.ff.ss+1;
		int id = tmp.ss, mid;
		while (l < r) {
			mid = (l+r)>>1;
			if (rec(i, mid) >= rec(id, mid))
				r = mid;
			else
				l = mid+1;
		}
		arr.pop(), arr.push(ppi(pii(tmp.ff.ff, l-1), id));
		if (l <= m) arr.push(ppi(pii(l, m), i));
	}
	while (arr.size()) {
		tmp = arr.top(), arr.pop();
		for (int i = tmp.ff.ff; i <= tmp.ff.ss; i++) {
			ans = max(ans, rec(tmp.ss, i));
		}
	}
	cout << ans << "\n";
}