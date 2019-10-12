#include <bits/stdc++.h>
#define MAXN 300000
#define ff first
#define ss second
#define pb push_back
#define int long long
using namespace std;

int n, m, k, a, b;
int mmax, mmin;
int dsu[MAXN+5];
pair <int, pair<int, int> > path[MAXN+5];

int finding(int a) {
	if (dsu[a] != a) dsu[a] = finding(dsu[a]);
	return dsu[a];
}

signed main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> path[i].ss.ff >> path[i].ss.ss >> path[i].ff;
	}
	sort(path, path+m);
	for (int i = 1; i <= n; i++) dsu[i] = i;
	for (int i = 0; i < m; i++) {
		if (finding(path[i].ss.ff) != finding(path[i].ss.ss)) {
			mmin += path[i].ff;
			dsu[finding(path[i].ss.ff)] = finding(path[i].ss.ss);
		}
	}
	for (int i = 1; i <= n; i++) dsu[i] = i;
	for (int i = m-1; i >= 0; i--) {
		if (finding(path[i].ss.ff) != finding(path[i].ss.ss)) {
			mmax += path[i].ff;
			dsu[finding(path[i].ss.ff)] = finding(path[i].ss.ss);
		}
	}
	if (k >= mmin && k <= mmax) {
		cout << "TAK" << endl;
	} else {
		cout << "NIE" << endl;
	}
	return 0;
}